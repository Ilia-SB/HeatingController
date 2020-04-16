/*
 * Interface.h
 *
 * Created: 15.05.2016 16:24:38
 *  Author: Ivanov
 */ 


#ifndef INTERFACE_H_
#define INTERFACE_H_

#define MQTT_TOTAL_CONSUMPTION       F("total_cons")
#define MQTT_HYSTERESIS              F("hysteresis")
#define MQTT_CONSUMPTION_LIMIT       F("cons_limit")
#define MQTT_EEPROM_ERROR            F("eeprom_err")

#define MQTT_TARGETTEMP              F("trg_temp")
#define MQTT_PRIORITY                F("prio")
#define MQTT_AUTO                    F("auto")
#define MQTT_ON_OFF                  F("on_off")
#define MQTT_SENSOR                  F("sensor")
#define MQTT_PORT                    F("port")
#define MQTT_ADJUST                  F("adjust")
#define MQTT_ENABLED                 F("enabled")
#define MQTT_CONSUMPTION             F("cons")
#define MQTT_TEMP                    F("temp")
#define MQTT_IS_CONNECTED            F("connected")
#define MQTT_ACTUAL_STATE            F("act_state")
#define MQTT_ERROR                   F("error")
#define MQTT_GETSTATE                F("report")

#define CRC_ERROR		1000
#define NO_DATA			1001

#define MODE_HEATER_ON	true
#define MODE_HEATER_OFF	false

#endif /* INTERFACE_H_ */