/*
 * stos.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#include "stos.h"

stos::stos() {
	// TODO Auto-generated constructor stub

}

stos::~stos() {
	// TODO Auto-generated destructor stub
}


void stos::add(int x)
{
  push(x);
}
void stos::remove()
{
  if(isEmpty()==true)
    throw empty();
  else
    ile_elem--;
  if(ile_elem<size()/3 && ile_elem<10)
    zmniejsz();
}
int stos::get()
{
  if(isEmpty()==true)
    throw empty();
  else
    return wyswietl(ind());
}
/*
stos::stos(){*NEXT=NULL; ile_elem=0;}

void stos::push(int x)
{
  stos *tmp=new stos;
  if (tmp==NULL)
    throw badalloc();
  else
    {
      tmp.liczba=x;
      tmp.NEXT=this;
      this=tmp;
    }
}
void stos::remove()
{
  if (isEmpty==true)
    throw empty();
  else
    stos *tmp=this;
    this=this.NEXT;
    delete tmp;


  }*/

