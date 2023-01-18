/*
 * SDcard.h
 *
 *  Created on: 18 בדצמ׳ 2022
 *      Author: ADMIN
 */
#include "main.h"
#include "fatfs.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h> //for va_list var arg functions

#ifndef INC_SDCARD_H_
#define INC_SDCARD_H_

class SDcard {
private:
	FATFS _fatFs; 	//Fatfs handle
	FRESULT _fres; //Result after operations
public:
	SDcard();
	~SDcard(){};
};

#endif /* INC_SDCARD_H_ */
