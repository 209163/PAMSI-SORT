/*
 * lista.cpp
 *
 *  Created on: 27 kwi 2016
 *      Author: paula
 */

#include "lista.h"

template <class typ>
lista<typ>::lista() {
	Tab=new tablica<typ>;

}

template <class typ>
lista<typ>::~lista() {

}


//====================================================================//
template <class typ>
void lista<typ>::add(typ x)
{
    Tab->push (x);
}
//====================================================================//
template <class typ>
void lista<typ>::add(typ x, int index)
{
  if(index<Tab->ind())
    Tab->przypisz (x, index);
  else
    throw bad_index();
}
//====================================================================//
template <class typ>
void lista<typ>::remove(int i)
{
  if(Tab->isEmpty()==true)
    throw empty();
  else if(i>Tab->ind())
    throw bad_index();
  else
    Tab->zdejmij(i);
}
//====================================================================//
template <class typ>
void lista<typ>::remove()
{
  if(Tab->isEmpty()==true)
    throw empty();
  else
    Tab->zdejmij(Tab->ind());
}
//====================================================================//
template <class typ>
typ lista<typ>::get(int i)
{
  if(Tab->isEmpty()==true)
    throw empty();
  else if (i>Tab->ind())
    throw bad_index();
  else
    return Tab->get(i);
}
//====================================================================//
template <class typ>
bool lista<typ>::isEmpty()
{
  return Tab->isEmpty();
}
//=============================================================//
template <class typ>
int lista<typ>::size()
{
  return Tab->ind()+1;
}
//=============================================================//
