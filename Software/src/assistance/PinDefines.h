
#ifndef PIN_DEFINES_H
#define PIN_DEFINES_H

#define PINS_ESP8266
// #define PINS_ESP32

#ifdef PINS_ESP8266

// information LED
#define LED1 D0

// GPS software serial
#define GPS_SOFTWARE_SERIAL_RX_PIN 2
#define GPS_SOFTWARE_SERIAL_TX_PIN 0

// compass software serial
#define COMPASS_SOFTWARE_SERIAL_RX_PIN 5
#define COMPASS_SOFTWARE_SERIAL_TX_PIN 4

// motor pins
#define MOTOR_1_DIRECTION_PIN   14 // EN1
#define MOTOR_1_PWM_PIN         12 // EN2
#define MOTOR_2_DIRECTION_PIN   13 // EN3
#define MOTOR_2_PWM_PIN         15 // EN4



#endif

#ifdef PINS_ESP32

// information LED
#define LED1 0

// GPS software serial
#define GPS_SOFTWARE_SERIAL_RX_PIN 0
#define GPS_SOFTWARE_SERIAL_TX_PIN 0

// compass software serial
#define COMPASS_SOFTWARE_SERIAL_RX_PIN 0
#define COMPASS_SOFTWARE_SERIAL_TX_PIN 0

// motor pins
#define MOTOR_1_DIRECTION_PIN   0 // EN1
#define MOTOR_1_PWM_PIN         0 // EN2
#define MOTOR_2_DIRECTION_PIN   0 // EN3
#define MOTOR_2_PWM_PIN         0 // EN4

#endif

#endif