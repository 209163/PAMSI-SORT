/*!
\file
\brief plik zawiera klase tablica
*/
//_________________________________________________________________//
#ifndef TABLICA_H
#define TABLICA_H
#include <iostream>
#include "inTablica.h"
using namespace std;
//_________________________________________________________________//
/*!
\brief Klasa tablica
Klasa ma w swoim skladzie metody sluzace do zarzadzania tablica dynamiczna uzywane przez inne typy danych, moze byc tez uzywana samodzielnie*/
template <class typ>
class tablica: public inTablica<typ>{
private:
  typ *tab;
  //! \brief zwieksza ilosc zaalokowanej pamieci
  void zwieksz(typ);
  int rozmiar;
public:
  int ile_elem; //ToDo: przerobic klasy tak by ile_elem i zmniejsz() byly prywatne
  //! \brief zmniejsza ilosc zaalokowanej pamieci
  void zmniejsz();

  //! \brief konstruktor bezparametryczny, tworzy tablice o 10 polach
  tablica() {rozmiar=10; ile_elem=0; tab=new typ[rozmiar];}

  //! \brief konstruktor, tworzy tablice o podanej przez urzytkownika ilosci pol
  tablica(int n) {rozmiar=n; ile_elem=0; tab=new typ[rozmiar];}

  //void podaj_roz(int M){ this->rozmiar=M;}
  typ get(int n) {return tab[n];}

  void push(typ);
  void przypisz(typ, int);
  void zdejmij(int);

  //! \brief sortowanie bombelkowe
  void bubblesort();

  int size() {return rozmiar;}
  int ind(){return ile_elem-1;}
  bool isEmpty() {if(ile_elem!=0) return false; else return true;}

  //! \brief obiekt zwracany podczas wystapienia wyjatku wystepujacego gdy nastapi proba odzialywania na dane ktorych kontener nie posiada
  class empty{};

   //! \brief obiekt zwracany podczas wystapienia wyjatku wystepujacego gdy nastapi odwolanie do danych o zlym indeksie
  class bad_index{};
};
//_________________________________________________________________//
template <class typ>
void tablica<typ>::push(typ dana)
{
  if(ile_elem<size())
    {
      this->tab[ile_elem]=dana;//dopisuje dana na pierwsze wolne miejsce tablicy
    }
  else
    {
      zwieksz(dana);
    }
  this->ile_elem++; //nalicza ilosc zapisanych danych
}
//_________________________________________________________________//
template <class typ>
void tablica<typ>::zwieksz(typ dana)
{
  //std::cout<<"zwiekszam "<<i<<std::endl;
  int p=rozmiar;     // zmienna pomocnicza, zapamietuje poprzedni rozmiar tab.
  this->rozmiar=rozmiar*2;       // nowy rozmiar tablicy
  typ *tmp= new typ[rozmiar];   //tworzy tablice tymczasowa
  for(int j=0; j<p; j++)
    tmp[j]=tab[j];   //kopiuje zawartosc tablicy
  delete[] tab;     //zwalnia tablice
  tmp[ile_elem]=dana;     //dopisuje dana na pierwsze wolne miejsce tablicy
  this->tab=tmp;  //przypisuje tablice tymczasowowa do tablicy orginalnej
}
//_________________________________________________________________//
template <class typ>
void tablica<typ>::przypisz(typ dana, int miejsce)
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
//_________________________________________________________________//
template <class typ>
void tablica<typ>::zdejmij(int index)
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
//_________________________________________________________________//
template <class typ>
void tablica<typ>::zmniejsz()
{
  this->rozmiar=rozmiar/2;       // nowy rozmiar tablicy
  typ *tmp= new typ[rozmiar];   //tworzy tablice tymczasowa
  for(int j=0; j<ile_elem; j++)
    tmp[j]=tab[j];   //kopiuje zawartosc tablicy
  delete[] tab;     //zwalnia pamiec
  this->tab=tmp;  //przypisuje tablice tymczasowowa do tablicy orginalnej
}
//_________________________________________________________________//
template <class typ>
void tablica<typ>::bubblesort()
{
  typ tmp;
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
  cout<<"posortowano!:)"<<endl;
}
#endif
