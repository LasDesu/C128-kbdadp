EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PS/2 to C128 keyboard adapter"
Date "2020-05-31"
Rev ""
Comp "Alexander Molodtsov"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L mylib:CONN-25 X1
U 1 1 5ABA2896
P 8700 1300
F 0 "X1" H 8900 1450 60  0000 C CNN
F 1 "CONN-25" H 9400 1450 50  0001 C CNN
F 2 "Connectors_DSub:DSUB-25_Male_Horizontal_Pitch2.77x2.84mm_EdgePinOffset4.94mm_Housed_MountingHolesOffset7.48mm" H 8900 1050 60  0001 C CNN
F 3 "" H 8900 1050 60  0000 C CNN
	1    8700 1300
	1    0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR03
U 1 1 5AD7341E
P 8500 1400
F 0 "#PWR03" H 8500 1400 30  0001 C CNN
F 1 "GND" H 8500 1330 30  0001 C CNN
F 2 "" H 8500 1400 60  0000 C CNN
F 3 "" H 8500 1400 60  0000 C CNN
	1    8500 1400
	1    0    0    -1  
$EndComp
NoConn ~ 8700 1500
Text Label 8300 3500 0    60   ~ 0
ROW0
Text Label 8300 3300 0    60   ~ 0
ROW1
Text Label 8300 3100 0    60   ~ 0
ROW2
Text Label 8300 2100 0    60   ~ 0
ROW3
Text Label 8300 2700 0    60   ~ 0
ROW4
Text Label 8300 2500 0    60   ~ 0
ROW5
Text Label 8300 2300 0    60   ~ 0
ROW6
Text Label 8300 2900 0    60   ~ 0
ROW7
Text Label 8300 1700 0    60   ~ 0
RSTR
Text Label 8300 6100 0    60   ~ 0
CAPS
Text Label 8300 5900 0    60   ~ 0
40/80
Text Label 8300 3700 0    60   ~ 0
COL0
Text Label 8300 4900 0    60   ~ 0
COL1
Text Label 8300 4700 0    60   ~ 0
COL2
Text Label 8300 4500 0    60   ~ 0
COL3
Text Label 8300 4300 0    60   ~ 0
COL4
Text Label 8300 4100 0    60   ~ 0
COL5
Text Label 8300 3900 0    60   ~ 0
COL6
Text Label 8300 5100 0    60   ~ 0
COL7
Text Label 8300 5300 0    60   ~ 0
K0
Text Label 8300 5500 0    60   ~ 0
K1
Text Label 8300 5700 0    60   ~ 0
K2
$Comp
L mylib:STM32F103C8 DD1
U 1 1 5AE648C3
P 4300 1800
F 0 "DD1" H 5050 1950 60  0000 C CNN
F 1 "STM32F103C8" H 5050 -1050 50  0000 C CNN
F 2 "Housings_QFP:LQFP-48_7x7mm_Pitch0.5mm" H 5500 1350 60  0001 C CNN
F 3 "" H 5500 1350 60  0000 C CNN
	1    4300 1800
	1    0    0    -1  
$EndComp
Text Label 6200 1800 2    60   ~ 0
ROW0
Text Label 6200 1900 2    60   ~ 0
ROW1
Text Label 6200 2000 2    60   ~ 0
ROW2
Text Label 6200 2500 2    60   ~ 0
ROW3
Text Label 6200 2200 2    60   ~ 0
ROW4
Text Label 6200 2300 2    60   ~ 0
ROW5
Text Label 6200 2400 2    60   ~ 0
ROW6
Text Label 6200 2100 2    60   ~ 0
ROW7
NoConn ~ 5800 2600
NoConn ~ 5800 3300
Text Label 3900 3000 0    60   ~ 0
COL0
Text Label 3900 3100 0    60   ~ 0
COL1
Text Label 3900 3200 0    60   ~ 0
COL2
Text Label 3900 3300 0    60   ~ 0
COL3
Text Label 3900 3400 0    60   ~ 0
COL4
Text Label 3900 3500 0    60   ~ 0
COL5
Text Label 3900 3600 0    60   ~ 0
COL6
Text Label 3900 2600 0    60   ~ 0
COL7
Text Label 3900 2700 0    60   ~ 0
K0
Text Label 3900 2800 0    60   ~ 0
K1
Text Label 3900 2900 0    60   ~ 0
K2
Text Label 3900 2200 0    60   ~ 0
40/80
Text Label 3900 2100 0    60   ~ 0
CAPS
Text Label 3900 2300 0    60   ~ 0
RSTR
$Comp
L mylib:LED VD1
U 1 1 5AE64ECF
P 3400 3200
F 0 "VD1" H 3400 3400 50  0000 C CNN
F 1 "LED" H 3400 3100 50  0001 C CNN
F 2 "LEDs:LED_D3.0mm" H 3400 3150 60  0001 C CNN
F 3 "" H 3400 3150 60  0000 C CNN
	1    3400 3200
	0    -1   1    0   
$EndComp
$Comp
L mylib:LED VD2
U 1 1 5AE64F45
P 3700 3200
F 0 "VD2" H 3700 3400 50  0000 C CNN
F 1 "LED" H 3700 3100 50  0001 C CNN
F 2 "LEDs:LED_D3.0mm" H 3700 3150 60  0001 C CNN
F 3 "" H 3700 3150 60  0000 C CNN
	1    3700 3200
	0    -1   1    0   
$EndComp
$Comp
L mylib:RES R3
U 1 1 5AE64F67
P 3400 2800
F 0 "R3" H 3400 2900 50  0000 C CNN
F 1 "1K*" H 3400 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3400 2750 60  0001 C CNN
F 3 "" H 3400 2750 60  0000 C CNN
	1    3400 2800
	0    -1   -1   0   
$EndComp
$Comp
L mylib:RES R4
U 1 1 5AE64FAF
P 3700 2800
F 0 "R4" H 3700 2900 50  0000 C CNN
F 1 "1K*" H 3700 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3700 2750 60  0001 C CNN
F 3 "" H 3700 2750 60  0000 C CNN
	1    3700 2800
	0    -1   -1   0   
$EndComp
$Comp
L mylib:GND #PWR015
U 1 1 5AE650B7
P 3700 3400
F 0 "#PWR015" H 3700 3400 30  0001 C CNN
F 1 "GND" H 3700 3330 30  0001 C CNN
F 2 "" H 3700 3400 60  0000 C CNN
F 3 "" H 3700 3400 60  0000 C CNN
	1    3700 3400
	1    0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR014
U 1 1 5AE65115
P 3400 3400
F 0 "#PWR014" H 3400 3400 30  0001 C CNN
F 1 "GND" H 3400 3330 30  0001 C CNN
F 2 "" H 3400 3400 60  0000 C CNN
F 3 "" H 3400 3400 60  0000 C CNN
	1    3400 3400
	1    0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR019
U 1 1 5AE651FE
P 5900 4700
F 0 "#PWR019" H 5900 4700 30  0001 C CNN
F 1 "GND" H 5900 4630 30  0001 C CNN
F 2 "" H 5900 4700 60  0000 C CNN
F 3 "" H 5900 4700 60  0000 C CNN
	1    5900 4700
	1    0    0    -1  
$EndComp
NoConn ~ 4300 4000
$Comp
L mylib:VCC #PWR017
U 1 1 5AE65694
P 5900 3600
F 0 "#PWR017" H 5900 3600 30  0001 C CNN
F 1 "VCC" H 5900 3700 40  0000 C CNN
F 2 "" H 5900 3600 60  0000 C CNN
F 3 "" H 5900 3600 60  0000 C CNN
	1    5900 3600
	1    0    0    -1  
$EndComp
NoConn ~ 4300 4500
$Comp
L mylib:CONN-6S X4
U 1 1 5AE65BA4
P 2200 3000
F 0 "X4" H 2500 3150 60  0000 C CNN
F 1 "CONN-6S" H 3000 3150 50  0001 C CNN
F 2 "MyLib:Mini_din6" H 2500 2750 60  0001 C CNN
F 3 "" H 2500 2750 60  0000 C CNN
	1    2200 3000
	-1   0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR018
U 1 1 5AE65C07
P 2300 4400
F 0 "#PWR018" H 2300 4400 30  0001 C CNN
F 1 "GND" H 2300 4330 30  0001 C CNN
F 2 "" H 2300 4400 60  0000 C CNN
F 3 "" H 2300 4400 60  0000 C CNN
	1    2300 4400
	1    0    0    -1  
$EndComp
$Comp
L mylib:RES R5
U 1 1 5AE65DE2
P 2700 3400
F 0 "R5" H 2700 3500 50  0000 C CNN
F 1 "4.7K" H 2700 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 2700 3350 60  0001 C CNN
F 3 "" H 2700 3350 60  0000 C CNN
	1    2700 3400
	0    -1   -1   0   
$EndComp
$Comp
L mylib:RES R6
U 1 1 5AE65E3A
P 3000 3400
F 0 "R6" H 3000 3500 50  0000 C CNN
F 1 "4.7K" H 3000 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3000 3350 60  0001 C CNN
F 3 "" H 3000 3350 60  0000 C CNN
	1    3000 3400
	0    -1   -1   0   
$EndComp
$Comp
L c128kbd-rescue:+5V #PWR012
U 1 1 5AE65F5D
P 2700 3100
F 0 "#PWR012" H 2700 2950 50  0001 C CNN
F 1 "+5V" H 2700 3240 50  0000 C CNN
F 2 "" H 2700 3100 50  0001 C CNN
F 3 "" H 2700 3100 50  0001 C CNN
	1    2700 3100
	1    0    0    -1  
$EndComp
$Comp
L c128kbd-rescue:+5V #PWR013
U 1 1 5AE65F93
P 3000 3100
F 0 "#PWR013" H 3000 2950 50  0001 C CNN
F 1 "+5V" H 3000 3240 50  0000 C CNN
F 2 "" H 3000 3100 50  0001 C CNN
F 3 "" H 3000 3100 50  0001 C CNN
	1    3000 3100
	1    0    0    -1  
$EndComp
$Comp
L c128kbd-rescue:+5V #PWR011
U 1 1 5AE6608C
P 2400 2900
F 0 "#PWR011" H 2400 2750 50  0001 C CNN
F 1 "+5V" H 2400 3040 50  0000 C CNN
F 2 "" H 2400 2900 50  0001 C CNN
F 3 "" H 2400 2900 50  0001 C CNN
	1    2400 2900
	1    0    0    -1  
$EndComp
$Comp
L mylib:PIN P1
U 1 1 5AE660D3
P 1300 5700
F 0 "P1" H 1380 5700 40  0001 L CNN
F 1 "+5V" H 1300 5775 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 1300 5700 60  0001 C CNN
F 3 "" H 1300 5700 60  0000 C CNN
	1    1300 5700
	-1   0    0    -1  
$EndComp
$Comp
L mylib:PIN P2
U 1 1 5AE6614A
P 1300 6100
F 0 "P2" H 1380 6100 40  0001 L CNN
F 1 "GND" H 1300 6175 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 1300 6100 60  0001 C CNN
F 3 "" H 1300 6100 60  0000 C CNN
	1    1300 6100
	-1   0    0    -1  
$EndComp
$Comp
L c128kbd-rescue:+5V #PWR023
U 1 1 5AE661AE
P 1500 5600
F 0 "#PWR023" H 1500 5450 50  0001 C CNN
F 1 "+5V" H 1500 5740 50  0000 C CNN
F 2 "" H 1500 5600 50  0001 C CNN
F 3 "" H 1500 5600 50  0001 C CNN
	1    1500 5600
	1    0    0    -1  
$EndComp
Text Notes 1250 3050 0    60   ~ 0
Data
Text Notes 1250 3450 0    60   ~ 0
GND
Text Notes 1250 3650 0    60   ~ 0
VCC
Text Notes 1250 3850 0    60   ~ 0
Clock
NoConn ~ 2200 4000
NoConn ~ 2200 3200
$Comp
L mylib:JUMPER2 J2
U 1 1 5AF03E29
P 2900 1600
F 0 "J2" H 2900 1700 50  0000 C CNN
F 1 "JUMPER2" H 2900 1300 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3000 1550 60  0001 C CNN
F 3 "" H 3000 1550 60  0000 C CNN
	1    2900 1600
	-1   0    0    -1  
$EndComp
$Comp
L mylib:CAP C2
U 1 1 5AF03EEA
P 6300 4200
F 0 "C2" H 6300 4325 50  0000 C CNN
F 1 "0.1u" H 6300 4075 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6300 4150 60  0001 C CNN
F 3 "" H 6300 4150 60  0000 C CNN
	1    6300 4200
	0    -1   -1   0   
$EndComp
$Comp
L mylib:CAP C3
U 1 1 5AF03F3E
P 6700 4200
F 0 "C3" H 6700 4325 50  0000 C CNN
F 1 "0.1u" H 6700 4075 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6700 4150 60  0001 C CNN
F 3 "" H 6700 4150 60  0000 C CNN
	1    6700 4200
	0    -1   -1   0   
$EndComp
$Comp
L mylib:CAP C4
U 1 1 5AF03F80
P 7100 4200
F 0 "C4" H 7100 4325 50  0000 C CNN
F 1 "0.1u" H 7100 4075 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 7100 4150 60  0001 C CNN
F 3 "" H 7100 4150 60  0000 C CNN
	1    7100 4200
	0    -1   -1   0   
$EndComp
$Comp
L mylib:GND #PWR020
U 1 1 5AF04380
P 7100 4700
F 0 "#PWR020" H 7100 4700 30  0001 C CNN
F 1 "GND" H 7100 4630 30  0001 C CNN
F 2 "" H 7100 4700 60  0000 C CNN
F 3 "" H 7100 4700 60  0000 C CNN
	1    7100 4700
	1    0    0    -1  
$EndComp
NoConn ~ 5800 3100
NoConn ~ 5800 3200
$Comp
L mylib:SW_OFF SA1
U 1 1 5AF04AF8
P 2100 2200
F 0 "SA1" H 2100 2350 50  0000 C CNN
F 1 "SW_OFF" H 2100 2100 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 2100 2150 60  0001 C CNN
F 3 "" H 2100 2150 60  0000 C CNN
	1    2100 2200
	0    -1   -1   0   
$EndComp
$Comp
L mylib:GND #PWR08
U 1 1 5AF04BF7
P 2100 2600
F 0 "#PWR08" H 2100 2600 30  0001 C CNN
F 1 "GND" H 2100 2530 30  0001 C CNN
F 2 "" H 2100 2600 60  0000 C CNN
F 3 "" H 2100 2600 60  0000 C CNN
	1    2100 2600
	1    0    0    -1  
$EndComp
$Comp
L mylib:CAP C1
U 1 1 5AF04C27
P 2400 2200
F 0 "C1" H 2400 2325 50  0000 C CNN
F 1 "0.1u" H 2400 2075 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2400 2150 60  0001 C CNN
F 3 "" H 2400 2150 60  0000 C CNN
	1    2400 2200
	0    -1   -1   0   
$EndComp
$Comp
L mylib:RES R2
U 1 1 5AF04F86
P 3100 2200
F 0 "R2" H 3100 2300 50  0000 C CNN
F 1 "10K" H 3100 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3100 2150 60  0001 C CNN
F 3 "" H 3100 2150 60  0000 C CNN
	1    3100 2200
	0    -1   -1   0   
$EndComp
$Comp
L mylib:GND #PWR09
U 1 1 5AF050C0
P 3100 2600
F 0 "#PWR09" H 3100 2600 30  0001 C CNN
F 1 "GND" H 3100 2530 30  0001 C CNN
F 2 "" H 3100 2600 60  0000 C CNN
F 3 "" H 3100 2600 60  0000 C CNN
	1    3100 2600
	1    0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR07
U 1 1 5AF056BB
P 6800 2400
F 0 "#PWR07" H 6800 2400 30  0001 C CNN
F 1 "GND" H 6800 2330 30  0001 C CNN
F 2 "" H 6800 2400 60  0000 C CNN
F 3 "" H 6800 2400 60  0000 C CNN
	1    6800 2400
	1    0    0    -1  
$EndComp
Text Notes 7350 1850 0    60   ~ 0
TX
Text Notes 7350 2050 0    60   ~ 0
RX
Text Notes 7350 2250 0    60   ~ 0
GND
$Comp
L mylib:CAP C8
U 1 1 5AF05E59
P 2200 5900
F 0 "C8" H 2200 6025 50  0000 C CNN
F 1 "0.1u" H 2200 5775 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2200 5850 60  0001 C CNN
F 3 "" H 2200 5850 60  0000 C CNN
	1    2200 5900
	0    -1   -1   0   
$EndComp
$Comp
L mylib:CAPP C7
U 1 1 5AF05EF3
P 1800 5900
F 0 "C7" H 1800 6025 50  0000 C CNN
F 1 "47u 16V" H 1800 5775 50  0000 C CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D5.0mm_P2.50mm" H 1800 5850 60  0001 C CNN
F 3 "" H 1800 5850 60  0000 C CNN
	1    1800 5900
	0    -1   1    0   
$EndComp
$Comp
L mylib:CAP C10
U 1 1 5AF0615B
P 3600 5900
F 0 "C10" H 3600 6025 50  0000 C CNN
F 1 "0.1u" H 3600 5775 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3600 5850 60  0001 C CNN
F 3 "" H 3600 5850 60  0000 C CNN
	1    3600 5900
	0    -1   -1   0   
$EndComp
$Comp
L mylib:VCC #PWR024
U 1 1 5AF061AF
P 3600 5600
F 0 "#PWR024" H 3600 5600 30  0001 C CNN
F 1 "VCC" H 3600 5700 40  0000 C CNN
F 2 "" H 3600 5600 60  0000 C CNN
F 3 "" H 3600 5600 60  0000 C CNN
	1    3600 5600
	1    0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR025
U 1 1 5AF06A9A
P 3600 6200
F 0 "#PWR025" H 3600 6200 30  0001 C CNN
F 1 "GND" H 3600 6130 30  0001 C CNN
F 2 "" H 3600 6200 60  0000 C CNN
F 3 "" H 3600 6200 60  0000 C CNN
	1    3600 6200
	1    0    0    -1  
$EndComp
Text Notes 7000 3700 0    60   ~ 0
USB option\nmaybe?
Text Notes 7000 2400 0    60   ~ 0
UART
Text Notes 1200 4400 0    60   ~ 0
PS/2
Text Notes 8800 6300 0    60   ~ 0
C128
$Comp
L c128kbd-rescue:L78L33_TO92 DA1
U 1 1 5B053225
P 2700 5700
F 0 "DA1" H 2550 5825 50  0000 C CNN
F 1 "L78L33_TO92" H 2700 5825 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 2700 5925 50  0001 C CIN
F 3 "" H 2700 5650 50  0001 C CNN
	1    2700 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1400 8500 1300
Wire Wire Line
	8500 1300 8700 1300
Wire Wire Line
	8300 2100 8700 2100
Wire Wire Line
	8300 2300 8700 2300
Wire Wire Line
	8300 2500 8700 2500
Wire Wire Line
	8700 2700 8300 2700
Wire Wire Line
	8300 2900 8700 2900
Wire Wire Line
	8700 3100 8300 3100
Wire Wire Line
	8300 3300 8700 3300
Wire Wire Line
	8700 3500 8300 3500
Wire Wire Line
	8300 1700 8700 1700
Wire Wire Line
	8300 5900 8700 5900
Wire Wire Line
	8700 6100 8300 6100
Wire Wire Line
	8300 5700 8700 5700
Wire Wire Line
	8700 5500 8300 5500
Wire Wire Line
	8300 5300 8700 5300
Wire Wire Line
	8700 5100 8300 5100
Wire Wire Line
	8300 4900 8700 4900
Wire Wire Line
	8700 4700 8300 4700
Wire Wire Line
	8700 4300 8300 4300
Wire Wire Line
	8700 4500 8300 4500
Wire Wire Line
	8700 4100 8300 4100
Wire Wire Line
	8700 3900 8300 3900
Wire Wire Line
	8300 3700 8700 3700
Wire Wire Line
	6200 2500 5800 2500
Wire Wire Line
	5800 2400 6200 2400
Wire Wire Line
	6200 2300 5800 2300
Wire Wire Line
	5800 2200 6200 2200
Wire Wire Line
	6200 2100 5800 2100
Wire Wire Line
	5800 2000 6200 2000
Wire Wire Line
	6200 1900 5800 1900
Wire Wire Line
	5800 1800 6200 1800
Wire Wire Line
	3900 2200 4300 2200
Wire Wire Line
	4300 2100 3900 2100
Wire Wire Line
	3900 2600 4300 2600
Wire Wire Line
	4300 2700 3900 2700
Wire Wire Line
	3900 2800 4300 2800
Wire Wire Line
	4300 2900 3900 2900
Wire Wire Line
	3900 3000 4300 3000
Wire Wire Line
	3900 3100 4300 3100
Wire Wire Line
	3900 3200 4300 3200
Wire Wire Line
	3900 3300 4300 3300
Wire Wire Line
	4300 3400 3900 3400
Wire Wire Line
	4300 3500 3900 3500
Wire Wire Line
	4300 3600 3900 3600
Wire Wire Line
	3400 2400 3400 2600
Wire Wire Line
	3700 2500 3700 2600
Wire Wire Line
	3700 3400 3700 3300
Wire Wire Line
	3400 3400 3400 3300
Wire Wire Line
	3400 3100 3400 3000
Wire Wire Line
	3700 3100 3700 3000
Wire Wire Line
	5900 4200 5900 4300
Wire Wire Line
	5900 4300 5900 4400
Wire Wire Line
	5900 4400 5900 4500
Wire Wire Line
	5900 4500 5900 4700
Wire Wire Line
	5900 4200 5800 4200
Wire Wire Line
	5800 4300 5900 4300
Connection ~ 5900 4300
Wire Wire Line
	5800 4400 5900 4400
Connection ~ 5900 4400
Wire Wire Line
	5800 4500 5900 4500
Connection ~ 5900 4500
Wire Wire Line
	6500 2900 5800 2900
Wire Wire Line
	5900 3600 5900 3700
Wire Wire Line
	5900 3700 5900 3800
Wire Wire Line
	5900 3800 5900 3900
Wire Wire Line
	5900 3900 5900 4000
Wire Wire Line
	5900 4000 5800 4000
Wire Wire Line
	5800 3900 5900 3900
Connection ~ 5900 3900
Wire Wire Line
	5800 3800 5900 3800
Connection ~ 5900 3800
Wire Wire Line
	5800 3700 5900 3700
Wire Wire Line
	6300 4000 6700 4000
Wire Wire Line
	6700 4000 7100 4000
Connection ~ 5900 3700
Wire Wire Line
	3700 2500 4300 2500
Wire Wire Line
	3400 2400 4300 2400
Wire Wire Line
	2300 3400 2300 4200
Wire Wire Line
	2300 4200 2300 4400
Wire Wire Line
	2300 4200 2200 4200
Wire Wire Line
	3000 3600 3000 3800
Wire Wire Line
	3000 3800 4300 3800
Wire Wire Line
	2700 3900 4300 3900
Wire Wire Line
	2700 3900 2700 3600
Wire Wire Line
	3000 3100 3000 3200
Wire Wire Line
	2700 3100 2700 3200
Wire Wire Line
	1500 5600 1500 5700
Wire Wire Line
	1400 5700 1500 5700
Wire Wire Line
	1500 5700 1800 5700
Wire Wire Line
	1800 5700 2200 5700
Wire Wire Line
	2200 5700 2400 5700
Wire Wire Line
	2300 3400 2200 3400
Connection ~ 2300 4200
Wire Wire Line
	2200 3600 2400 3600
Wire Wire Line
	2400 3600 2400 2900
Wire Wire Line
	2500 3000 2200 3000
Connection ~ 3000 3800
Wire Wire Line
	7100 4000 7100 4100
Wire Wire Line
	6300 4100 6300 4000
Connection ~ 6300 4000
Wire Wire Line
	6700 4100 6700 4000
Connection ~ 6700 4000
Wire Wire Line
	6300 4300 6300 4400
Wire Wire Line
	6300 4400 6700 4400
Wire Wire Line
	6700 4400 7100 4400
Wire Wire Line
	7100 4300 7100 4400
Wire Wire Line
	7100 4400 7100 4700
Connection ~ 7100 4400
Wire Wire Line
	6700 4400 6700 4300
Connection ~ 6700 4400
Wire Wire Line
	2100 2000 2100 1900
Wire Wire Line
	2100 1900 2400 1900
Wire Wire Line
	2400 1900 4300 1900
Wire Wire Line
	2400 2300 2400 2500
Wire Wire Line
	2400 2500 2100 2500
Wire Wire Line
	2100 2400 2100 2500
Wire Wire Line
	2100 2500 2100 2600
Connection ~ 2100 2500
Wire Wire Line
	2400 2100 2400 1900
Connection ~ 2400 1900
Wire Wire Line
	3100 2000 3100 1800
Connection ~ 3100 1800
Wire Wire Line
	3100 2600 3100 2400
Wire Wire Line
	3000 1800 3100 1800
Wire Wire Line
	3100 1800 4300 1800
Wire Wire Line
	6800 2400 6800 2200
Wire Wire Line
	6800 2200 6900 2200
Wire Wire Line
	6500 2800 5800 2800
Wire Wire Line
	6400 2700 6400 1800
Wire Wire Line
	3600 5600 3600 5700
Wire Wire Line
	3600 5700 3600 5800
Connection ~ 3600 5700
Connection ~ 1500 5700
Wire Wire Line
	1800 5800 1800 5700
Connection ~ 1800 5700
Wire Wire Line
	2200 5800 2200 5700
Connection ~ 2200 5700
Wire Wire Line
	1400 6100 1800 6100
Wire Wire Line
	1800 6100 2200 6100
Wire Wire Line
	2200 6100 2700 6100
Wire Wire Line
	2700 6100 3200 6100
Wire Wire Line
	3600 6000 3600 6100
Wire Wire Line
	3600 6100 3600 6200
Wire Wire Line
	2700 6100 2700 6000
Connection ~ 2700 6100
Wire Wire Line
	2200 6000 2200 6100
Connection ~ 2200 6100
Wire Wire Line
	1800 6000 1800 6100
Connection ~ 1800 6100
Wire Wire Line
	3000 5700 3200 5700
Connection ~ 3600 6100
$Comp
L mylib:QUARTZ ZQ1
U 1 1 5B1EB46B
P 3700 4400
F 0 "ZQ1" H 3700 4525 50  0000 C CNN
F 1 "8MHz" H 3700 4275 50  0000 C CNN
F 2 "Crystals:Crystal_HC18-U_Vertical" H 3700 4350 60  0001 C CNN
F 3 "" H 3700 4350 60  0000 C CNN
	1    3700 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 4400 3400 4400
Wire Wire Line
	3400 4200 3400 4400
Wire Wire Line
	3400 4400 3400 4500
Wire Wire Line
	3400 4200 4300 4200
Wire Wire Line
	3800 4400 4000 4400
Wire Wire Line
	4000 4300 4000 4400
Wire Wire Line
	4000 4400 4000 4500
Wire Wire Line
	4000 4300 4300 4300
$Comp
L mylib:CAP C5
U 1 1 5B1EB651
P 3400 4600
F 0 "C5" H 3400 4725 50  0000 C CNN
F 1 "30p" H 3400 4475 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3400 4550 60  0001 C CNN
F 3 "" H 3400 4550 60  0000 C CNN
	1    3400 4600
	0    -1   -1   0   
$EndComp
$Comp
L mylib:CAP C6
U 1 1 5B1EB6BC
P 4000 4600
F 0 "C6" H 4000 4725 50  0000 C CNN
F 1 "30p" H 4000 4475 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 4000 4550 60  0001 C CNN
F 3 "" H 4000 4550 60  0000 C CNN
	1    4000 4600
	0    -1   -1   0   
$EndComp
Connection ~ 4000 4400
$Comp
L mylib:GND #PWR022
U 1 1 5B1EB7C4
P 4000 4800
F 0 "#PWR022" H 4000 4800 30  0001 C CNN
F 1 "GND" H 4000 4730 30  0001 C CNN
F 2 "" H 4000 4800 60  0000 C CNN
F 3 "" H 4000 4800 60  0000 C CNN
	1    4000 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 4800 4000 4700
$Comp
L mylib:GND #PWR021
U 1 1 5B1EB8D9
P 3400 4800
F 0 "#PWR021" H 3400 4800 30  0001 C CNN
F 1 "GND" H 3400 4730 30  0001 C CNN
F 2 "" H 3400 4800 60  0000 C CNN
F 3 "" H 3400 4800 60  0000 C CNN
	1    3400 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4800 3400 4700
Connection ~ 3400 4400
$Comp
L mylib:JUMPER2 J1
U 1 1 5B1EC9EE
P 2900 1100
F 0 "J1" H 2900 1200 50  0000 C CNN
F 1 "JUMPER2" H 2900 800 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3000 1050 60  0001 C CNN
F 3 "" H 3000 1050 60  0000 C CNN
	1    2900 1100
	-1   0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR02
U 1 1 5B1ECD3B
P 3100 1400
F 0 "#PWR02" H 3100 1400 30  0001 C CNN
F 1 "GND" H 3100 1330 30  0001 C CNN
F 2 "" H 3100 1400 60  0000 C CNN
F 3 "" H 3100 1400 60  0000 C CNN
	1    3100 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1400 3100 1300
Wire Wire Line
	3100 1300 3000 1300
Text Notes 2700 1300 1    60   ~ 0
BOOT1
Text Notes 2700 1800 1    60   ~ 0
BOOT0
Text Notes 1800 2000 0    60   ~ 0
RESET
Wire Notes Line
	3200 4100 4200 4100
Wire Notes Line
	4200 4100 4200 4900
Wire Notes Line
	4200 4900 3200 4900
Wire Notes Line
	3200 4900 3200 4100
Text Notes 3200 5100 0    60   ~ 0
Optional stable\nclock source
$Comp
L c128kbd-rescue:+5V #PWR06
U 1 1 5B320056
P 8600 1900
F 0 "#PWR06" H 8600 1750 50  0001 C CNN
F 1 "+5V" H 8600 2040 50  0000 C CNN
F 2 "" H 8600 1900 50  0001 C CNN
F 3 "" H 8600 1900 50  0001 C CNN
	1    8600 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8700 1900 8600 1900
Wire Wire Line
	3000 1100 3400 1100
Text Notes 5500 1600 0    50   ~ 0
These are not 5V tolerant\nit's output anyway
$Comp
L mylib:RES R1
U 1 1 5ED3FB37
P 3700 1100
F 0 "R1" H 3700 1200 50  0000 C CNN
F 1 "10K" H 3700 1000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3700 1050 60  0001 C CNN
F 3 "" H 3700 1050 60  0000 C CNN
	1    3700 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2300 4300 2300
$Comp
L mylib:VCC #PWR01
U 1 1 5ED4834E
P 4000 1100
F 0 "#PWR01" H 4000 1100 30  0001 C CNN
F 1 "VCC" H 4000 1200 40  0000 C CNN
F 2 "" H 4000 1100 60  0000 C CNN
F 3 "" H 4000 1100 60  0000 C CNN
	1    4000 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	4000 1100 3900 1100
Wire Wire Line
	5800 2700 6400 2700
Wire Wire Line
	6400 1800 6900 1800
Wire Wire Line
	6500 2800 6500 2000
Wire Wire Line
	6500 2000 6900 2000
$Comp
L mylib:CONN-4 X3
U 1 1 5EDD3415
P 6900 2800
F 0 "X3" H 7100 2950 60  0000 C CNN
F 1 "CONN-4" H 7600 2950 50  0001 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 7100 2550 60  0001 C CNN
F 3 "" H 7100 2550 60  0000 C CNN
	1    6900 2800
	1    0    0    -1  
$EndComp
$Comp
L mylib:GND #PWR016
U 1 1 5EDD38CF
P 6800 3500
F 0 "#PWR016" H 6800 3500 30  0001 C CNN
F 1 "GND" H 6800 3430 30  0001 C CNN
F 2 "" H 6800 3500 60  0000 C CNN
F 3 "" H 6800 3500 60  0000 C CNN
	1    6800 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3500 6800 3400
Wire Wire Line
	6800 3400 6900 3400
Wire Wire Line
	6800 2800 6900 2800
Wire Wire Line
	5800 3000 6900 3000
Wire Wire Line
	6500 3200 6900 3200
Wire Wire Line
	6500 2900 6500 3200
Wire Wire Line
	5900 4000 6300 4000
Connection ~ 5900 4000
Text Notes 7350 2850 0    50   ~ 0
5V
Text Notes 7350 3050 0    50   ~ 0
D-
Text Notes 7350 3250 0    50   ~ 0
D+
Text Notes 7350 3450 0    50   ~ 0
GND
Wire Wire Line
	3500 1100 3400 1100
Wire Wire Line
	3400 1100 3400 2300
Connection ~ 3400 1100
Wire Wire Line
	3100 1600 3000 1600
$Comp
L mylib:VCC #PWR04
U 1 1 5AF04934
P 3100 1600
F 0 "#PWR04" H 3100 1600 30  0001 C CNN
F 1 "VCC" H 3100 1700 40  0000 C CNN
F 2 "" H 3100 1600 60  0000 C CNN
F 3 "" H 3100 1600 60  0000 C CNN
	1    3100 1600
	0    1    1    0   
$EndComp
$Comp
L mylib:CONN-4 X2
U 1 1 5EED886F
P 6900 1600
F 0 "X2" H 7100 1750 60  0000 C CNN
F 1 "CONN-4" H 7600 1750 50  0001 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 7100 1350 60  0001 C CNN
F 3 "" H 7100 1350 60  0000 C CNN
	1    6900 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1600 6900 1600
Text Notes 7350 1650 0    50   ~ 0
5V
$Comp
L c128kbd-rescue:+5V #PWR010
U 1 1 5EF006C4
P 6800 2800
F 0 "#PWR010" H 6800 2650 50  0001 C CNN
F 1 "+5V" H 6800 2940 50  0000 C CNN
F 2 "" H 6800 2800 50  0001 C CNN
F 3 "" H 6800 2800 50  0001 C CNN
	1    6800 2800
	0    -1   -1   0   
$EndComp
$Comp
L c128kbd-rescue:+5V #PWR05
U 1 1 5EF00E7C
P 6800 1600
F 0 "#PWR05" H 6800 1450 50  0001 C CNN
F 1 "+5V" H 6800 1740 50  0000 C CNN
F 2 "" H 6800 1600 50  0001 C CNN
F 3 "" H 6800 1600 50  0001 C CNN
	1    6800 1600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 3800 3000 3800
Wire Wire Line
	2500 3000 2500 3900
Wire Wire Line
	2500 3900 2700 3900
Connection ~ 2700 3900
$Comp
L mylib:CAPP C9
U 1 1 5EFEB351
P 3200 5900
F 0 "C9" H 3200 6025 50  0000 C CNN
F 1 "47u 10V" H 3200 5775 50  0000 C CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D5.0mm_P2.50mm" H 3200 5850 60  0001 C CNN
F 3 "" H 3200 5850 60  0000 C CNN
	1    3200 5900
	0    -1   1    0   
$EndComp
Wire Wire Line
	3200 5800 3200 5700
Connection ~ 3200 5700
Wire Wire Line
	3200 5700 3600 5700
Wire Wire Line
	3200 6000 3200 6100
Connection ~ 3200 6100
Wire Wire Line
	3200 6100 3600 6100
$EndSCHEMATC
