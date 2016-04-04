/*!
\file
\brief plik zawiera funkcje z metodami sortowania
*/
#ifndef SORT_HH
#define SORT_HH
#include <algorithm>
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

void quickSort(int *tab, int left, int right)
{
	if(right<=left) return;
	int i=left-1, j=right+1;
	int pivot=tab[(left+right)/2];	//pkt odniesienia
	
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
		quickSort(tab, left, j);
	if (i<right)
		quickSort(tab, i, right);
}
#endif
