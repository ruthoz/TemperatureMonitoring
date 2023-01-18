#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef INC_DHT_H_
#define INC_DHT_H_


class Dht{
private:

	GPIO_TypeDef * _gpioPort;
	uint16_t _gpioPin;
	TIM_HandleTypeDef * _timer;
	uint8_t _data[5];
	double _temperature;
	double _humidity;

	int waitWhileEqual(int value, int expectedTime);
	void setGpioOutput();
	void setGpioInput();
public:
	Dht( GPIO_TypeDef* gpioPort, uint16_t gpioPin, TIM_HandleTypeDef * timer){
		_gpioPort = gpioPort;
		_gpioPin = gpioPin;
		_timer = timer;
		_temperature = 0.0;
		_humidity = 0.0;
	}
	~Dht(){};
	int read();
	int reciveData();

	double getHumidty();
	double getTemperature();
};

#endif /* INC_DHT_H_ */




