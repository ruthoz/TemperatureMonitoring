/*
 * handleCommand.c
 *
 *  Created on: Jul 3, 2022
 *      Author: student
 */

#ifndef INC_HANDLECOMMAND_C_
#define INC_HANDLECOMMAND_C_

#include "main.h"
#include "CliContainer.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "cmsis_os.h"

typedef void(*HandlerFunc)(void* , char*);

struct Comand
{
	char* comandName;
	char* stateComand;
	HandlerFunc comandPointer;
	void* object;
};


int Communication_commTask();
void Communication_handleCommand();
void Communication_registerCommand(char* comandName, char* stateComand, HandlerFunc comandPointer, void* object);

#endif /* INC_HANDLECOMMAND_C_ */
