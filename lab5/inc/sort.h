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
#include <utility>
#include <iostream>
using namespace std;
//! \brief sortowanie babelkowe

void swap(int a, int b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void bubblesort(lista2s<int> &list, int size)
{
  int tmp;
  for(int i=0; i< size; i++)
    {
      for(int j=0; j<size; j++)
	{
	  if(list.get(j)>list.get(j+1))
	    {
	      tmp=list.get(j);
	      list.add(list.get(j+1),j);
	      list.add(tmp, j+1);
	    }
	}
    }
}



////! \file sortowanie przez scalanie
////! scalanie dwoch posortowanych ciagow
//
//
//// Merges two subarrays of arr[].
//// First subarray is arr[l..m]
//// Second subarray is arr[m+1..r]
//void merge(lista list, int l, int m, int r)
//{
//    int i, j, k;
//    int n1 = m - l + 1;
//    int n2 =  r - m;
//
//    /* create temp arrays */
//    int *L=new int[n1];
//    int *R=new int[n2];
//
//
//    /* Copy data to temp arrays L[] and R[] */
//    for (i = 0; i < n1; i++)
//        L[i] = list.get(l+i);
//    for (j = 0; j < n2; j++)
//        R[j] = list.get(m+1+j);
//
//    /* Merge the temp arrays back into arr[l..r]*/
//    i = 0; // Initial index of first subarray
//    j = 0; // Initial index of second subarray
//    k = l; // Initial index of merged subarray
//    while (i < n1 && j < n2)
//    {
//        if (L[i] <= R[j])
//        {
//            //arr[k]  = L[i];
//            list.add(L[i],k);
//            i++;
//        }
//        else
//        {
//        	list.add(R[j],k);
//            //arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    /* Copy the remaining elements of L[], if there
//       are any */
//    while (i < n1)
//    {
//        //arr[k] = L[i];
//        list.add(L[i],k);
//        i++;
//        k++;
//    }
//
//    /* Copy the remaining elements of R[], if there
//       are any */
//    while (j < n2)
//    {
//        //arr[k] = R[j];
//        list.add(R[j],k);
//        j++;
//        k++;
//    }
//}
////! sortowanie
///* l is for left index and r is right index of the
//   sub-array of arr to be sorted */
//void mergeSort(lista list, int l, int r)
//{
//    if (l < r)
//    {
//        // Same as (l+r)/2, but avoids overflow for
//        // large l and h
//        int m = l+(r-l)/2;
//
//        // Sort first and second halves
//        mergeSort(list, l, m);
//        mergeSort(list, m+1, r);
//
//        merge(list, l, m, r);
//    }
//}
#endif
