/*
 * inTablica.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#ifndef INTABLICA_H
#define INTABLICA_H
class inTablica{
public:
	inTablica();
	virtual ~inTablica();
  virtual void push(int)=0;
  virtual void przypisz(int, int)=0;
  virtual void zdejmij(int)=0;
  virtual int size()=0;
  virtual int ind()=0;
  virtual bool isEmpty()=0;
};
#endif
