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

// Onboard I2C EEPROM
#if NO_EEPROM_SELECTED
  #define I2C_EEPROM
  #define MARLIN_EEPROM_SIZE 0x1000                 // 4KB
  #undef NO_EEPROM_SELECTED
#endif

// #if NOT_TARGET(TARGET_STM32F1)
//   #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
// #endif

// Release PB3/PB4 (E0 STP/DIR) from JTAG pins
// #define DISABLE_JTAG

// Ignore temp readings during development.
//#define BOGUS_TEMPERATURE_GRACE_PERIOD    2000

#if EITHER(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION)
  #define FLASH_EEPROM_EMULATION
  #define EEPROM_PAGE_SIZE     (0x800U)           // 2KB
  #define EEPROM_START_ADDRESS (0x8000000UL + (STM32_FLASH_SIZE) * 1024UL - (EEPROM_PAGE_SIZE) * 2UL)
  #define MARLIN_EEPROM_SIZE    EEPROM_PAGE_SIZE  // 2KB
#endif

//
// Limit Switches
//
#define X_STOP_PIN                          -1   //!No limit switches
#define Y_STOP_PIN                          -1   //!No limit switches
#define Z_STOP_PIN                          -1   //!No limit switches

//
// Z Probe must be this pin
//
#define Z_MIN_PROBE_PIN                     PC14  // PROBE //!

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA1  // "FIL_SW"
#endif

//
// Diag Pins
//
#define X_DIAG_PIN                          PD13  // "X_DIAG"
#define Y_DIAG_PIN                          PD11  // "Y_DIAG"
#define Z_DIAG_PIN                          PE13  // "Z_DIAG"
#define E0_DIAG_PIN                         PC8   // "E_DIAG"

//
// Steppers
//
#define X_ENABLE_PIN                        PD14  // "X_EN"
#define X_STEP_PIN                          PC6   // "X_STEP"
#define X_DIR_PIN                           PD15  // "X_DIR"
#define X_CS_PIN                            PC7   // "X_nCS"

#define Y_ENABLE_PIN                        PD10  // "Y_EN"
#define Y_STEP_PIN                          PD8   // "Y_STEP"
#define Y_DIR_PIN                           PD9   // "Y_DIR"
#define Y_CS_PIN                            PD12  // "Y_nCS"

#define Z_ENABLE_PIN                        PE12  // "Z_EN"
#define Z_STEP_PIN                          PE14  // "Z_STEP"
#define Z_DIR_PIN                           PE15  // "Z_DIR"
#define Z_CS_PIN                            PB12  // "Z_nCS"

#define E0_ENABLE_PIN                       PC9   // "E_EN"
#define E0_STEP_PIN                         PA11  // "E_STEP"
#define E0_DIR_PIN                          PA8   // "E_DIR"
#define E0_CS_PIN                           PA12  // "E_nCS"

//
// Temperature Sensors  //!Currently assuming ch1 is chamber and ch2 is coldend
//
#define TEMP_0_PIN                          PA5   // Analog Input "NOZ_THERM"
#define TEMP_CHAMBER_PIN                    PA6   // Analog Input "CH1_THERM" 
#define TEMP_1_PIN                          PA7   // Analog Input "CH2_THERM" 
#define TEMP_BED_PIN                        PC4   // Analog Input "BED_THERM" 

//
// Heaters / Fans //!Currently assuming ch1 is chamber and ch2 is coldend
//
#define HEATER_0_PIN                        PA3   // "HOTEND_HEAT" 
#define HEATER_CHAMBER_PIN                  PD0   // "CH1_HEAT" 
#define HEATER_1_PIN                        PD1   // "CH2_HEAT" 
#define HEATER_BED_PIN                      PA2   // "BED_HEAT"

//!FAN_PIN corresponds to FAN_1, FAN1_PIN corresponds to FAN_2 and etc.
#define FAN_PIN                           PE11   // "FAN_1"
#define FAN1_PIN                          PE10   // "FAN_2" 
#define FAN2_PIN                          PE9    // "FAN_3" 
#define FAN3_PIN                          PE8    // "FAN_4" 
#define FAN4_PIN                          PE7    // "FAN_5" 
#define FAN5_PIN                          PC12   // "FAN_6" 
#define FAN6_PIN                          PC11   // "FAN_7" 
#define FAN7_PIN                          PC10   // "FAN_8" 

//
// Miscellaneous 
//
//TODO: Add door pins to pinsDebug_list and pins_postprocess(?)
// #define DOOR1_PIN                         PC14   // "DOOR_1" 
// #define DOOR2_PIN                         PC15   // "DOOR_2" 

// #define PURGE_PIN                         PC13   // "PURGE"

// #define BTN_EN1                           PC3   // "ENC_A"
// #define BTN_EN2                           PA0   // "ENC_B"

//*Uncomment below for inductive probe support


//
// USB connect control
//
// #define USB_CONNECT_PIN                   PD3  //! "USB_B_POWER?"

// #define USB_CONNECT_INVERTING              false

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


