/*
 * IncFile1.h
 *
 * Created: 15.03.2016 17:44:24
 *  Author: Ivanov
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define NUMBER_OF_HEATERS 10
const int pins[NUMBER_OF_HEATERS] = {4,5,6,7,8,9,17,16,15,14}; /*pins that control relays*/

#define SENSOR 2
#define CM_SENSOR	3
#define I2C_ADDRESS 0x01
#define COMMAND_BUFFER_LEN 280
#define RESPONSE_BUFFER_LEN 280
#define DEFAULT_TEMPERATURE 5
#define DEFAULT_TEMPERATURE_ADJUST 0
#define DEFAULT_CONSUMPTION_LIMIT 10000
#define MAX_CONSUMPTION_LIMIT 15000
#define DEFAULT_HYSTERESIS 1
#define PROCESSING_INTERVAL 30000000 /*?s*/
#define OFF_ON_DELAY 2000000 /*?s*/
#define READ_SENSORS_DELAY 1000 /*ms*/

const byte PROGMEM HEATER1[3] =   {0x00, 0x00, 0x00};
const byte PROGMEM HEATER2[3] =	{0x00, 0x00, 0x01};
const byte PROGMEM HEATER3[3] =	{0x00, 0x00, 0x02};
const byte PROGMEM HEATER4[3] =	{0x00, 0x00, 0x03};
const byte PROGMEM HEATER5[3] =	{0x00, 0x00, 0x04};
const byte PROGMEM HEATER6[3] =	{0x00, 0x00, 0x05};
const byte PROGMEM HEATER7[3] =	{0x00, 0x00, 0x06};
const byte PROGMEM HEATER8[3] =	{0x00, 0x00, 0x07};
const byte PROGMEM HEATER9[3] =	{0x00, 0x00, 0x08};
const byte PROGMEM HEATER10[3] = {0x00, 0x00, 0x09};

#define SENSOR_ADDRESS	0
#define IS_ENABLED		8
#define PORT			9
#define IS_AUTO			10
#define IS_ON			11
#define PRIORITY		12
#define TARGET_TEMP		13
#define TEMP_ADJUST		17
#define CONSUMPTION		21
#define UNDEFINED		255

#define HEATER_RECORD_LEN	23 /*bytes*/

#define CONSUMPTION_LIMIT (HEATER_RECORD_LEN * NUMBER_OF_HEATERS)
#define HYSTERESYS (CONSUMPTION_LIMIT + 2)

#define EEPROM_WRITE_DELAY_TIME	5000 /*5 seconds*/

#endif /* CONFIG_H_ */