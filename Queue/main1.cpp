#include <iostream>
#include <locale.h>
#include "Queue.h"

using namespace std;

int main(int argc, char* argv[]) 
{
 setlocale(LC_ALL, "Russian");
 TQueue<int> test;
 int temporary;
 cout << "Тестирование программ поддержки структуры типа очереди" << endl;
 for ( int i=0; i < 35; i++ ) 
 {
 test.Put(i);
 cout << "Положили значение " << i << endl;
 }
 cin.get();
 while ( !test.IsEmpty() ) {
 temporary = test.Get();
 cout << "Взяли значение " << temporary << endl;
 }
 cout << "Нажмите любую клавишу" << endl;
 cin.get();
 return 0;
} 
