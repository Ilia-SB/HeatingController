/* 
* HeaterItem.h
*
* Created: 28.01.2016 15:32:58
* Author: Ivanov
*/


#ifndef __HEATERITEM_H__
#define __HEATERITEM_H__

#include "Arduino.h"

#define ADDR_LEN 3
#define SENSOR_ADDR_LEN	8

class HeaterItem
{
//variables
public:
	bool isEnabled;
	//const byte* address;
	uint64_t sensorAddress;
	byte port;
	byte pin;
	bool isAuto;
	uint16_t powerConsumption;
	bool isOn;
	bool wantsOn;
	byte priority;
	bool isConnected;
	bool actualState;
protected:
private:
	float temperature = 0;
	float targetTemperature = 0;
	float delta = 0;
	float temperatureAdjust = 0;

//functions
public:
	HeaterItem();
	~HeaterItem();
	bool operator>( const HeaterItem &c );
	//HeaterItem& operator=( const HeaterItem &c );
	void setTemperature(float temp);
	float getTemperature();
	void getTemperatureBytes(byte *array);
	void setTargetTemperature(float temp);
	float getTargetTemperature();
	void setTemperatureAdjust(float temp);
	float getTemperatureAdjust();
	void getTemperatureAdjustBytes(byte *array);
	float getDelta();
protected:
private:
	HeaterItem( const HeaterItem &c );
	//void byteToHexStr(const byte* value, uint8_t size, char* str, uint8_t* len);
}; //HeaterItem

#endif //__HEATERITEM_H__
