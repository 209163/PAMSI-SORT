/*
 * kolejka.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#include "kolejka.h"

void kolejka::add(int x)
{
    push (x);
}
void kolejka::remove()
{
  if(isEmpty()==true)
    throw empty();
  else
    zdejmij(0);
}
int kolejka::first()
{
  if(isEmpty()==true)
    throw empty();
  else
    return wyswietl(0);
}
int kolejka::last()
{
  if(isEmpty()==true)
    throw empty();
  else
    return wyswietl(ind());
}
