/* 
* ConsumptionMeter.cpp
*
* Created: 28.01.2016 15:57:41
* Author: Ivanov
*/


#include "ConsumptionMeter.h"

ConsumptionMeter cm;

// default constructor
ConsumptionMeter::ConsumptionMeter()
{
	thisImpulseTime=0;
	prevImpulseTime=0;
	consumption = 0;
	
	*digitalPinToPCMSK(CM_SENSOR) |= _BV(digitalPinToPCMSKbit(CM_SENSOR));  // enable pin
	pinAsInputPullUp(CM_SENSOR);
	PCIFR  |= _BV(digitalPinToPCICRbit(CM_SENSOR)); // clear any outstanding interrupt
	PCICR  |= _BV(digitalPinToPCICRbit(CM_SENSOR)); // enable interrupt for the group
} //ConsumptionMeter

// default destructor
ConsumptionMeter::~ConsumptionMeter()
{
} //~ConsumptionMeter

// get current power consumption value
uint16_t ConsumptionMeter::getConsumption() {
	noInterrupts();
	if (prevImpulseTime != 0) {
		if (thisImpulseTime > prevImpulseTime) {
			consumption = CONST / (thisImpulseTime - prevImpulseTime);
		}
	}
	interrupts();
	return consumption;
}


/*
void ConsumptionMeter::process()
{
	if(tick) {
		tick = false;
		#ifdef DEBUG
			if (ledState) {
				digitalHigh(LED);
				} else {
				digitalLow(LED);
			}
			ledState =!ledState;
		#endif
	}
}
*/

void ConsumptionMeter::isr() {
		if (isLow(CM_SENSOR)) {
			prevImpulseTime = thisImpulseTime;
			thisImpulseTime = millis();
		}
}

ISR(PCINT0_vect) {
	cm.isr();
}

ISR(PCINT1_vect) {
	cm.isr();
}

ISR(PCINT2_vect) {
	cm.isr();
}