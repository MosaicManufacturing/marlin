/**
 * variableSensitivity.h
 * Store the base value from which to determine homing value for XY sensitivity
 * and trigger to enable/disable variable XY homing sensitivity
**/
#ifndef _VARIABLEXYSENSITIVITY_
#define _VARIABLEXYSENSITIVITY_

#include <cstdint>

#include "../../../core/types.h"

class VariableXYSensitivity {
  private:
    float xBaseSensitivity;
    float yBaseSensitivity;
    float xOffsetSensitivity;
    float yOffsetSensitivity;
    bool variableSensitivity;

    int16_t getVariableSensitivity(
      uint8_t sensitivityVal,
      uint8_t offsetVal,
      celsius_float_t chamberTemperature
    ) const;
    // note that all sensitivity values (both base & offset for X & Y) should be [0,255] as per TMC driver documentation (TMC driver takes uint_8 as input for threshold sensitivity)

  public:
    VariableXYSensitivity();

    void init();

    void setToggle(bool toggleVal);

    void setXBase(uint8_t sensitivityVal);
    void setYBase(uint8_t sensitivityVal);

    void setXOffset(uint8_t offsetVal);
    void setYOffset(uint8_t offsetVal);

    int16_t getVariableXSensitivity(celsius_float_t chamberTemperature) const;
    int16_t getVariableYSensitivity(celsius_float_t chamberTemperature) const;

    int16_t getInitialXSensitivity() const;
    int16_t getInitialYSensitivity() const;

    bool getToggle() const;

    float getXBase() const;
    float getYBase() const;

    float getXOffset() const;
    float getYOffset() const;
};
#endif // _VARIABLEXYSENSITIVITY
