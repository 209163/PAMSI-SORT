/*
 * lista.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#include "lista.h"

lista::lista() {
	// TODO Auto-generated constructor stub

}

lista::~lista() {
	// TODO Auto-generated destructor stub
}


void lista::add(int x)
{
    push (x);
}
void lista::add(int x, int index)
{
  if(index<=ile_elem)
    przypisz (x, index);
  else
    throw bad_index();
}
void lista::remove(int i)
{
  if(isEmpty()==true)
    throw empty();
  else if(i>ind())
    throw bad_index();
  else
    zdejmij(i);
}
void lista::remove()
{
  if(isEmpty()==true)
    throw empty();
  else
    zdejmij(ind());
}
int lista::get(int i)
{
  if(isEmpty()==true)
    throw empty();
  else if (i>ind())
    throw bad_index();
  else
    return wyswietl(i);
}


