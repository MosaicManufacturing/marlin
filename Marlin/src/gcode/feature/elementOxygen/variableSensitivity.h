/**
 * variableSensitivity.h
 * Store the base value from which to determine homing value for XY sensitivity
 * and trigger to enable/disable variable XY homing sensitivity
**/
#ifndef _VARIABLEXYSENSITIVITY_
#define _VARIABLEXYSENSITIVITY_

#include <cstdint>

class VariableXYSensitivity {
  private:
    float xBaseSensitivity;
    float yBaseSensitivity; //currently unused
    float xOffsetSensitivity; 
    float yOffsetSensitivity; //currently unused
    bool variableSensitivity;
    // note that all sensitivity values (both base & offset for X & Y) should be [0,255] as per TMC driver documentation (TMC driver takes uint_8 as input for threshold sensitivity)
  public:
    VariableXYSensitivity(); 

    void init();

    void setToggle(bool toggleVal);

    void setXBase(uint8_t sensitivityVal);
    void setYBase(uint8_t sensitivityVal);

    void setXOffset(uint8_t offsetVal);
    void setYOffset(uint8_t offsetVal);

    bool getToggle() const;

    float getXBase() const;
    float getYBase() const;

    float getXOffset() const;
    float getYOffset() const;
};
#endif // _VARIABLEXYSENSITIVITY