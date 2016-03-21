#ifndef TABLICA_HH
#define TABLICA_HH
#include "atp2.hh"
class tablica: public atp2{
private:
  int *tab=new int[rozmiar];
public:
  tablica() {rozmiar=10;}
  tablica(int n) {rozmiar=n;}
  //void podaj_roz(int M){ this->rozmiar=M;}
  int wyswietl(int n) {return tab[n];}
  void push(int);
  void zwieksz(int);
  void przypisz(int, int);
  void zmniejsz();
  void zdejmij(int);
};
#endif
