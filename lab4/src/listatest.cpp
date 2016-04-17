/*
 * listatest.cpp
 *
 *  Created on: 14 kwi 2016
 *      Author: paula
 */
#include <iostream>
#include "listatest.h"
#include "stoper.h"

using namespace std;

listatest::listatest() {
	// TODO Auto-generated constructor stub

}

listatest::~listatest() {
	// TODO Auto-generated destructor stub
}



void listatest::run()
{
  stoper s;
  int pom=-1;
  for(int j=0; j<getIleOkrazen(); j++)
    {
      for(int il=10; il<getIleDanych(); il=il*10)
	{
	  int losowana=(std::rand()%il);
	  s.setStart();
	  for(int i=0; pom==losowana && i<ile_elem; i++)
	    {
	      pom=get(i);
	    }
	  s.setStop();
	  s.sendToFile();
	  cout<<losowana<<endl;
	}
    }
}
