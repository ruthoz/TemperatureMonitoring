/*
 * File.cpp
 *
 *  Created on: Nov 29, 2022
 *      Author: student
 */

#include <File.h>

File::File(const char* nameFile) {
	strcpy(_nameFile, nameFile);
}

void File::read(){
	_fres = f_open(&_fil, _nameFile, FA_READ);
	if (_fres != FR_OK) {
		printf("f_open error (%i)\r\n", _fres);
		return;
	}
	//Read 250 bytes from "file" on the SD card
	 BYTE readBuf[256];

	//We can either use f_read OR f_gets to get data out of files
	//f_gets is a wrapper on f_read that does some string formatting for us
	TCHAR* rres = f_gets((TCHAR*)readBuf, 256, &_fil);
	if(rres == 0){
		printf("f_gets error (%i)\r\n", _fres);
	}
	while(rres != 0) {
		rres = f_gets((TCHAR*)readBuf, 256, &_fil);
		printf("%s\r\n", readBuf);
	}

	//Be a tidy kiwi - don't forget to close your file!
	f_close(&_fil);


}

void File::write(const char* writeBuf){
	//write a file "write.txt"
	_fres = f_open(&_fil, _nameFile, FA_WRITE | FA_OPEN_APPEND | FA_OPEN_EXISTING);
	if(_fres == FR_OK) {
    	//printf("I was able to open 'write.txt' for writing\r\n");
	} else {
		printf("f_open error (%i)\r\n", _fres);
    }

	UINT bytesWrote;
	_fres = f_write(&_fil, writeBuf, strlen(writeBuf), &bytesWrote);
	if(_fres == FR_OK) {
		//printf("Wrote %i bytes to '%s'!\r\n", bytesWrote, _nameFile);
	} else {
		printf("f_write error (%i)\r\n", _fres);
	}

	 //Be a tidy kiwi - don't forget to close your file!
	f_close(&_fil);
}

void File::clear(){

	//write a file "write.txt"
	_fres = f_open(&_fil, _nameFile, FA_CREATE_ALWAYS);
	if(_fres == FR_OK) {
     //printf("I was able to open 'write.txt' for writing\r\n");
	} else {
		printf("f_open error (%i)\r\n", _fres);
    }
	 //Be a tidy kiwi - don't forget to close your file!
	f_close(&_fil);
}

