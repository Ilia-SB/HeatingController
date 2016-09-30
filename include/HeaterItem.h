/* 
* HeaterItem.h
*
* Created: 28.01.2016 15:32:58
* Author: Ivanov
*/


#ifndef __HEATERITEM_H__
#define __HEATERITEM_H__

#include "Arduino.h"

class HeaterItem
{
//variables
public:
	boolean isEnabled;
	byte address[3];
	byte sensorAddress[8];
	byte port;
	byte pin;
	boolean isAuto;
	uint16_t powerConsumption;
	boolean isOn;
	boolean wantsOn;
	byte priority;
	boolean isConnected;
	boolean actualState;
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
}; //HeaterItem

#endif //__HEATERITEM_H__
