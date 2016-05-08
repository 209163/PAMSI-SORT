/*
 * QSTest.h
 *
 *  Created on: 1 maj 2016
 *      Author: paula
 */

#ifndef QSTEST_H_
#define QSTEST_H_
#include "lista2s.h"
#include "stoper.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class typ>
class QSTest: public lista2s<typ> {
public:
	QSTest();
	virtual ~QSTest();
	void run();
};
//---------------------------------------------------//
template <class typ>
QSTest<typ>::QSTest() {


}

template <class typ>
QSTest<typ>::~QSTest() {
}


template <class typ>
void QSTest<typ>::run()
{
	srand(time(NULL));
	QSTest<int> sizes;

		sizes.add(10);
		sizes.add(100);
		sizes.add(1000);
		sizes.add(10000);
		sizes.add(100000);
		sizes.add(1000000);
		sizes.add(10000000);
		for(int k=0; k<10; k++)
		{
//cout<<"przypadek sredni:"<<endl;
//for (int i=0; i<7;i++)
//	{
//		QSTest<int> test;
//		stoper mea;
//		//tworze tablice do posortowania
//		for (int j=0; j<sizes.get(i); j++)
//		{
//			int l=sizes.get(i);
//			int r=rand()%l+1;
//			test.add(r);
//		}
//
//		//wyswietlam ja
////		for (int j=0;j<sizes.get(i);j++)
////		{
////			cout<<test.get(j)<<" ";
////		}
//	//cout<<endl;
//		//sortowanie
//		mea.setStart();
//		test.quicksort(test.FIRST);
//		mea.setStop();
//		mea.getRunTime();
//		mea.sendToFile(sizes.get(i));
//		mea.displayRunTime(sizes.get(i));
//
//		//wyswietlam posortowana
////		for (int j=0;j<sizes.get(i);j++)
////			{
////				cout<<test.get(j)<<" ";
////			}
////		cout<<endl;
//	}

cout<<"przypadek pesymistyczny:"<<endl;
for (int i=0; i<6;i++)
	{
		QSTest<int> test;
		stoper mea;
		//tworze tablice do posortowania
		for (int j=0; j<sizes.get(i); j++)
		{
			test.add(j);
		}

//		//wyswietlam ja
//		for (int j=0;j<sizes.get(i);j++)
//		{
//			cout<<test.get(j)<<" ";
//		}
	//cout<<endl;
		//sortowanie
		mea.setStart();
		test.quicksort(test.FIRST);
		mea.setStop();
		mea.getRunTime();
		mea.sendToFile(sizes.get(i));
		mea.displayRunTime(sizes.get(i));

//		//wyswietlam posortowana
//		for (int j=0;j<sizes.get(i);j++)
//			{
//				cout<<test.get(j)<<" ";
//			}
		//cout<<endl;
	}
}

}





#endif /* QSTEST_H_ */
