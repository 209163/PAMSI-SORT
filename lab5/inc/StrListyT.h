/*!
\file
\brief plik zawiera strukture potrzebna do dzialania listy
*/
#ifndef STRLISTYT_HH
#define STRLISTYT_HH
#include <string>
template <class typ>
struct StrListyT{
public:
  //std::string dana;
  typ dana;
  StrListyT *NEXT;
  StrListyT *PREV;
  StrListyT(){NEXT=NULL; PREV=NULL;}
};
#endif
