/* 
* CommBuffer.h
*
* Created: 15.03.2016 18:24:01
* Author: Ivanov
*/


#ifndef __COMMBUFFER_H__
#define __COMMBUFFER_H__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Interface.h"

class CommBuffer
{
//variables
public:
	bool commandReceived;
	bool bufferOverflow;
protected:
private:
	int position, size, commandsStored;
	bool receivingCommand = false;
	uint8_t* array;
//functions
public:
	CommBuffer(int);
	~CommBuffer();
	void addChar(int);
	void clearBuffer();
	void getCommand(uint8_t *buffer, int *len);
	int getLength();
protected:
private:
	CommBuffer( const CommBuffer &c );
	CommBuffer& operator=( const CommBuffer &c );
}; //CommBuffer

#endif //__COMMBUFFER_H__
