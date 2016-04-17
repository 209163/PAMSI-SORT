/*
 * sort.h
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */

/*!
\file
\brief plik zawiera funkcje z metodami sortowania
*/
#ifndef SORT_HH
#define SORT_HH
#include <algorithm>
#include <iostream>
using namespace std;
//! \brief sortowanie babelkowe
void bubblesort(int tab[], int size)
{
  int tmp;
  for(int i=0; i< size; i++)
    {
      for(int j=0; j<size; j++)
	{
	  if(tab[j]>tab[j+1])
	    {
	      tmp=tab[j];
	      tab[j]=tab[j+1];
	      tab[j+1]=tmp;
	    }
	}
    }
}
//! \brief sortowanie szybkie
void quickSort(int *tab, int lewy, int prawy)
{
	if(prawy<=lewy) return;
	int i=lewy-1, j=prawy+1;
	int pivot=tab[(lewy+prawy)/2];	//pkt odniesienia

	while(1)
	{
	while(pivot>tab[++i]);
	while(pivot<tab[--j]);
	if(i<=j)
		swap(tab[i], tab[j]);
	else
		break;
	}

	if(j>left)
		quickSort(tab, lewy, j);
	if (i<right)
		quickSort(tab, i, prawy);
}

//! \file sortowanie przez scalanie
//! scalanie dwoch posortowanych ciagow
void merge(int *tab, int pocz, int sr, int kon)
{
	lista list;
	int *tmp=new int [list.size()];
	int i,j,q;
	for (i=pocz; i<=kon; i++) tmp[i]=tab[i];  // Skopiowanie danych do tablicy pomocniczej
	i=pocz; j=sr+1; q=pocz;                 // Ustawienie wskaźników tablic
	while (i<=sr && j<=kon) {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy głównej
	if (tmp[i]<tmp[j])
	tab[q++]=tmp[i++];
	else
	tab[q++]=tmp[j++];
	}
	while (i<=sr) tab[q++]=tmp[i++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór się skończył
}
//! sortowanie
void mergesort(int *tab, int pocz, int kon)
{
	int sr;
	if (pocz<kon) {
	sr=(pocz+kon)/2;
	mergesort(tab, pocz, sr);    // Dzielenie lewej części
	mergesort(tab, sr+1, kon);   // Dzielenie prawej części
	merge(tab, pocz, sr, kon);   // Łączenie części lewej i prawej
}
}
#endif
