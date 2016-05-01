/*
 * irunnable.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#include "iRunnable.h"

iRunnable::iRunnable() {
	ileOkrazen=10;
	ileDanych=100000000;

}

iRunnable::~iRunnable() {

}


int iRunnable::getIleOkrazen()
{
	return ileOkrazen;
}

int iRunnable::getIleDanych()
{
	return ileDanych;
}
