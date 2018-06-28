/*
Library			: AutoAttenuator.h
Start date		: 26 June 2018
Written by		: Shubhi Rofiddinsa
Supervised by	: Daniel Merk, Peter Straube

Purpose:
- As a substitute for the mechanical knobs
- Controls and read data from the board
*/


#ifndef AutoAttenuator_h
#define AutoAttenuator_h

#include <Arduino.h>

class Attenuator
{
		// Class member variables
		int pin1;
		int pin2;
		int pin3;
		int pin4;
		int pin5;
	
	public:
		// Overloading constructors
		Attenuator();														//10dB
		Attenuator(int pin_1, int pin_2, int pin_3, int pin_4, int pin_5);	//20-60dB
		
		// Functions to the board
		// Attenuation settings
		int setAtt10();
		int setAtt20();
		int setAtt30();
		int setAtt40();
		int setAtt50();
		int setAtt60();
		
		// choosing between set or read actual attenuation
		void chooseMode();
		
		// choosing/set attenuation
		void setAttenuation();
		
		// read attenuation
		void readAttenuation();
		
		// displaying messages to choose
		void displayChoice();
		void displayAtt();
		
};

#endif