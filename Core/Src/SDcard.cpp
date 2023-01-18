/*
 * SDcard.cpp
 *
 *  Created on: 18 בדצמ׳ 2022
 *      Author: ADMIN
 */

#include <SDcard.h>

SDcard::SDcard() {
	HAL_Delay(1000);
	_fres = f_mount(&_fatFs, "", 1); //1=mount now
	if (_fres != FR_OK) {
		printf("f_mount error (%i)\r\n", _fres);
		return;
	}
}


