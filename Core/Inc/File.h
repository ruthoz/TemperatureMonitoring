/*
 * File.h
 *
 *  Created on: Nov 29, 2022
 *      Author: student
 */
#include "main.h"
#include "fatfs.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h> //for va_list var arg functions

#ifndef INC_FILE_H_
#define INC_FILE_H_

class File {
private:
	FIL _fil; 		//File handle
	FRESULT _fres; //Result after operations
	char _nameFile [20];
	DWORD _free_clusters, _free_sectors, _total_sectors;

public:
	File(const char* nameFile);
	~File(){};

	void read();
	void write(const char* writeBuf);
	void clear();
};

#endif /* INC_FILE_H_ */
