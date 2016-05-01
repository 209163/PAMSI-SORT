/*
 * tablicatest.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

#include "tablicatest.h"
#include <string>
using namespace std;

template <class typ>
tablicatest<typ>::tablicatest() {
	tab=new int[rozmiar];
	rozmiar=10;
	ile_elem=0;

}

template <class typ>
tablicatest<typ>::tablicatest(int n) {
	tab=new int[rozmiar];
	rozmiar=n;
	ile_elem=0;

}

template <class typ>
tablicatest<typ>::~tablicatest() {

}

template <class typ>
void tablicatest<typ>::push(int dana)
{
  if(ile_elem<size())
    this->tab[ile_elem]=dana;//dopisuje dana na pierwsze wolne miejsce tablicy
  else
    zwieksz(dana);
  this->ile_elem++; //nalicza ilosc zapisanych danych
}

template <class typ>
void tablicatest<typ>::zwieksz(int dana)
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

template <class typ>
void tablicatest<typ>::przypisz(int dana, int miejsce)
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

template <class typ>
void tablicatest<typ>::zdejmij(int index)
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

template <class typ>
void tablicatest<typ>::zmniejsz()
{
  this->rozmiar=rozmiar/2;       // nowy rozmiar tablicy
  int *tmp= new int[rozmiar];   //tworzy tablice tymczasowa
  for(int j=0; j<ile_elem; j++)
    tmp[j]=tab[j];   //kopiuje zawartosc tablicy
  delete[] tab;     //zwalnia pamiec
  this->tab=tmp;  //przypisuje tablice tymczasowowa do tablicy orginalnej
}

template <class typ>
void tablicatest<typ>::bubblesort()
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

template <class typ>
void tablicatest<typ>::run()
{
  //stoper s;
  string dane="tablica";
  for(int j=0; j<getIleOkrazen(); j++)
    {
      for(int i=10; i<getIleDanych(); i=i*10)
	{
	  //s.start();
	  for(int i=0;i<=ile_elem; i++)
	    push(i);
	  //s.stop();
	  //std::cout<<s.getTime()<<std::endl;
	  //  s.getElapsedTime();
	  //s.dumpToFile(dane);
	}
    }
}