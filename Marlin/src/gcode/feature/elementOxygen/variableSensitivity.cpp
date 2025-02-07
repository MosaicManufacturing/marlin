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
    xOffsetSensitivity = 8;
    yOffsetSensitivity = 8;
    variableSensitivity = true;
}

void VariableXYSensitivity::setToggle(bool toggleVal) {
    variableSensitivity = toggleVal;
}
void VariableXYSensitivity::setXBase(uint8_t sensitivityVal) {
    xBaseSensitivity = static_cast<float>(sensitivityVal);
}
void VariableXYSensitivity::setYBase(uint8_t sensitivityVal) {
    yBaseSensitivity = static_cast<float>(sensitivityVal);
}
void VariableXYSensitivity::setXOffset(uint8_t offsetVal) {
    xOffsetSensitivity = static_cast<float>(offsetVal);
}
void VariableXYSensitivity::setYOffset(uint8_t offsetVal) {
    yOffsetSensitivity = static_cast<float>(offsetVal);
}

int16_t VariableXYSensitivity::getVariableSensitivity(
    uint8_t sensitivityVal, uint8_t offsetVal, celsius_float_t chamberTemperature) const {
        const float maxChamberTemp = 80.;
        const float minChamberTemp = 25.;
        float offsetR = (chamberTemperature - minChamberTemp) / (maxChamberTemp - minChamberTemp);
        // bound to [0, 1]
        offsetR = max(min(offsetR, 1.0f), 0.0f);
        int16_t interpolatedSensitivity = static_cast<int16_t>(ceil(sensitivityVal - offsetR * offsetVal));
        return interpolatedSensitivity;
    }


int16_t VariableXYSensitivity::getVariableXSensitivity(celsius_float_t chamberTemperature) const {
    return getVariableSensitivity(xBaseSensitivity, xOffsetSensitivity, chamberTemperature);
}

int16_t VariableXYSensitivity::getVariableYSensitivity(celsius_float_t chamberTemperature) const {
    return getVariableSensitivity(yBaseSensitivity, yOffsetSensitivity, chamberTemperature);

}

int16_t VariableXYSensitivity::getInitialXSensitivity() const {
    return xBaseSensitivity - xOffsetSensitivity;
}
int16_t VariableXYSensitivity::getInitialYSensitivity() const {
    return yBaseSensitivity - yOffsetSensitivity;
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
