/*
 * lista.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

/*!
\file
\brief plik zawiera klase lista
*/
#ifndef LISTA_H
#define LISTA_H
#include "tablica.h"
#include "inLista.h"
class lista: public tablica, public inLista{
public:
  lista();
  virtual ~lista();
  void remove(int); //! \brief usuwa dana o podanym indeksie, a nastepnie przestawia zmienne
  void remove();  //! \brief usuwa ostatnia dana w kolejce
  void add(int, int); //! \brief dodaje dana na miejscu o podanym indeksie, jezeli nie moze byc tam wstawiona zglosi wyjatek, gdy miejsce jest zajete przestawia dane
  void add(int); //! \brief dodaje dana na koniec listy
  int get (int); //! \brief zwraca wartosc na podanym indeksie, jezeli nie moze tego zrobic, zwroci wyjatek
};

#endif
