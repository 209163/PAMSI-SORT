/*!
\file
\brief plik zawiera klase lista, ktora jest oparta na jednowymiarowej tablicy dynamicznej
*/
#ifndef LISTA_H
#define LISTA_H
#include "tablica.h"
#include "inLista.h"
template <class typ>
class lista: public inLista<typ>, public tablica<typ>{
protected:
  tablica<typ> *Tab;
public:
  //! konstruktor bezparametryczny
  lista();
  virtual ~lista();
  void remove(int);
  void remove();
  void add(typ, int);
  void add(typ);
  typ get (int);
  bool isEmpty();
  int size();


    //! \brief obiekt zwracany podczas wystapienia wyjatku wystepujacego gdy nastapi proba odzialywania na dane ktorych kontener nie posiada
  class empty{};

   //! \brief obiekt zwracany podczas wystapienia wyjatku wystepujacego gdy nastapi odwolanie do danych o zlym indeksie
  class bad_index{};
};

#endif
