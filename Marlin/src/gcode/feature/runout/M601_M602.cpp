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

#include "../../../inc/MarlinConfig.h"

#include "../../MarlinCore.h" // for startOrResumeJob

#if HAS_FILAMENT_SENSOR

#include "../../gcode.h"
#include "../../../feature/runout.h"

/**
 * M412: Enable / Disable filament runout detection
 *
 * Parameters
 *  R         : Reset the runout sensor
 *  S<bool>   : Reset and enable/disable the runout sensor
 *  H<bool>   : Enable/disable host handling of filament runout
 *  D<linear> : Extra distance to continue after runout is triggered
 */
void GcodeSuite::M601() {
    SERIAL_ECHOLNPGM("ok");
    SERIAL_ECHOLNPGM("here is where we send command to apollo to indicate runout");
}

void GcodeSuite::M602() {
    SERIAL_ECHOLNPGM("ok");
    SERIAL_ECHOLNPGM("here is where we send command to apollo to indicate runout");

    #if ENABLED(PARK_HEAD_ON_PAUSE)

        M125();

    #else

        // Set initial pause flag to prevent more commands from landing in the queue while we try to pause

        print_job_timer.pause();

        TERN_(DGUS_LCD_UI_MKS, MKS_pause_print_move());             

    #endif
}

#endif // HAS_FILAMENT_SENSOR
