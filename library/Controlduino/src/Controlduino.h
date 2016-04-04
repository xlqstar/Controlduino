#ifndef CONTROLDUINO_H_
#define CONTROLDUINO_H_

#include <Arduino.h>

const byte JOYSTICK_BASE  = 16; // it's a "virtual" channel: its ID won't conflict with real ones

// const byte MAX_CHANNELS   = 13;

// const byte CH_SWITCH_1    = 0;
// const byte CH_SWITCH_2    = 1;
// const byte CH_SWITCH_3    = 2;
// const byte CH_SWITCH_4    = 3;
// const byte CH_SLIDER      = 4;
// const byte CH_LIGHT       = 5;
// const byte CH_TEMPERATURE = 6;
// const byte CH_MIC         = 7;
// const byte CH_TINKERKIT_A = 8;
// const byte CH_TINKERKIT_B = 9;
// const byte CH_JOYSTICK_SW = 10;
// const byte CH_JOYSTICK_X  = 11;
// const byte CH_JOYSTICK_Y  = 12;


// L2Button 1
// L1Button 2
// SHButton reset

// UpButton 4
// LeftButton 5
// RightButton 3
// DownButton 6

// LeftJoystickX
// LeftJoystickButton 14
// LeftJoystickY




// R2Button 12
// R1Button 13
// OPButton

// TriangleButton 10
// SquareButton 11
// OButton 9
// XButton 8

// RightJoystickX
// RightJoystickButton 16
// RightJoystickY



// HomeButton 7


const byte MAX_CHANNELS   = 21;

const byte CH_L1Button = 6; //s2
const byte CH_L2Button = 7; //s1

const byte CH_UpButton = 4; //s4
const byte CH_DownButton = 2; //s6
const byte CH_LeftButton = 3; //s5
const byte CH_RightButton = 5; //s3

const byte CH_LeftJoystickButton = 13; //s14
const byte CH_LeftJoystickX = 7;
const byte CH_LeftJoystickY = 8;

const byte CH_R1Button = 12; //s13
const byte CH_R2Button = 11; //s12

const byte CH_TriangleButton = 9; //s10
const byte CH_OButton = 8; //s9
const byte CH_XButton = 0; //s8
const byte CH_SquareButton = 10; //s11

const byte CH_RightJoystickButton = 15; //s16
const byte CH_RightJoystickX = 16;
const byte CH_RightJoystickY = 17;

const byte CH_ShareButton = 18; //reset
const byte CH_OptionButton = 14; //s15

const byte CH_HomeButton = 1; //s7

class _Controlduino {
private:
	unsigned int readChannel(byte channel);

public:
	_Controlduino();

	// inline unsigned int readJoystickSwitch() { return readChannel(CH_JOYSTICK_SW); }
	boolean readButton(byte channel);

	inline int readLeftJoystickX() { 
		return readChannel(CH_LeftJoystickX) - 512;
	}

	inline int readLeftJoystickY() {
		return readChannel(CH_LeftJoystickY) - 512;
	}

	inline int readRightJoystickX() { 
		return readChannel(CH_RightJoystickX) - 512;
	}

	inline int readRightJoystickY() {
		return readChannel(CH_RightJoystickY) - 512;
	}
};


extern _Controlduino Controlduino;

#endif // CONTROLDUINO_H_
