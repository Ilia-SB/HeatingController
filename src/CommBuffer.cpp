/* 
* CommBuffer.cpp
*
* Created: 15.03.2016 18:24:01
* Author: Ivanov
*/


#include "CommBuffer.h"

// default constructor
CommBuffer::CommBuffer(int len)
{
	array = new uint8_t[len];
	size = len;
	commandReceived = false;
	commandsStored = 0;
	position = 0;
} //CommBuffer

// default destructor
CommBuffer::~CommBuffer()
{
	delete[] array;
} //~CommBuffer

void CommBuffer::addChar(int c)
{
	if ((uint8_t)c == BEGINTRANSMISSION) {
		if (!receivingCommand) {
			receivingCommand = true;
			return;
		}
	}
	
	if (receivingCommand) {
		if ((char)c == ';') { //if command terminator found
			commandReceived = true; /*raise commandReceived flag*/
			receivingCommand = false;
			commandsStored++;
		}
	
		if (position < size) /*is there's still room*/
		{
			memcpy(array + position, &c, 1); /*Add character to buffer*/
			position++; /*increment buffer position*/
		} else {
			bufferOverflow = true; /*raise bufferOverflow flag*/
		}
	}
}

void CommBuffer::clearBuffer()
{
	position = 0;
	commandReceived = false;
}

void CommBuffer::getCommand(uint8_t *buffer, int *len)
{
	if (commandReceived) {
		int separatorPos = 0;
		bool separatorFound = false;
		for (int i=0; i<position; i++) {
			if(array[i]==';') {
				separatorFound = true;
				separatorPos = i;
				break;
			}
		}
		
		if (separatorFound) {
			if (*len >= separatorPos+1) { //if command fits the buffer supplied
				memcpy(buffer, array, separatorPos); //copy command to buffer
				buffer[separatorPos] = '\0'; //replace separator by string end
				*len = separatorPos;
			} else { //otherwise discard it
				*len=0;
			}
			memcpy(array, array+separatorPos+1, position-separatorPos-1); //shift the buffer to the left removing the processed command
			position = position - separatorPos - 1; //update write position in the buffer
			commandsStored--;
			if(commandsStored == 0) {
				commandReceived = false;
			}
			return;
			
		}
	} else {
		*len = 0;
		return;
	}
}

int CommBuffer::getLength()
{
	return position;
}