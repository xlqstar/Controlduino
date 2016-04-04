#include "Controlduino.h"

_Controlduino Controlduino;



const byte MUX_ADDR_PINS[] = { D8, D7, D5, D6 };
const byte MUX_COM_PIN = A7;
const int JOYSTICK_DEAD_ZONE = 100;

_Controlduino::_Controlduino(){
  for (byte p=0; p<4; p++) {
    pinMode(MUX_ADDR_PINS[p], OUTPUT);
  }
}

boolean _Controlduino::readButton(byte ch){
	switch(ch) {
	case JOYSTICK_RIGHT:
		return joyLowHalf(CH_JOYSTICK_X);
	case JOYSTICK_LEFT:
		return joyHighHalf(CH_JOYSTICK_X);
	case JOYSTICK_UP:
		return joyLowHalf(CH_JOYSTICK_Y);
	case JOYSTICK_DOWN:
		return joyHighHalf(CH_JOYSTICK_Y);
	}

	unsigned int val = readChannel(ch);
	return (val > 512) ? HIGH : LOW;

}

unsigned int _Controlduino::readChannel(byte channel){
	digitalWrite(MUX_ADDR_PINS[0], (channel & 1) ? HIGH : LOW);
	digitalWrite(MUX_ADDR_PINS[1], (channel & 2) ? HIGH : LOW);
	digitalWrite(MUX_ADDR_PINS[2], (channel & 4) ? HIGH : LOW);
	digitalWrite(MUX_ADDR_PINS[3], (channel & 8) ? HIGH : LOW);
	// workaround to cope with lack of pullup resistor on joystick switch
	if (channel == CH_LeftJoystickButton || channel == CH_RightJoystickButton) {
		pinMode(MUX_COM_PIN, INPUT_PULLUP); 
		unsigned int joystickSwitchState = (digitalRead(MUX_COM_PIN) == HIGH) ? 1023 : 0;
		digitalWrite(MUX_COM_PIN, LOW);
		return joystickSwitchState;
	}
	else
    return analogRead(MUX_COM_PIN);
}

boolean _Controlduino::joyLowHalf(byte joyCh) {
  return (readChannel(joyCh) < 512 - JOYSTICK_DEAD_ZONE)
    ? LOW : HIGH;
}

boolean _Controlduino::joyHighHalf(byte joyCh) {
  return (readChannel(joyCh) > 512 + JOYSTICK_DEAD_ZONE)
    ? LOW : HIGH;
}
