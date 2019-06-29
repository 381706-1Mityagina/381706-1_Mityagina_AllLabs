#include "..//ViewTableLib/ViewTable.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  TViewTableElem<int> elem_f("a", 40), elem_s("b", 10), elem_t("c", 100);
  TViewTableElem<int> elem_fo(elem_f);
  
  TViewTable<int> hey(10);
  
  hey.Put(elem_s);
  hey.Put(elem_t);
  hey.Put(elem_f);

  cout<<t<<"\n";
  
  hey.Put(elem_fo);
  
  return 0;
}
