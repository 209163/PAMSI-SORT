/*
 * tablicatest.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

/*!
\file
\brief plik zawiera klase tablicatest
*/
#ifndef TABLICATEST_H
#define TABLICATEST_H
#include "inTablica.h"
#include "iRunnable.h"
class tablicatest: public inTablica, public iRunnable{
/*!
\brief Klasa tablicatest

Klasa testowa*/
private:
  int *tab;
  void zwieksz(int);//! \brief zwieksza ilosc zaalokowanej pamieci
  int rozmiar;
public:
  int ile_elem;
  void zmniejsz();//! \brief zwieksza ilosc zaalokowanej pamieci
  tablicatest(); //! \brief konstruktor bezparametryczny, tworzy tablice o 10 polach
  tablicatest(int n); //! \brief konstruktor, tworzy tablice o podanej przez urzytkownika ilosci pol
  virtual ~tablicatest();
  //void podaj_roz(int M){ this->rozmiar=M;}
  //int wyswietl(int n) {return tab[n];}
  void push(int); //! \brief metoda dodajaca dana na ostatnie wolne miejsce tablicy
  void przypisz(int, int); //! \brief przypisuje podana dana na konkretnym miejscu tablicy, pierwszym parametrem jest dana, a drugim miejsce na ktorym ma byc zapisana
  void zdejmij(int); //! \brief usuwa ostatni element tablicy
  void bubblesort(); //! \brief sortowanie bombelkowe
  int size() {return rozmiar;} //! \brief metoda zwraca ilosc zaalokowanego miejsca
  int ind(){return ile_elem-1;} //! \brief metoda zwraca ideks na ktorym jest ostatnia dana w kontenerze
  bool isEmpty() {if(ile_elem!=0) return false; else return true;} //! \brief metoda sprawdza czy kontener jest pusty
  class empty{};//! \brief obiekt zwracany podczas wystapienia wyjatku wystepujacego gdy nastapi proba odzialywania na dane ktorych kontener nie posiada
  class bad_index{}; //! \brief obiekt zwracany podczas wystapienia wyjatku wystepujacego gdy nastapi odwolanie do danych o zlym indeksie
  void run();
};
#endif
