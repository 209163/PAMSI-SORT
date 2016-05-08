/*!
\file
\brief plik zawiera szablon klasy lista2s, ktora jest zbudowana jak klasyczna lista
*/
#ifndef LISTA2s_HH
#define LISTA2s_HH
#include "inLista.h"
#include "StrListyT.h"
#include <iostream>
using namespace std;
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
  void quicksortAlg(StrListyT<typ> *start, StrListyT<typ> *end);
  void quicksort(StrListyT<typ> *start);
  StrListyT<typ> *partition(StrListyT<typ> *start, StrListyT<typ> *end);
  void mergesort(StrListyT<typ> **firstRef);
  StrListyT<typ>* sortedmerge(StrListyT<typ>* a, StrListyT<typ>* b);
  void split(StrListyT<typ>* source, StrListyT<typ>** frontRef, StrListyT<typ>** backRef);
  void swap(int* a, int* b);
  StrListyT<typ> *lastNode(StrListyT<typ> *root);
  class bad_index{};
  class empty{};
};

//-------------------------------------------------//

template <class typ>
lista2s<typ>::~lista2s()
{

}

/**
 * zamienia dwa elementy
 * @param a
 * @param b
 */
template <class typ>
void lista2s<typ>::swap(int* a, int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

/**
 * odnajduje  ostatni wezel w dwukierunkowej liscie
 * @param root
 * @return zwraca ostatni wezel
 */
template <class typ>
StrListyT<typ> *lista2s<typ>::lastNode(StrListyT<typ> *root)
{
	while (root && root->NEXT)
	{
		root=root->NEXT;
	}
	return root;
}

/**
 * odnajduje ostatni wezel oraz wywoluje quicksortAlg()
 * @param start
 */
template <class typ>
void lista2s<typ>::quicksort(StrListyT<typ> *start)
{
	StrListyT<typ> *last = lastNode(start);
	quicksortAlg(start, last);
}



/**
 * glowne zalozenie dzialania algorytmu quicksort
 * @param start
 * @param end
 */
template <class typ>
void lista2s<typ>::quicksortAlg(StrListyT<typ> *start, StrListyT<typ> *end)
{
	//if(start=>end) return;
	if( end!=NULL && start != end && start != end->NEXT)
	{
		//zwraca wskaznik do pivota po sortowaniu
		StrListyT<typ> *pivotPointer = partition(start, end);
		quicksortAlg(start, pivotPointer->PREV);
		quicksortAlg(pivotPointer->NEXT, end);
	}

}
/**
 * przerzuca na lewo wartosci mniejsze od pivota, a na prawo wieksze
 * @param start pierwszy element listy
 * @param end ostatni element listy
 * @return
 */
template <class typ>
StrListyT<typ> *lista2s<typ>::partition(StrListyT<typ> *start, StrListyT<typ> *end)
{
	//wybieram ostatni element na pivota
	typ pivot = end->dana;
	//i=start-1;
	StrListyT<typ> *i = start->PREV;
	//for (int j=start; j<=end-1; j++)
	for (StrListyT<typ> *j=start; j !=end; j=j->NEXT)
	{
		if (j->dana <= pivot)
		{
			if(i==NULL) i=start;
			else i=i->NEXT;
			swap(&(i->dana), &(j->dana));
		}
	}
	//wstawiam pivota w odpowiednie miejsce
	if (i==NULL) i=start;
	else i=i->NEXT;
	swap(&(i->dana), &(end->dana));
	return i;
}

/**
 * funcka dzieli liste na 2 polowy - front i back.
 * Jezeli tozmiary nie moga byc rowne to ten dodatkowy umieszczany jest we front
 * @param source
 * @param frontRef
 * @param backRef
 */
template <class typ>
void lista2s<typ>::split(StrListyT<typ>* source, StrListyT<typ>** frontRef, StrListyT<typ>** backRef)
{
	StrListyT<int> * fast;
	StrListyT<int> * slow;
	//lista pusta lub 1 elem
	if(source==NULL || source->NEXT==NULL)
	{
		*frontRef=source;
		*backRef=NULL;
	}
	else
	{
		slow = source;
		fast=source->NEXT;

		//zwiekszam fast o 2 wezly, slow o 1
		while (fast!=NULL)
		{
			fast=fast->NEXT;
			if(fast!=NULL)
			{
				slow=slow->NEXT;
				fast=fast->NEXT;
			}
		}

		/*
		 * slow jest tuz przed srodkiem listy, ustawiam
		 * poczatek jednaj listy na source, a drugiej na nastepny po slow
		 */
		*frontRef=source;
		*backRef=slow->NEXT;
		slow->NEXT=NULL;
	}
}

template <class typ>
StrListyT<typ>* lista2s<typ>::sortedmerge(StrListyT<typ>* a, StrListyT<typ>* b)
{
	StrListyT<int>* result = NULL;

	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}

	if(a->dana <= b->dana)
	{
		result = a;
		result->NEXT = sortedmerge(a->NEXT,b);
	}
	else
	{
		result=b;
		result->NEXT = sortedmerge(a,b->NEXT);
	}

	return result;
}

template <class typ>
void lista2s<typ>::mergesort(StrListyT<typ> **headRef)
{
	StrListyT<int>* head = *headRef;
	StrListyT<int>* a;
	StrListyT<int>* b;
	//jak pusta lub tylko 1 elem
	if((head==NULL) || (head->NEXT==NULL)) return;

	//podzial na 2 podlisty
	split(head, &a, &b);

	//sortuje podlisty
	mergesort(&a);
	mergesort(&b);

	//scalam posortowane listy
	*headRef = sortedmerge(a,b);
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



#endif
