#ifndef __DEVICE_H
#define __DEVICE_H

#include "Arduino.h"
#include <EasyButton.h>
#include <EasyButtonVirtual.h>
#include "definitions.h" 

#define NAVI_BUTTONS
//#define I2C_KEYPAD
//#define VOL_ROTARY
//#define TUNE_ROTARY
#define POWER_SWITCH

#define ROT1_CLK            -1 //36
#define ROT1_DT             -1 //37
#define ROT1_SW             -1 //38
#define ROT2_CLK            -1 //33
#define ROT2_DT             -1 //32
#define ROT2_SW             -1 //39

#define NAVI_LEFT           2
#define NAVI_RIGHT          12
#define NAVI_UP             17
#define NAVI_DOWN           15
#define NAVI_OK             13

#define POWER_SWITCH_PIN    27    

struct HardwareButton {
    uint8_t KeyId;
    EasyButton Btn;
    pCommandFn RepeatableLongFn; // Short press and simple long press functions stored in EasyButton object. This stores the callback function only if long press requires to execute command repeatedly. Not the nicest solution tho
};

struct VirtualButton {
    uint8_t KeyId;
    EasyButtonVirtual Btn;
    pCommandFn RepeatableLongFn; // Short press and simple long press functions stored in EasyButton object. This stores the callback function only if long press requires to execute command repeatedly. Not the nicest solution tho
};

struct Rotary{
    int8_t Clk;
    int8_t Dt;
    //uint8_t Sw;
    uint8_t lastStateClk;
    //unsigned long lastButtonPress;
};

extern bool state_KEY_MATRIX_A, state_KEY_MATRIX_B, state_KEY_MATRIX_C, state_KEY_MATRIX_D, state_KEY_MATRIX_ASTERISK, state_KEY_MATRIX_SHARP, state_KEY_MATRIX_NUM,
            state_KEY_ROT_ROT1_DOWN, state_KEY_ROT_ROT1_UP, state_KEY_ROT_ROT2_DOWN, state_KEY_ROT_ROT2_UP;

extern Rotary rotTune;
extern Rotary rotVol;

extern HardwareButton HwButtons[];
extern VirtualButton VirtButtonsMatrix[];
extern VirtualButton VirtButtonsRotary[];

extern size_t HwButtonsSize;
extern size_t VirtButtonsMatrixSize;
extern size_t VirtButtonsRotarySize;


#endif