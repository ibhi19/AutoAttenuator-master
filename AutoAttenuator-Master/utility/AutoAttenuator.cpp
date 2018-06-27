/*
Library			: AutoAttenuator.cpp
Start date		: 26 June 2018
Written by		: Shubhi Rofiddinsa
Supervised by	: Daniel Merk, Peter Straube

Purpose:
- As a substitute for the mechanical knobs of BP0505/A
- Controls and read data from the board
*/

#include "AutoAttenuator.h"
#include "Arduino.h"

// Terminal messages
String messageAtt = "Choose Attenuation from 10-60dB.";
String messageChoice = "Choose between set or read attenuation.";

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

void Attenuator::setAtt10()
{
	Serial.println("You selected 10dB!\n");
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(1000);
}

void Attenuator::setAtt20()
{
	Serial.println("You selected 20dB!\n");
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
}

void Attenuator::setAtt30()
{
	Serial.println("You selected 30dB!\n");
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
}

void Attenuator::setAtt40()
{
	Serial.println("You selected 40dB!\n");
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
}

void Attenuator::setAtt50()
{
	Serial.println("You selected 50dB!\n");
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, HIGH);
	
	delay(1000);
}

void Attenuator::setAtt60()
{
	Serial.println("You selected 60dB!\n");
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	digitalWrite(pin3, LOW);
	digitalWrite(pin4, LOW);
	digitalWrite(pin5, LOW);
	
	delay(50);
	
	digitalWrite(pin1, HIGH);
	
	delay(1000);
}

// Choose mode
void Attenuator::chooseMode()
{
	int selectMode;
	displayChoice();
	
	while(Serial.available()==0){
	}
	selectMode = Serial.read();
	
	// Switch cases
	switch(selectMode){
		case '1':
			chooseAttenuation();
			break;
		default:
			Serial.println("Input not recognised! Choose again.\n");
	}
}

// Choose attenuation
void Attenuator::chooseAttenuation()
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
			break;
		case '2':
			setAtt20();
			break;
		case '3':
			setAtt30();
			break;
		case '4':
			setAtt40();
			break;
		case '5':
			setAtt50();
			break;
		case '6':
			setAtt60();
			break;
		default:
			Serial.println("Wrong input! Choose again.\n");
	}
		
}

// Functions to operate boards

void Attenuator::displayChoice()
{
	Serial.println(messageChoice);
	Serial.println("1. Set Attenuation");
	Serial.println("2. Read Attenuation\n");
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