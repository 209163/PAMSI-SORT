/*
 * inKolejka.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#ifndef INKOLEJKA_H
#define INKOLEJKA_H
class inKolejka{
public:
	inKolejka();
	virtual ~inKolejka();
  virtual void remove()=0;
  virtual void add(int)=0;
  virtual int last ()=0;
  virtual int first ()=0;
};
#endif
