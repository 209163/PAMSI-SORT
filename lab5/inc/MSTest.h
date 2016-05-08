/*
 * MSTest.h
 *
 *  Created on: 2 maj 2016
 *      Author: paula
 */

#ifndef MSTEST_H_
#define MSTEST_H_
#include "lista2s.h"
#include "stoper.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class typ>
class MSTest : lista2s<typ> {
public:
	MSTest();
	virtual ~MSTest();
	void run();
};

//-------------------------------------------------//

template <class typ>
MSTest<typ>::MSTest() {
	// TODO Auto-generated constructor stub

}

template <class typ>
MSTest<typ>::~MSTest() {
	// TODO Auto-generated destructor stub
}

template <class typ>
void MSTest<typ>::run()
{

	srand(time(NULL));
	MSTest<int> sizes;

		sizes.add(10);
		sizes.add(100);
		sizes.add(1000);
		sizes.add(10000);
		sizes.add(100000);
		sizes.add(1000000);
		sizes.add(1000000000);

	for (int k=0; k<10;k++)
	{
		cout<<"przypadek sredni:"<<endl;
		for (int i=0; i<5;i++)
			{
				MSTest<int> test;
				stoper mea;
				//tworze tablice do posortowania
				for (int j=0; j<sizes.get(i); j++)
				{
					int l=sizes.get(i);
					int r=rand()%l+1;
					test.add(r);
				}

//				//wyswietlam ja
//				for (int j=0;j<sizes.get(i);j++)
//				{
//					cout<<test.get(j)<<" ";
//				}
			//cout<<endl;
				//sortowanie
				mea.setStart();
				test.mergesort(&test.FIRST);
				mea.setStop();
				mea.getRunTime();
				mea.sendToFile(sizes.get(i));
				mea.displayRunTime(sizes.get(i));

//				//wyswietlam posortowana
//				for (int j=0;j<sizes.get(i);j++)
//					{
//						cout<<test.get(j)<<" ";
//					}
//				cout<<endl;
			}

//		cout<<"przypadek pesymistyczny:"<<endl;
//		for (int i=0; i<5;i++)
//			{
//				MSTest<int> test;
//				stoper mea;
//				//tworze tablice do posortowania
//				for (int j=sizes.get(i); j>0; j--)
//				{
//					test.add(j);
//				}
//
//		//		//wyswietlam ja
//		//		for (int j=0;j<sizes.get(i);j++)
//		//		{
//		//			cout<<test.get(j)<<" ";
//		//		}
//			//cout<<endl;
//				//sortowanie
//				mea.setStart();
//				test.mergesort(test.FIRST, test.LAST);
//				mea.setStop();
//				mea.getRunTime();
//				mea.sendToFile(sizes.get(i));
//				mea.displayRunTime(sizes.get(i));
//
//		//		//wyswietlam posortowana
//		//		for (int j=0;j<sizes.get(i);j++)
//		//			{
//		//				cout<<test.get(j)<<" ";
//		//			}
//				//cout<<endl;
//			}
		}

}

#endif /* MSTEST_H_ */
