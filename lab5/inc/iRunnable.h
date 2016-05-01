/*
 * irunnable.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

//! \file irunnable.hh zawira interfejs do testowania zaimplementowanych algorytmow
#ifndef IRUN_H
#define IRUN_H
#include "stoper.h"
#include <cstdlib>
class iRunnable
{
private:
  int ileOkrazen;
  int ileDanych;
public:
  iRunnable();
  virtual ~iRunnable();
  virtual void run()=0;
  void prepare(int, int);
  int getIleOkrazen();
  int getIleDanych();

};

#endif
