#include "../../../inc/MarlinConfig.h"
#include "../../gcode.h"

VariableXYSensitivity variableXYSensitivity;

#if USE_SENSORLESS
    void GcodeSuite::M920() {
        if (parser.seen('S')) variableXYSensitivity.setToggle(parser.value_bool());
        LOOP_NUM_AXES(a) if (parser.seen(AXIS_CHAR(a))) {
            float value = parser.value_float();
            if (value < 0) {
                value = 0;
                SERIAL_ECHO("Sensitivity values cannot be less than 0. Sensitivity value set to 0.");
                }
            else if (value > 255) {
                value = 255;
                SERIAL_ECHO("Sensitivity values cannot be larger than 255. Sensitivity value set to 255.");
                }

            switch (a) {
                case X_AXIS:
                    variableXYSensitivity.setXBase(value);
                    break;
                case Y_AXIS:
                    variableXYSensitivity.setYBase(value);
                    break;
                case Z_AXIS:
                    // TODO: echo error?
                    break;
            }
        };
        serialprint_onoff(variableXYSensitivity.getToggle());
        SERIAL_ECHO("\nX: ");
        SERIAL_ECHO(variableXYSensitivity.getXBase()); //echo value
        SERIAL_ECHO(", Y: ");
        SERIAL_ECHO(variableXYSensitivity.getYBase()); //echo value
        SERIAL_EOL();
    }
#endif
