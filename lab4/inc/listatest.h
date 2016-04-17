/*
 * listatest.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

/*!
\file
\brief plik zawiera klase listatest
*/
#ifndef LISTA_H
#define LISTA_H
#include "tablicatest.h"
#include "inLista.h"
#include "iRunnable.h"
#include "stoper.h"
class listatest: public tablicatest, public inLista, public stoper{
public:
  listatest();
  virtual ~listatest();
  void run();
};

#endif
