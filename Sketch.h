/*
 * Sketch.h
 *
 * Created: 01.06.2016 17:22:25
 *  Author: Ivanov
 */ 


#ifndef SKETCH_H_
#define SKETCH_H_

//#define DEBUG

#include <Arduino.h>
#include <EEPROM.h>
#include "config.h"
#include "PinReadWrite.h"
#include <OneWire.h>
#include "HeaterItem.h"
#include "Interface.h"
#include "DebugPrint.h"
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "MemoryFree.h"

static void heatersOff(int availablePower, HeaterItem** autoHeaters, int autoHeatersCount, HeaterItem** manualHeaters, int manualHeatersCount);
static void heatersOn(int availablePower, HeaterItem** autoHeaters, int autoHeatersCount, HeaterItem** manualHeaters, int manualHeatersCount);
static void processHeaters(int currentConsumption, boolean mode);
static void sortHeaters(HeaterItem **array, int size);
//static void detectSensors(void);
static void startSensor(uint64_t *addr);
static float readSensor(uint64_t *addr);
static void startSensorsRead(void);
static void processCommand(uint8_t heaterNumber, byte* payload, unsigned int  len);
//static byte calculateCRC(byte *command, int len);
static void eepromWriteHeater(uint8_t i);
static void eepromDelayedWrite(uint8_t heaterNumber, uint8_t offset);
static void eepromWriteItem(uint8_t heaterNumber, uint8_t offset);
static void eepromReadHeater(uint8_t heaterNumber);
static void initHeaters();
static void validateHeater(uint8_t heaterNumber);
static void initPins(void);
static unsigned long elapsedSince(unsigned long);
static void stringToByteArray(const char* string, uint8_t len, byte* hex);
static void byteArrayToString(const byte* hex, uint8_t len, char* string);
static void mqttCallback(char* topic, byte* payload, unsigned int length);
static void mqttReconnect(void);
static void reportTotalConsumption(void);
static void reportHeater(uint8_t heaterNumber);
static void reportItem(uint8_t heaterNumber, uint8_t item);

#endif /* SKETCH_H_ */