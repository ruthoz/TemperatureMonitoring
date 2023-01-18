/*
 * Flash.h
 *
 *  Created on: 17 Nov 2022
 *      Author: student
 */
#include "main.h"
#include "MyMain.h"

#ifndef FLASH_H_
#define FLASH_H_


class Flash
{
private:
	uint32_t _flashStartAddess = 0x0800000;
	uint32_t _pageSize = 2048;
	uint32_t _flashAdd;
	uint32_t _page;
	uint32_t _bank;
public:

	Flash(uint32_t address){
		_flashAdd = address;
		_page = ((_flashAdd-_flashStartAddess)/_pageSize);
		_bank = _page < 256 ?  FLASH_BANK_1 : FLASH_BANK_2;
	}
	~Flash(){};

	void erase();
	void writh( void* data);
	void read();
};

#endif /* FLASH_H_ */





