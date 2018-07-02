/*
Library			: AutoAttenuator.cpp
Start date		: 26 June 2018
Written by		: Shubhi Rofiddinsa
Supervised by	: Daniel Merk, Peter Straube

Purpose:
- As a substitute for the mechanical knobs
- Controls and read data from the board
*/

#include "AutoAttenuator.h"
#include "Arduino.h"

// Terminal messages
String messageAtt = "Choose Attenuation from 10-60dB.";
String mainMessage1 = "Main Menu";
String separator = "----------------------------------";

// Variable to pass value
int attenuationValue;

// Overloading constructors
Attenuator::Attenuator()
{
	// Empty. Default 10dB is already connected between EUT & AE
}

Attenuator::Attenuator(int pin_1, int pin_2, int pin_3, int pin_4, int pin_5)
{
	pin1 = pin_1;
	pin2 = pin_2;
	pin3 = pin_3;
	pin4 = pin_4;
	pin5 = pin_5;
	
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	pinMode(pin3, OUTPUT);
	pinMode(pin4, OUTPUT);
	pinMode(pin5, OUTPUT);
}

// Attenuation settings from 10-60dB

int Attenuator::setAtt10()
{
	int attVal = 10;
	
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(1000);
	
	// Update value
	attenuationValue = attVal;
	
	// Passing value to functions
	return updateAtt();
}

int Attenuator::setAtt20()
{
	int attVal = 20;
	
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, HIGH);
	digitalWrite(pin3, HIGH);
	digitalWrite(pin4, HIGH);
	digitalWrite(pin5, HIGH);
	
	delay(1000);
	
	attenuationValue = attVal;
	
	return updateAtt();
}
int Attenuator::setAtt30()
{
	int attVal = 30;

	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, HIGH);
	digitalWrite(pin3, HIGH);
	digitalWrite(pin4, HIGH);
	
	delay(1000);
	
	attenuationValue = attVal;
	
	return updateAtt();
}

int Attenuator::setAtt40()
{
	int attVal = 40;

	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, HIGH);
	digitalWrite(pin3, HIGH);
	
	delay(1000);
	
	attenuationValue = attVal;
	
	return updateAtt();
}

int Attenuator::setAtt50()
{
	int attVal = 50;

	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, HIGH);
	
	delay(1000);
	
	attenuationValue = attVal;
	
	return updateAtt();
}

int Attenuator::setAtt60()
{
	int attVal = 60;

	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	
	digitalWrite(pin1, HIGH);
	
	delay(1000);
	
	attenuationValue = attVal;
	
	return updateAtt();
}

int Attenuator::incAtt()
{
	// Copy actual value
	int attValue = attenuationValue;
	
	// Switch cases
	switch(attValue){
		case 10:
			setAtt20();
			readAttenuation();
			break;
		case 20:
			setAtt30();
			readAttenuation();
			break;
		case 30:
			setAtt40();
			readAttenuation();
			break;
		case 40:
			setAtt50();
			readAttenuation();
			break;
		case 50:
			setAtt60();
			readAttenuation();
			break;
		case 60:
			Serial.println("60dB is the maximum setting.\n");
			Serial.println(separator);
	}
}

int Attenuator::decAtt()
{
	// Copy actual value
	int attValue = attenuationValue;
	
	// Switch cases
	switch(attValue){
		case 20:
			setAtt10();
			readAttenuation();
			break;
		case 30:
			setAtt20();
			readAttenuation();
			break;
		case 40:
			setAtt30();
			readAttenuation();
			break;
		case 50:
			setAtt40();
			readAttenuation();
			break;
		case 60:
			setAtt50();
			readAttenuation();
			break;
		default:
			Serial.println("10dB is the minimum setting.\n");
			Serial.println(separator);
	}
}

// Choose mode
void Attenuator::mainMenu()
{
	int selectMode;
	displayChoice();
	
	while(Serial.available()==0){
	}
	selectMode = Serial.read();
	
	// Switch cases
	switch(selectMode){
		case '1':
			setAttenuation();
			break;
		case '2':
			readAttenuation();
			break;
		case '3':
			incAtt();
			break;
		case '4':
			decAtt();
			break;
		case '5':
			clearScreen();
			break;
		default:
			Serial.println("Input not recognised! Choose again.\n");
			Serial.println(separator);
	}
}

// Choose/set attenuation
void Attenuator::setAttenuation()
{	
	int selectAtt;
	displayAtt();
	
	while(Serial.available()==0){
	}
	selectAtt = Serial.read();
	
	// Switch cases
	switch(selectAtt){
		case '1':
			setAtt10();
			Serial.println("You selected 10dB!\n");
			Serial.println(separator);
			break;
		case '2':
			setAtt20();
			Serial.println("You selected 20dB!\n");
			Serial.println(separator);
			break;
		case '3':
			setAtt30();
			Serial.println("You selected 30dB!\n");
			Serial.println(separator);
			break;
		case '4':
			setAtt40();
			Serial.println("You selected 40dB!\n");
			Serial.println(separator);
			break;
		case '5':
			setAtt50();
			Serial.println("You selected 50dB!\n");
			Serial.println(separator);
			break;
		case '6':
			setAtt60();
			Serial.println("You selected 60dB!\n");
			Serial.println(separator);
			break;
		default:
			Serial.println("Input not recognised! Choose again.\n");
			Serial.println(separator);
	}
		
}

// Update value
int Attenuator::updateAtt()
{
	int updateValue = attenuationValue;
	
	return updateValue;
}

// read actual settings
void Attenuator::readAttenuation()
{
	Serial.print("Actual setting:");
	Serial.print(updateAtt());
	Serial.println(" dB\n");
	Serial.println(separator);
}

// Functions to operate boards

void Attenuator::displayChoice()
{
	Serial.println(mainMessage1);
	Serial.println("1. Set Attenuation");
	Serial.println("2. Read Attenuation");
	Serial.println("3. +10dB");
	Serial.println("4. -10dB");
	Serial.println("5. Clear screen\n");
}

void Attenuator::displayAtt()
{
	Serial.println(messageAtt);
	Serial.println("1. 10dB");
	Serial.println("2. 20dB");
	Serial.println("3. 30dB");
	Serial.println("4. 40dB");
	Serial.println("5. 50dB");
	Serial.println("6. 60dB");
}

// clear screen functions (only use this with PuTTY)
void Attenuator::clearScreen()
{
	Serial.write(27);			// ESC command
	Serial.print("[2J");		// clear screen command
	Serial.write(27);
	Serial.print("[H");			// cursor to home command
}