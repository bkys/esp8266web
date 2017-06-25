#ifndef _user_config_h_
#define _user_config_h_

#include "sdk/sdk_config.h"

#define SYS_VERSION "0.6.4"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define WEB_DEFAULT_SOFTAP_IP	DEFAULT_SOFTAP_IP // ip 192.168.4.1
#define WEB_DEFAULT_SOFTAP_MASK	DEFAULT_SOFTAP_MASK // mask 255.255.255.0
#define WEB_DEFAULT_SOFTAP_GW	DEFAULT_SOFTAP_IP // gw 192.168.4.1
#define WEB_DEFAULT_STATION_IP    0x3201A8C0 // ip 192.168.1.50
#define WEB_DEFAULT_STATION_MASK  0x00FFFFFF // mask 255.255.255.0
#define WEB_DEFAULT_STATION_GW    0x0101A8C0 // gw 192.168.1.1
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define PROGECT_NUMBER 0
// 0 -> проект "TCP2UART"
// 1 -> проект MODBUS-"RS485"
// 2 -> пустой web
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#if PROGECT_NUMBER == 0
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Конфигурация для проекта TCP2UART
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define USE_WEB		80 // включить в трансляцию порт Web, если =0 - по умолчанию выключен
#define WEBSOCKET_ENA  // включить WEBSOCKET

#define USE_TCP2UART 12345 // включить в трансляцию драйвер TCP2UART, номер порта по умолчанию (=0 - отключен)
#define USE_UART_AJAX // включить в трансляцию ~uart_data~ (для чудаков :) )

#define USE_CPU_SPEED  160 // установить частоту CPU по умолчанию 80 или 160 MHz

#define USE_NETBIOS	1 // включить в трансляцию драйвер NETBIOS, если =0 - по умолчанию выключен.

#define USE_SNTP	1 // включить в трансляцию драйвер SNTP, если =0 - по умолчанию выключен, = 1 - по умолчанию включен.

#define USE_MODBUS	502 // включить в трансляцию Modbus TCP, если =0 - по умолчанию выключен
#define MDB_ID_ESP 50 // номер устройства ESP на шине modbus

#define USE_CAPTDNS	0	// включить в трансляцию NDS отвечающий на всё запросы клиента при соединении к AP модуля
						// указанием на данный WebHttp (http://aesp8266/), если =0 - по умолчанию выключен

#if USE_MAX_IRAM == 48
#define USE_OVERLAY 16384 // включить в трансляцию возможность работы с оверлеями (максимальный размер кода оверлея)
#else
#if DEF_SDK_VERSION >=2000
#define USE_OVERLAY 5850 // включить в трансляцию возможность работы с оверлеями (максимальный размер кода оверлея)
#else
#define USE_OVERLAY 7424 // включить в трансляцию возможность работы с оверлеями (максимальный размер кода оверлея)
#endif
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#elif PROGECT_NUMBER == 1
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Конфигурация для проекта MODBUS-RS-485
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define USE_WEB		80 // включить в трансляцию порт Web, если =0 - по умолчанию выключен
#define WEBSOCKET_ENA // включить WEBSOCKET

#define USE_CPU_SPEED  160 // установить частоту CPU по умолчанию 80 или 160 MHz

#define USE_NETBIOS	1 // включить в трансляцию драйвер NETBIOS, если =0 - по умолчанию выключен.

#define USE_SNTP	1 // включить в трансляцию драйвер SNTP, если =0 - по умолчанию выключен, = 1 - по умолчанию включен.

#ifndef USE_TCP2UART
#define USE_RS485DRV	// использовать RS-485 драйвер
#define MDB_RS485_MASTER // Modbus RTU RS-485 master & slave
#endif
#define USE_MODBUS	502 // включить в трансляцию Modbus TCP, если =0 - по умолчанию выключен
#define MDB_ID_ESP 50 // номер устройства ESP на шине modbus

#define USE_CAPTDNS	0	// включить в трансляцию DNS отвечающий на всё запросы клиента при соединении к AP модуля
						// указанием на данный WebHttp (http://aesp8266/), если =0 - по умолчанию выключен

#if USE_MAX_IRAM == 48
#define USE_OVERLAY 16384 // включить в трансляцию возможность работы с оверлеями (максимальный размер кода оверлея)
#else
#if DEF_SDK_VERSION >=2000
#define USE_OVERLAY 5850 // включить в трансляцию возможность работы с оверлеями (максимальный размер кода оверлея)
#else
#define USE_OVERLAY 7424 // включить в трансляцию возможность работы с оверлеями (максимальный размер кода оверлея)
#endif
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#elif PROGECT_NUMBER == 2
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Конфигурация для проекта WEB+WEBSOCEK
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define USE_WEB		80 // включить в трансляцию порт Web, если =0 - по умолчанию выключен
//#define WEBSOCKET_ENA // включить WEBSOCKET
//#define USE_NETBIOS	1 // включить в трансляцию драйвер NETBIOS, если =0 - по умолчанию выключен.
#define USE_SNTP	1 // включить в трансляцию драйвер SNTP, если =0 - по умолчанию выключен, = 1 - по умолчанию включен.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif // PROGECT_NAME

#if DEBUGSOO > 0
#if !(defined(USE_RS485DRV) || defined(USE_TCP2UART))
// #define USE_GDBSTUB // UDK пока не поддерживает GDB
#endif
#endif



#endif // _user_config_h_


