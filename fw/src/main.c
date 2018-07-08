/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <string.h>

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_exti.h"

#include "timer.h"
#include "kbd_iface.h"

#define KBD_COLS 11
#define KBD_MSIZE (1 << KBD_COLS)
#define KBD_MASK (KBD_MSIZE - 1)

static volatile uint8_t kbdmtx[KBD_MSIZE];
//static uint16_t kbd_addr = 0x7FF;
#define KBD_IADDR(a) kbdmtx[KBD_MASK - (a)]

static inline void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	if ( (GPIOx->ODR & GPIO_Pin) != (uint32_t)Bit_RESET )
	{
		GPIOx->BRR = GPIO_Pin;
	}
	else
	{
		GPIOx->BSRR = GPIO_Pin;
	}
}

static inline void keyboard_update()
{
	//kbd_addr = GPIO_ReadInputData( GPIOE ) >> KBD_GPIO_OFF;
	//GPIO_Write( GPIOF, kbd_addr );
	uint16_t kbd_addr = GPIOB->IDR;
	kbd_addr >>= KBD_GPIO_OFF;
	GPIOA->ODR = kbdmtx[kbd_addr];
}

void key_press( unsigned col, uint8_t mask )
{
	unsigned i;
	col = 1 << col;

	KBD_IADDR(col) &= ~mask;
	keyboard_update();

	i = col + 1;
	while ( i < KBD_MSIZE )
	{
		if ( (i & col) == 0 )
		{
			i |= col;
			continue;
		}

		KBD_IADDR(i) &= ~mask;
		i ++;
	}

	keyboard_update();
}

void key_release( unsigned col, uint8_t mask )
{
	unsigned i, j;
	col = 1 << col;

	KBD_IADDR(col) |= mask;
	keyboard_update();

	i = col + 1;
	while ( i < KBD_MSIZE )
	{
		uint8_t newval = 0xFF;

		if ( (i & col) == 0 )
		{
			i |= col;
			continue;
		}

		for ( j = (1 << (KBD_COLS - 1)); j; j >>= 1 )
		{
			if ( (j & i) == 0 )
				continue;
			newval &= KBD_IADDR(j);
		}

		KBD_IADDR(i) = newval;
		i ++;
	}

	keyboard_update();
}

static inline void keyboard_irq_handler()
{
	uint32_t flags;

	flags = EXTI->PR;
	keyboard_update();

	//EXTI_ClearITPendingBit( flags & (KBD_MASK << KBD_GPIO_OFF) );
	EXTI->PR = flags & (0x7FF << KBD_GPIO_OFF);

	GPIO_ToggleBits( GPIOB, GPIO_Pin_3 );
}

void EXTI9_5_IRQHandler(void)
{
	keyboard_irq_handler();
}

void EXTI15_10_IRQHandler(void)
{
	keyboard_irq_handler();
}

void key_caps_set( int state )
{
	GPIO_WriteBit( GPIOB, GPIO_Pin_0, state ? Bit_RESET : Bit_SET );
}

void key_4080_set( int state )
{
	GPIO_WriteBit( GPIOB, GPIO_Pin_1, state ? Bit_RESET : Bit_SET );
}

void key_restore_set( int state )
{
	GPIO_WriteBit( GPIOB, GPIO_Pin_2, state ? Bit_RESET : Bit_SET );
}

#define PS2_PORT		GPIOC
#define PS2_DATA_PIN	GPIO_Pin_13
#define PS2_CLK_PIN		GPIO_Pin_14

void ps2_clock_out()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit( &GPIO_InitStructure );

	GPIO_SetBits( PS2_PORT, PS2_CLK_PIN );

	GPIO_InitStructure.GPIO_Pin = PS2_CLK_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( PS2_PORT, &GPIO_InitStructure );
}

void ps2_clock_in()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit( &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = PS2_CLK_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( PS2_PORT, &GPIO_InitStructure );
}

void ps2_data_out()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit( &GPIO_InitStructure );

	GPIO_SetBits( PS2_PORT, PS2_DATA_PIN );

	GPIO_InitStructure.GPIO_Pin = PS2_DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( PS2_PORT, &GPIO_InitStructure );
}

void ps2_data_in()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit( &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = PS2_DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( PS2_PORT, &GPIO_InitStructure );
}

void ps2_clock_set( unsigned state )
{
	GPIO_WriteBit( PS2_PORT, PS2_CLK_PIN, state ? Bit_SET : Bit_RESET );
}

unsigned ps2_clock_get()
{
	return GPIO_ReadInputDataBit(PS2_PORT, PS2_CLK_PIN) != Bit_RESET ? 1 : 0;
}

void ps2_data_set( unsigned state )
{
	GPIO_WriteBit( PS2_PORT, PS2_DATA_PIN, state ? Bit_SET : Bit_RESET );
}

unsigned ps2_data_get()
{
	return GPIO_ReadInputDataBit(PS2_PORT, PS2_DATA_PIN) != Bit_RESET ? 1 : 0;
}

void dbg_kbd_led_set( unsigned state )
{
	GPIO_WriteBit( GPIOB, GPIO_Pin_4, state ? Bit_SET : Bit_RESET );
}

static void init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;

	/* setup ports clocks */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE );
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE );
	GPIO_PinRemapConfig( GPIO_Remap_SWJ_Disable, ENABLE );

	/* address lines */
	GPIO_StructInit( &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = KBD_MASK << KBD_GPIO_OFF;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOB, &GPIO_InitStructure );

	/* data lines */
	GPIO_StructInit( &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = 0xFF;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init( GPIOA, &GPIO_InitStructure );
	GPIO_SetBits( GPIOA, 0xFF );

	/* extended keys */
	GPIO_StructInit( &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init( GPIOB, &GPIO_InitStructure );
	GPIO_SetBits( GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 );

	/* leds */
	GPIO_StructInit( &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init( GPIOB, &GPIO_InitStructure );
	GPIO_SetBits( GPIOB, GPIO_Pin_3 | GPIO_Pin_4 );

	ps2_clock_in();
	ps2_data_in();

	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource5 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource6 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource7 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource8 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource9 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource10 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource11 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource12 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource13 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource14 );
	GPIO_EXTILineConfig( GPIO_PortSourceGPIOB, GPIO_PinSource15 );

	/* Connect port E to EXTI lines */
	EXTI_InitStruct.EXTI_Line = \
		EXTI_Line5 | EXTI_Line6 | EXTI_Line7 | EXTI_Line8 | EXTI_Line9 | EXTI_Line10 | \
		EXTI_Line11 | EXTI_Line12 | EXTI_Line13 | EXTI_Line14 | EXTI_Line15;
	/* Enable interrupt */
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	/* Interrupt mode */
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	/* Triggers on rising and falling edge */
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	/* Add to EXTI */
	EXTI_Init( &EXTI_InitStruct );

	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init( &NVIC_InitStruct );

	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init( &NVIC_InitStruct );

	timer_init();
}

static void set_system_clock()
{
	RCC_DeInit();

	// Включаем внутренний RC генератор.
	RCC_HSICmd( ENABLE );
	// Выбираем источником такторования внутренний RC генератор.
	RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);

	/* HCLK = SYSCLK */ /* Смотри на схеме AHB Prescaler. Частота не делится (RCC_SYSCLK_Div1) */
	RCC_HCLKConfig( RCC_SYSCLK_Div1 );

	/* PCLK2 = HCLK */ /* Смотри на схеме APB2 Prescaler. Частота не делится (RCC_HCLK_Div1)  */
	RCC_PCLK2Config( RCC_HCLK_Div1 );

	/* PCLK1 = HCLK/2 */ /* Смотри на схеме APB1 Prescaler. Частота делится на 2 (RCC_HCLK_Div2)
	потому что на выходе APB1 должно быть не более 36МГц (смотри схему) */
	RCC_PCLK1Config( RCC_HCLK_Div2 );

	// Выключаем умножитель частоты.
	RCC_PLLCmd( DISABLE );

	RCC_PLLConfig( RCC_CFGR_PLLSRC_HSI_Div2, RCC_CFGR_PLLMULL13 );

	RCC_PLLCmd( ENABLE ); // Включаем умножитель частоты.

	/* Ждем пока PLL будет готов */
	while ( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET )
		{ }

	/* Переключаем системное тактирование на PLL */
	RCC_SYSCLKConfig( RCC_SYSCLKSource_PLLCLK );

	/* Ждем пока переключиться */
	while ( RCC_GetSYSCLKSource() != 0x08 )
		{ }

	SystemCoreClockUpdate(); // Вычисление тактовой частоты ядра.
}

int main(void)
{
	memset( kbdmtx, ~0, sizeof(kbdmtx) );

	set_system_clock();

	init();
	keyboard_update();

	while ( 1 )
	{
		kbd_loop();
	}
}
