/*!
\file
\brief plik zawiera interfejs uzywany w listach
*/
#ifndef INLISTA_H
#define INLISTA_H
template <class typ> class inLista{
public:
	inLista();
	virtual ~inLista();
  //! \brief usuwa dana o podanym indeksie, a nastepnie przestawia zmienne
  virtual void remove(int)=0;
  //! \brief usuwa ostatnia dana w kolejce
  virtual void remove()=0;
  //! \brief dodaje dana na miejscu o podanym indeksie, jezeli nie moze byc tam wstawiona zglosi wyjatek, gdy miejsce jest zajete przestawia dane
  virtual void add(typ, int)=0;
  //! \brief dodaje dana na koniec listy
  virtual void add(typ)=0;
  //! \brief zwraca wartosc na podanym indeksie, jezeli nie moze tego zrobic, zwroci wyjatek
  virtual typ get (int)=0;
  //! \brief zwraca wartosc true gdy lista jest pusta lub false gdy jest na niej przynajmniej jeden element
  virtual bool isEmpty()=0;
  //! \brief zwraca liczbe elementow na stosie
  virtual int size()=0;

};
#endif
