/*
 * IncFile1.h
 *
 * Created: 11.04.2016 16:25:32
 *  Author: Ivanov
 */ 


#ifndef EEPROMANYTHING_H_
#define EEPROMANYTHING_H_

#include <Arduino.h>  // for type definitions
#include "EEPROM.h"

template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
	const byte* p = (const byte*)(const void*)&value;
	unsigned int i;
	for (i = 0; i < sizeof(value); i++) {
		if (EEPROM.read(ee) != *p) {
			EEPROM.write(ee++, *p++);
		}
	}
	return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
	byte* p = (byte*)(void*)&value;
	unsigned int i;
	for (i = 0; i < sizeof(value); i++)
	*p++ = EEPROM.read(ee++);
	return i;
}



#endif /* EEPROMANYTHING_H_ */