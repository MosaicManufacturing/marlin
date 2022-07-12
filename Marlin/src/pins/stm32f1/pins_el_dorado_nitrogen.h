/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

//! Might want to use prusa/mk3 configuration.h and adv instead because its more sim. to rambo board
//!https://github.com/MarlinFirmware/Configurations/blob/release-2.0.8/config/examples/Prusa/MK3/Configuration.h

#define BOARD_CUSTOM_BUILD_FLAGS -DTONE_CHANNEL=4 -DTONE_TIMER=4

/* EEPROM PINS
#define SPI_EEPROM
#define MARLIN_EEPROM_SIZE 0x40000 
#define SPI_CHAN_EEPROM1      1
#define SPI_EEPROM1_CS       PD7 // EEPROM_CS_S
#define EEPROM_MISO          PB4  // EEPROM_MISO
#define EEPROM_MOSI          PB5  // EEPROM_MOSI
#define EEPROM_CLK           PB3 // EEPROM_CLK_S
//#define            PB3  // EEPROM_CLK
#define EEPROM_PAGE_SIZE 0x100
//#define E2END
#define EEPROM_START_ADDRESS 0x0000
*/


#define I2C_EEPROM
#define MARLIN_EEPROM_SIZE  0x1000
#define I2C_SCL_PIN         PB6
#define I2C_SDA_PIN         PB7


// Onboard I2C EEPROM
//#if NO_EEPROM_SELECTED
//#define I2C_EEPROM
//#define MARLIN_EEPROM_SIZE 0x1000                 // 4KB
//#undef NO_EEPROM_SELECTED
//#endif

// #if NOT_TARGET(TARGET_STM32F1)
//   #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
// #endif

// Release PB3/PB4 (E0 STP/DIR) from JTAG pins
#define DISABLE_JTAG

// Ignore temp readings during development.
//#define BOGUS_TEMPERATURE_GRACE_PERIOD    2000

//#if EITHER(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION)
//  #define FLASH_EEPROM_EMULATION
//  #define EEPROM_PAGE_SIZE     (0x800U)           // 2KB
//  #define EEPROM_START_ADDRESS (0x8000000UL + (STM32_FLASH_SIZE) * 1024UL - (EEPROM_PAGE_SIZE) * 2UL)
//  #define MARLIN_EEPROM_SIZE    EEPROM_PAGE_SIZE  // 2KB
//#endif

//
// Filament Runout Sensor
//
//#ifndef FIL_RUNOUT_PIN
//  #define FIL_RUNOUT_PIN                    PA1  // "FIL_SW" No Connection
//#endif

//
// Diag Pins
//
#define Y_DIAG_PIN                          PE15  // PD13  // "Y_DIAG"
#define X_DIAG_PIN                          PD4   // PD11  // "X_DIAG"
#define Z_DIAG_PIN                          PD11  // PE13  // "Z_DIAG"
#define E0_DIAG_PIN                         PA11  // PC8   // "E_DIAG"

//
// Limit Switches use diag for both directions
//
#define X_MAX_PIN                          X_DIAG_PIN   //!No limit switches
#define Y_MAX_PIN                          Y_DIAG_PIN //!No limit switches
#define X_MIN_PIN                          X_DIAG_PIN   //!No limit switches
#define Y_MIN_PIN                          Y_DIAG_PIN //!No limit switches
//#define Z_STOP_PIN                          PB1
#define Z_STOP_PIN                          PA7 // Z_Endstop (to Master MCU)
//
// Z Probe must be this pin
//
#define Z_MIN_PROBE_PIN                     Z_STOP_PIN  // PROBE
                
//
// Steppers
//
//! X and Y pins were switched to avoid crossing wires in electronics box for Boron
// For EVT1 X and Y pins returned back

/*
#define X_MS1_PIN                           PD6
#define X_MS2_PIN                           PD5
#define Y_MS1_PIN                           PB13
#define Y_MS2_PIN                           PB12
#define Z_MS1_PIN                           PD13
#define Z_MS2_PIN                           PD12
#define E_MS1_PIN                           PA15
#define E_MS2_PIN                           PA12
*/

#define Y_ENABLE_PIN                        PB15  // "Y_EN"
#define Y_STEP_PIN                          PE12  // "Y_STEP"
#define Y_DIR_PIN                           PE11  // "Y_DIR"
//#define Y_SERIAL_RX_PIN                     PB11  // Y_UART
//#define Y_SERIAL_TX_PIN                     PB10  // Y_UART w/10k resistor
#define Y_HARDWARE_SERIAL                   MSerial3

#define X_ENABLE_PIN                        PB3  // "X_EN"
#define X_STEP_PIN                          PD1   // "X_STEP"
#define X_DIR_PIN                           PD0   // "X_DIR"
//#define X_SERIAL_RX_PIN                     PD2  // X_UART
//#define X_SERIAL_TX_PIN                     PC12  // X_UART w/10k resistor
#define X_HARDWARE_SERIAL                   MSerial5

#define Z_ENABLE_PIN                        PD15   // "Z_EN"
#define Z_STEP_PIN                          PD8   // "Z_STEP"
#define Z_DIR_PIN                           PD9   // "Z_DIR"
//#define Z_SERIAL_RX_PIN                     PA3  // Z_UART
//#define Z_SERIAL_TX_PIN                     PA2  // Z_UART w/10k resistor
#define Z_HARDWARE_SERIAL                   MSerial2

#define E0_ENABLE_PIN                       PC14   // "E_EN"
#define E0_STEP_PIN                         PC8  // "E_STEP"
#define E0_DIR_PIN                          PC7   // "E_DIR"
//#define E0_SERIAL_RX_PIN                     PC11  // E_UART
//#define E0_SERIAL_TX_PIN                     PC10  // E_UART w/10k resistor
#define E0_HARDWARE_SERIAL                   MSerial4


// Fake extruder to enable additonal thermistor
//#define E1_ENABLE_PIN                       PC0   
//#define E1_STEP_PIN                         PC1  
//#define E1_DIR_PIN                          PC2   

//
// Temperature Sensors/ Thermistors  //!Currently assuming ch1 is chamber and ch2 is coldend

#define TEMP_0_PIN                          PC4   // Analog Input "NOZ_THERM"
#define TEMP_BED_PIN                        PA6   // Analog Input "BED_THERM"
#define TEMP_1_PIN                          PA1 // Analog Input "CH_TH_MCU" //! PA6 is confirmed to correspond to thermistor above printhead pcb 
#define TEMP_CHAMBER_PIN                    PA0   // Analog Input "CH_TH_MCU" this should run to the thermistor above printhead PCB
              // Analog Input "CH2_THERM" //! PA7 runs to the cold end thermistor, will for now run to the heater chamber thermistor P

//? Test values
//#define TEMP_1_PIN                          PA5   // Analog Input "NOZ_THERM"
//#define TEMP_BED_PIN                        PC4   // Analog Input "BED_THERM"
//#define TEMP_CHAMBER_PIN                    PA6   // Analog Input "CH1_THERM" //! PA6 is confirmed to correspond to thermistor above printhead pcb
//#define TEMP_0_PIN                          PA7   // Analog Input "CH2_THERM"

//
// Heaters / Fans //!Currently assuming ch1 is chamber and ch2 is coldend
//
#define HEATER_0_PIN                        PA4   // "HOTEND_HEAT"
#define HEATER_BED_PIN                      PB9   // "BED_HEAT"
#define HEATER_CHAMBER_PIN                  PB8   // "CH1_HEAT"
//#define HEATER_1_PIN                        PD1   // "CH2_HEAT"

//?These settings are just to test if hotend signal will turn on led, not in final build, delete after!
// #define HEATER_0_PIN                        PD0   // "HOTEND_HEAT"
// #define CASE_LIGHT_PIN                  PA3   // "CH1_HEAT"
// #define HEATER_1_PIN                        PD1   // "CH2_HEAT"
// #define HEATER_BED_PIN                      PA2   // "BED_HEAT"

//!FAN_PIN corresponds to FAN_1, FAN1_PIN corresponds to FAN_2 and etc.
//These two are the extruder heat sink and part cooling fan
//!FAN_PIN is always on! other fan pins are set in config adv

#define FAN1_PIN                           PE9   // "FAN_2" "FAN_HOT_MCU"
#define FAN_PIN                            PB0   // "FAN_1" "FAN_PRINT_MCU"   -> 39
//#define FAN2_PIN                         PA7

//Remaining are the rest of the fans including the Hepa, heater, and electronics box fans
// #define FAN2_PIN                          PE9    // "FAN_3"  -> pin 73   //!Use this as HEATER fan, MIGHT BE BROKEN
// #define FAN3_PIN                          PE8    // "FAN_4"  -> pin 72   //!Now using this as HEATER fan
// #define FAN4_PIN                          PE7    // "FAN_5"  -> pin 71   //!Use this as HEPA fan 
// #define FAN5_PIN                          PC12   // "FAN_6"  -> pin 44   //!Use this as electronics box fan 1
// #define FAN6_PIN                          PC11   // "FAN_7"  -> pin 43   //!Use this as electronics box fan 2
// #define FAN7_PIN                          PC10   // "FAN_8"  -> pin 42

// #define FAN2_PIN                          PE9    // "FAN_3"  -> pin 73   //!Use this as HEATER fan, MIGHT BE BROKEN
// #define FAN3_PIN                          PE8    // "FAN_4"  -> pin 72   //!Now using this as HEATER fan
// #define FAN4_PIN                          PE7    // "FAN_5"  -> pin 71   //!Use this as HEPA fan 
// #define FAN5_PIN                          PC12   // "FAN_6"  -> pin 44   //!Use this as electronics box fan 1
// #define FAN6_PIN                          PC11   // "FAN_7"  -> pin 43   //!Use this as electronics box fan 2
// #define FAN7_PIN                          PC10   // "FAN_8"  -> pin 42


//
// Miscellaneous
//
//TODO: Add door pins to pinsDebug_list and pins_postprocess(?)
// #define DOOR1_PIN                         PC14   // "DOOR_1"
// #define DOOR2_PIN                         PC15   // "DOOR_2"

// #define PURGE_PIN                         PC13   // "PURGE"

// #define BTN_EN1                           PC3   // "ENC_A"
// #define BTN_EN2                           PA0   // "ENC_B"

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "AEL105 Main Board V1.2.2"
#endif

// Release PA13/PA14 (led, usb control) from SWD pins
// #define DISABLE_DEBUG

// #ifndef NEOPIXEL_PIN
//   #define NEOPIXEL_PIN                     PD6   // LED driving pin
// #endif

// #ifndef PS_ON_PIN
//   #define PS_ON_PIN                        PC13  // Power Supply Control
// #endif
