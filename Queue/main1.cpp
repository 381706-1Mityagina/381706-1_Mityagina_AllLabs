#include <iostream>
#include <locale.h>
#include "Queue.h"

using namespace std;

int main(int argc, char* argv[]) 
{
 setlocale(LC_ALL, "Russian");
 TQueue test;
 int temporary;
 cout << "Тестирование программ поддержки структуры типа очереди" << endl;
 for ( int i=0; i < 35; i++ ) 
 {
 test.Put(i);
 cout << "Положили значение " << i << endl;
 }
 getch();
 while ( !test.IsEmpty() ) {
 temp = test.Get();
 cout << "Взяли значение " << temp << endl;
 }
 cout << "Нажмите любую клавишу" << endl;
 getch();
 return 0;
} 
