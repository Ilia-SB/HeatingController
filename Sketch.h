/*
 * Sketch.h
 *
 * Created: 01.06.2016 17:22:25
 *  Author: Ivanov
 */ 


#ifndef SKETCH_H_
#define SKETCH_H_

#include "Arduino.h"
#include "EEPROMAnything.h"
#include <EEPROM.h>
#include "avr/eeprom.h"
#include "config.h"
#include "CommBuffer.h"
#include "ConsumptionMeter.h"
#include "PinReadWrite.h"
#include "OneWire.h"
#include "HeaterItem.h"
#include "TimerOne.h"
#include "MsTimer2.h"
#include "Interface.h"
#include "DebugPrint.h"

void heatersOff(int availablePower, HeaterItem** autoHeaters, int autoHeatersCount, HeaterItem** manualHeaters, int manualHeatersCount);
void heatersOn(int availablePower, HeaterItem** autoHeaters, int autoHeatersCount, HeaterItem** manualHeaters, int manualHeatersCount);
void processHeaters(int currentConsumption, boolean mode);
void timer1_ISR(void);
void timer2_ISR(void);
void sortHeaters(HeaterItem **array, int size);
void processSerial(void);
void detectSensors(void);
void startSensor(byte *addr);
float readSensor(byte *addr);
void startSensorsRead(void);
void processCommand(void);
bool commandIsValid(byte *command, int len);
byte calculateCRC(byte *command, int len);
void reportSensors(void);
void reportSensorAddresses(void);
void eepromRead(void);
void eepromWrite(int i);
void eepromWriteHeater(uint8_t i);
void eepromDelayedWrite(uint8_t heaterNumber, uint8_t offset);
void eepromWriteItem(uint8_t heaterNumber, uint8_t offset);
void eepromReadHeater(uint8_t heaterNumber);
bool arraysEqual(byte *array1, byte *array2);
void checkConnected(void);
void reportUnconnected(void);
void reportUnconfigured(void);
void printAddress(byte *address);
void initHeaters();
void makeCommand(byte command, byte* address, byte* data, int dataLen, byte* comBuffer, byte* comBufferLen);
void validateHeater(uint8_t heaterNumber);
void initPins(void);
unsigned long elapsedSince(unsigned long);
void listHeaters(HeaterItem **array, int size);

void reportTemp(HeaterItem *);
void reportActualState(HeaterItem *);
void reportTotalConsumption(void);

#ifdef DEBUG
	void randomizeHeaters(void);
#endif
#endif /* SKETCH_H_ */