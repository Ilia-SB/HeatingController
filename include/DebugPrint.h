/*
 * DebugPrint.h
 *
 * Created: 14.09.2016 16:43:29
 *  Author: Ivanov
 */ 


#ifndef DEBUGPRINT_H_
#define DEBUGPRINT_H_


#ifdef DEBUG
#define DEBUG_PRINT(x)			Serial.print (x)
#define DEBUG_PRINTDEC(x)		Serial.print (x, DEC)
#define DEBUG_PRINTHEX(x)		Serial.print (x, HEX)
#define DEBUG_PRINTLN(x)		Serial.println (x)
#define DEBUG_MEMORY()          Serial.println();Serial.print(F("!!! Free memory: "));Serial.print(freeMemory());Serial.println(F(" !!!"));Serial.println();
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTDEC(x)
#define DEBUG_PRINTHEX(x)
#define DEBUG_PRINTLN(x)
#endif



#endif /* DEBUGPRINT_H_ */