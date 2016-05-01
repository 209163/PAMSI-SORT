/*!
\file
\brief plik zawiera szablon klasy lista2s, ktora jest zbudowana jak klasyczna lista
*/
#ifndef LISTA2s_HH
#define LISTA2s_HH
#include "inLista.h"
#include "StrListyT.h"
template <class typ> class lista2s
{
protected:
  StrListyT <typ> *FIRST;
  StrListyT <typ> *LAST;
  int rozmiar;
public:
  //! konstruktor bezparametryczny
  lista2s(){FIRST=LAST=NULL; rozmiar=0;};
  virtual ~lista2s();
  void remove(int);
  void remove();
  void add(typ , int);
  void addLast(typ);
  void add(typ);
  typ get (int);
  bool isEmpty();
  int size();
  int find(typ);
  StrListyT<typ> getFirst();
  StrListyT<typ> getLast();
  void quicksort(StrListyT<typ> *pLeft, StrListyT<typ> *pRight);
  class bad_index{};
  class empty{};
};
//-------------------------------------------------//
//template <class typ>
//lista2s<typ>::lista2s<typ>(){FIRST=NULL; rozmiar=0;}
//-------------------------------------------------//
template <class typ>
lista2s<typ>::~lista2s()
{

}


template <class typ>
void lista2s<typ>::addLast(typ x)
{
  StrListyT <typ> *NEW  = new StrListyT<typ>;
  NEW->dana=x;
  NEW->NEXT=FIRST;
  FIRST->PREV=NEW;
  NEW=LAST;
  FIRST=NEW;

  this->rozmiar++;
  }
//-------------------------------------------------//
template <class typ>
void lista2s<typ>::add(typ x)
{
	//nowa lista
	StrListyT<int> *NEW = new StrListyT<int>;

	NEW->dana = x;
	//jezeli to pierwszy elem
	if (FIRST == NULL)
	{
		FIRST = LAST = NEW;
		NEW->NEXT = NEW->PREV = NULL;
	}
	else
	{
		//dodaje na koniec
		LAST->NEXT = NEW;
		NEW->PREV = LAST;
		LAST = NEW;
		NEW->NEXT = NULL;
		this->rozmiar++;
	}
}

//-------------------------------------------------//
template <class typ>
void lista2s<typ>::add(typ x, int i)
{
  if(i==rozmiar)
    addLast(x);
  else if(i<rozmiar)
    {
      StrListyT <typ> *NEW=new StrListyT <typ>;
      StrListyT <typ> *tmp= FIRST;
      NEW=FIRST;
      for(int j=0; j+1!=i;j++)
	tmp=tmp->NEXT;
      NEW->dana=x;
      NEW->NEXT=tmp;
      tmp->NEXT=NEW;
      this->rozmiar++;
    }
  else
    throw bad_index();
}
//-------------------------------------------------//
template <class typ>
void lista2s<typ>::remove(int i)
{
  if(rozmiar==0)
    throw empty();
  else if(i>rozmiar)
    throw bad_index();
  else
    {
      StrListyT <typ> *tmp = FIRST;
      if(i==0)
	{
	  FIRST=tmp->NEXT;
	  //delete tmp;
	}
      else if(i>=1)
	{
	  for(int j=0; tmp && j+1!=i; j++)
	    tmp = tmp->NEXT;          //przeskakiwanie do odpowiedniego elementu
	  if (tmp->NEXT->NEXT==NULL)
	    {
	      //delete tmp->NEXT;
	      tmp->NEXT=NULL;
	    }
	  else
	    {
	      // delete tmp->NEXT; //zwalnianie pamieci
	      tmp->NEXT=tmp->NEXT->NEXT;
	    }
	}
     this->rozmiar--;
    }
}
//-------------------------------------------------//
template <class typ>
void lista2s<typ>::remove()
{

  if(rozmiar==0)
    throw empty();
  else
    {
      StrListyT <typ> *tmp = FIRST;
      FIRST=tmp->NEXT;
      //delete tmp;         //zwalnianie pamieci
      /*for(int j=0; tmp && j+1!=rozmiar; j++)
      tmp = tmp->NEXT;              //przeskakiwanie do odpowiedniego elementu
      delete tmp->NEXT;             //zwalnianie pamieci
      tmp->NEXT=NULL;*/
      this->rozmiar--;
    }
}
//-------------------------------------------------//
template <class typ>
typ lista2s<typ>::get(int i)
{
  if(rozmiar==0)
    throw empty();
  else if (i>rozmiar || i<0)
    throw bad_index();
  else
    {
      StrListyT <typ> *tmp = FIRST;
      for(int j=0; j!=i; j++)
	tmp = tmp->NEXT;              //przeskakiwanie do odpowiedniego elementu
      return tmp->dana;
    }
}
//-------------------------------------------------//
template <class typ>
bool lista2s<typ>::isEmpty()
{
  if(rozmiar==0)
    return true;
  else return false;
}
//-------------------------------------------------//
template <class typ>
int lista2s<typ>::size()
{
  return rozmiar;
}
//-------------------------------------------------//
template <class typ>
int lista2s<typ>::find(typ x)
{
  if(rozmiar==0)
    throw empty();
  else
    {
      int j=0;
      StrListyT <typ> *tmp = FIRST;
      for(j=0; tmp->dana!=x && tmp->NEXT!=NULL; j++)
	tmp = tmp->NEXT;              //przeskakiwanie do odpowiedniego elementu
      if (tmp!=NULL)
	return j;
      else
	throw empty();
    }
}

template <class typ>
void lista2s<typ>::quicksort(StrListyT<typ> *pLeft, StrListyT<typ> *pRight)
{
	StrListyT<int> *pStart;
	StrListyT<int> *pCurrent;
	int nTmp;

	//jak prawy i lewy sa sobie rowne to koniec
	if(pLeft == pRight) return;

	pStart=pLeft;
	pCurrent= pStart->NEXT;

	while(1)
	{
		//sprawdzam czy element z lewej jest mniejszy niz z prawej
		if (pStart->dana < pCurrent->dana)
		{
			//zamieniam ze soba elementy
			nTmp=pCurrent->dana;
			pCurrent->dana=pStart->dana;
			pStart->dana=nTmp;
		}
		//sprawdzam czy prawy koniec osiagniety
		if (pCurrent == pRight) break;

		//przesuwam wskaznik na nastepny element
		pCurrent = pCurrent->NEXT;
	}
	//zamieniam pierwszy i biezacy element
	nTmp = pLeft->dana;
	pLeft->dana = pCurrent->dana;
	pCurrent->dana=nTmp;

	//zapisuje biezacy element
	StrListyT<int> *pOldCurrent = pCurrent;

	//sprawdzam czy sortowac lewa strone
	pCurrent = pCurrent->PREV;
	if(pCurrent != NULL)
	{
		if ((pLeft->PREV != pCurrent) && (pCurrent->NEXT != pLeft))
			quicksort(pLeft, pCurrent);
	}

	//sprawdzam czy sortowac prawa
	pCurrent=pOldCurrent;
	pCurrent = pCurrent->NEXT;
	if(pCurrent != NULL)
	{
		if((pCurrent->PREV != pRight) && (pRight->NEXT != pCurrent))
			quicksort(pCurrent, pRight);
	}
}

#endif
