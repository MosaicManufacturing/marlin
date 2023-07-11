/**
 * variableSensitivity.cpp
 * Store the base value from which to determine homing value for XY sensitivity
 * and trigger to enable/disable variable XY homing sensitivity
**/
#include "variableSensitivity.h"
#include "../../../inc/MarlinConfig.h"

VariableXYSensitivity::VariableXYSensitivity() { init(); }

void VariableXYSensitivity::init() {
    xBaseSensitivity = X_STALL_SENSITIVITY;
    yBaseSensitivity = Y_STALL_SENSITIVITY;
    xOffsetSensitivity = 10;
    yOffsetSensitivity = 0;
    variableSensitivity = true;
}

void VariableXYSensitivity::setToggle(bool toggleVal) {
    variableSensitivity = toggleVal;
}
void VariableXYSensitivity::setXBase(uint8_t sensitivityVal) {
    xBaseSensitivity = (float)sensitivityVal;
}
void VariableXYSensitivity::setYBase(uint8_t sensitivityVal) {
    yBaseSensitivity = (float)sensitivityVal;
}
void VariableXYSensitivity::setXOffset(uint8_t offsetVal) {
    xOffsetSensitivity = (float)offsetVal;
}
void VariableXYSensitivity::setYOffset(uint8_t offsetVal) {
    yOffsetSensitivity = (float)offsetVal;
}

bool VariableXYSensitivity::getToggle() const {
    return variableSensitivity;
}
float VariableXYSensitivity::getXBase() const {
    return xBaseSensitivity;
}
float VariableXYSensitivity::getYBase() const {
    return yBaseSensitivity;
}
float VariableXYSensitivity::getXOffset() const {
    return xOffsetSensitivity;
}
float VariableXYSensitivity::getYOffset() const {
    return yOffsetSensitivity;
}