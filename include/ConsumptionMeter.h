/* 
* ConsumptionMeter.h
*
* Created: 28.01.2016 15:57:41
* Author: Ivanov
*/


#ifndef __CONSUMPTIONMETER_H__
#define __CONSUMPTIONMETER_H__

#include "pins_arduino.h"
#include "PinReadWrite.h"
#include "Arduino.h"
#include "config.h"

//#define DEBUG

#define CONST	1125000 //for 3200 impulses per kW/h


ISR(PCINT0_vect);
ISR(PCINT1_vect);
ISR(PCINT2_vect);

class ConsumptionMeter
{
friend void PCINT0_vect();
friend void PCINT1_vect();
friend void PCINT2_vect();

//variables
public:
	volatile bool tick;
protected:
private:
	volatile long thisImpulseTime, prevImpulseTime;
	uint16_t consumption;

//functions
public:
	ConsumptionMeter();
	~ConsumptionMeter();
	uint16_t getConsumption();
	//void process();
protected:
private:
	ConsumptionMeter( const ConsumptionMeter &c );
	ConsumptionMeter& operator=( const ConsumptionMeter &c );
	inline void isr();
}; //ConsumptionMeter

extern ConsumptionMeter cm;

#endif //__CONSUMPTIONMETER_H__
