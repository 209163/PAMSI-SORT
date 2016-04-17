/*
 * inStos.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#ifndef INSTOS_HH
#define INSTOS_HH
class inStos{
public:
	inStos();
	virtual ~inStos();
  virtual void remove()=0;
  virtual void add(int)=0;
  virtual int get ()=0;
};
#endif
