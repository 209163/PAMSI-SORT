#include<iostream>
#include <cstdio>
#include <ctime>
#include "tablica.hh"

int main (void)
{
  time_t czasStart = clock();
  int N=10;
  int ile_el=1000;
  tablica t;
  t.podaj_N(N);
  for(int i=0;i<ile_el; i++)
    t.nowa_dana(i);
  time_t czasStop = clock();
  //t.wyswietl();
  //t.wyswietl_N();
  std::cout<<"Uplynelo "<<(czasStop-czasStart)/(CLOCKS_PER_SEC*1.0)<<"s"<<std::endl;
  return 0;
}
