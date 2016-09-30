/*
 * DebugPrint.h
 *
 * Created: 14.09.2016 16:43:29
 *  Author: Ivanov
 */ 


#ifndef DEBUGPRINT_H_
#define DEBUGPRINT_H_


#ifdef DEBUG
#define DEBUG_PRINT(x)			Serial.write(BEGINTRANSMISSION);Serial.write(DEBUGINFO);Serial.print (x);Serial.write(ENDTRANSMISSION)
#define DEBUG_PRINTDEC(x)		Serial.write(BEGINTRANSMISSION);Serial.write(DEBUGINFO);Serial.print (x, DEC);Serial.write(ENDTRANSMISSION)
#define DEBUG_PRINTHEX(x)		Serial.write(BEGINTRANSMISSION);Serial.write(DEBUGINFO);Serial.print (x, HEX);Serial.write(ENDTRANSMISSION)
#define DEBUG_PRINTLN(x)		Serial.write(BEGINTRANSMISSION);Serial.write(DEBUGINFO);Serial.println (x);Serial.write(ENDTRANSMISSION)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTDEC(x)
#define DEBUG_PRINTLN(x)
#endif



#endif /* DEBUGPRINT_H_ */