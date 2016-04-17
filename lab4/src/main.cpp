/*
 * main.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
using namespace std;

int main()
{
	srand(time(NULL));

	lista sizes;
	sizes.add(10);
	sizes.add(100);
	sizes.add(1000);
	sizes.add(100000);
	sizes.add(1000000);
	sizes.add(1000000000);
	for (int i=0; i<6; i++)
	{
		cout<<sizes.get(i)<<endl;
	}

	int tab[10];

	lista posortuj;
	for (int i=0; i<10; i++)
	{
		int r=rand()%10+1;
		posortuj.add(r);
	}
	for (int i=0;i<10;i++)
	{
		cout<<posortuj.get(i)<<" ";
	}


	return 0;
}


