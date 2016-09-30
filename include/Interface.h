/*
 * Interface.h
 *
 * Created: 15.05.2016 16:24:38
 *  Author: Ivanov
 */ 


#ifndef INTERFACE_H_
#define INTERFACE_H_

#define BEGINTRANSMISSION 0xAA
#define ENDTRANSMISSION 0x3B

#define SETTARGETTEMP	0x01	//0x01 HEA TER ADDR TARGETTEMP CRC		01 00 00 01 19 1B ;	1B=01+00+01+19	0x19=25 degrees
#define SETPRIORITY		0x02	//0x02 HEA TER ADDR PRIORITY CRC		02 00 00 01 01 04 ;
#define SETAUTO			0x03	//0x03 HEA TER ADDR AUTO CRC			03 00 00 01 00 04 ;
#define SETONOFF		0x04	//0x04 HEA TER ADDR ONOFF CRC			04 00 00 01 00 05 ;
#define SETSENSOR		0x05	//0x05 HEA TER ADDR SENSOR CRC			05 00 00 01 28 30 C5 B8 00 00 00 8E 09 ;
#define SETPORT			0x06	//0x06 HEA TER ADDR PORT CRC			0F 00 00 01 02 12 ;
#define SETADJUST		0x07	//0x07 HEA TER ADDR SIGN TEMP FRACTION CRC
#define SETENABLED		0x08	//0x08 HEA TER ADDR ENABLED CRC
#define SETCONSUMPTION	0x09	

#define REPORTSETTARGETTEMP	0x41
#define REPORTSETPRIORITY	0x42
#define REPORTSETAUTO		0x43
#define REPORTSETONOFF		0x44
#define REPORTSETSENSOR		0x45
#define REPORTSETPORT		0x46
#define REPORTSETADJUST		0x47
#define REPORTSETENABLED	0x48
#define REPORTSETCONSUMPTION 0x49

#define GETTEMP				0x11	//0x11 HEA TER ADDR CRC
#define GETSTATE			0x12	//0X12 HEA TER ADDR CRC
#define GETCONSUMPTIONLIMIT	0x13
#define GETHYSTERESIS		0x14
#define GETTOTALCONSUMPTION 0x15
#define GETACTUALSTATE		0x16

#define REPORTTEMP					0X21	//0x21 HEA TER ADDR SIGN TEMP FRACTION CRC	21 00 00 01 00 14 0F 04 ;	(0x14=20 0x0F=0.15) = 20.15 degrees
#define REPORTSTATE					0X22	//0x22 HEA TER ADDR PORT SENSOR AUTO ONOFF ACTSTATE PRIORITY TARGETTEMP SIGN TEMP FRACTION ADJSIGN ADJ ADJFRACTION CRC
#define REPORTCONSUMPTIONLIMIT		0x23	//0x23 CON SUM PTI ON CRC
#define REPORTHYSTERESIS			0x24
#define REPORTTOTALCONSUMPTION		0x25
#define REPORTACTUALSTATE			0x26

#define SETCONSUMPTIONLIMIT	0x31	//0x31 LIMIT LIMIT CRC
#define SETHYSTERESIS		0x32	//0x32	HYSTERESIS CRC

#define EEPROMERROR			0x50	//0x50 HEA TER ADDR CRC
#define TEMPREADERROR		0x51	//0x51 HEA TER ADDR CRC

#define DEBUGINFO			0x60

#define CRC_ERROR		1000
#define NO_DATA			1001

#define MODE_HEATER_ON	true
#define MODE_HEATER_OFF	false

#endif /* INTERFACE_H_ */