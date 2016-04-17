/*
 * tablica.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#include "tablica.h"

tablica::tablica(int n)
{
	tab=new int[rozmiar];
	rozmiar=n;
	ile_elem=0;
}

tablica::tablica()
{
	tab=new int[rozmiar];
	rozmiar=10;
	ile_elem=0;
}
void tablica::push(int dana)
{
  if(ile_elem<size())
    this->tab[ile_elem]=dana;//dopisuje dana na pierwsze wolne miejsce tablicy
  else
    zwieksz(dana);
  this->ile_elem++; //nalicza ilosc zapisanych danych
}
void tablica::zwieksz(int dana)
{
  //std::cout<<"zwiekszam "<<i<<std::endl;
  int p=rozmiar;     // zmienna pomocnicza, zapamietuje poprzedni rozmiar tab.
  this->rozmiar=rozmiar*2;       // nowy rozmiar tablicy
  int *tmp= new int[rozmiar];   //tworzy tablice tymczasowa
  for(int j=0; j<p; j++)
    tmp[j]=tab[j];   //kopiuje zawartosc tablicy
  delete[] tab;     //zwalnia tablice
  tmp[ile_elem]=dana;     //dopisuje dana na pierwsze wolne miejsce tablicy
  this->tab=tmp;  //przypisuje tablice tymczasowowa do tablicy orginalnej
}
void tablica::przypisz(int dana, int miejsce)
{
  if(miejsce==ile_elem)
    this->tab[miejsce]=dana;
  else
    {
      for(int i=ile_elem; i>miejsce; i--)
	{
	  tab[i]=tab[i-1];
	}
      tab[miejsce]=dana;
    }
}
void tablica::zdejmij(int index)
{
  if(index==ind())
    {
      ile_elem--;
    }
  else if(index>ind() || index<0)
    throw bad_index();
  else
    {
      for(int i=index; i<ind(); i++)
	{tab[i]=tab[i+1];}
      ile_elem--;
    }
  if (ile_elem<size()/3)
    zmniejsz();
}
void tablica::zmniejsz()
{
  this->rozmiar=rozmiar/2;       // nowy rozmiar tablicy
  int *tmp= new int[rozmiar];   //tworzy tablice tymczasowa
  for(int j=0; j<ile_elem; j++)
    tmp[j]=tab[j];   //kopiuje zawartosc tablicy
  delete[] tab;     //zwalnia pamiec
  this->tab=tmp;  //przypisuje tablice tymczasowowa do tablicy orginalnej
}
void tablica::bubblesort()
{
  int tmp;
  for(int i=0; i< ind(); i++)
    {
      for(int j=0; j<ind(); j++)
	{
	  if(tab[i]>tab[i+1])
	    {
	      tmp=tab[i];
	      this->tab[i]=tab[i+1];
	      this->tab[i+1]=tmp;
	    }
	}
    }
}
