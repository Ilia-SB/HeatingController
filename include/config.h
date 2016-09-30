/*
 * IncFile1.h
 *
 * Created: 15.03.2016 17:44:24
 *  Author: Ivanov
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define NUMBER_OF_HEATERS 14
const int pins[NUMBER_OF_HEATERS] = {4,5,6,7,8,9,17,16,15,14,13,12,11,10}; /*pins that control relays*/

#define SENSOR 2
#define CM_SENSOR	3
#define I2C_ADDRESS 0x01
#define COMMAND_BUFFER_LEN 128
#define RESPONSE_BUFFER_LEN 128
#define DEFAULT_TEMPERATURE 5
#define DEFAULT_TEMPERATURE_ADJUST 0
#define DEFAULT_CONSUMPTION_LIMIT 6000
#define DEFAULT_HYSTERESIS 1
#define PROCESSING_INTERVAL 30000000 /*?s*/
#define OFF_ON_DELAY 2000000 /*?s*/
#define READ_SENSORS_DELAY 1000 /*ms*/

const byte HEATER1[3] = {0x00, 0x00, 0x00};
const byte HEATER2[3] =	{0x00, 0x00, 0x01};
const byte HEATER3[3] =	{0x00, 0x00, 0x02};
const byte HEATER4[3] =	{0x00, 0x00, 0x03};
const byte HEATER5[3] =	{0x00, 0x00, 0x04};
const byte HEATER6[3] =	{0x00, 0x00, 0x05};
const byte HEATER7[3] =	{0x00, 0x00, 0x06};
const byte HEATER8[3] =	{0x00, 0x00, 0x07};
const byte HEATER9[3] =	{0x00, 0x00, 0x08};
const byte HEATER10[3] = {0x00, 0x00, 0x09};
const byte HEATER11[3] = {0x00, 0x00, 0x0A};
const byte HEATER12[3] = {0x00, 0x00, 0x0B};
const byte HEATER13[3] = {0x00, 0x00, 0x0C};
const byte HEATER14[3] = {0x00, 0x00, 0x0D};
	
#define SENSOR_ADDRESS	0
#define IS_ENABLED		8
#define PORT			9
#define IS_AUTO			10
#define IS_ON			11
#define PRIORITY		12
#define TARGET_TEMP		13
#define TEMP_ADJUST		17
#define CONSUMPTION		21

#define HEATER_RECORD_LEN	23 /*bytes*/

#define CONSUMPTION_LIMIT (HEATER_RECORD_LEN * NUMBER_OF_HEATERS)
#define HYSTERESYS (CONSUMPTION_LIMIT + 2)

#endif /* CONFIG_H_ */