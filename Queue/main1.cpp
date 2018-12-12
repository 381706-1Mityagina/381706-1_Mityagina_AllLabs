#include <iostream>
#include <locale.h>
#include "..//QueueLib/Queue.h"

using namespace std;

int main()
{
 setlocale(LC_ALL, "Russian");  
 TQueue<int> test;
 int temporary;
 cout << "Тестирование программ поддержки структуры типа очереди" << endl;
 for ( int i = 0; i < 35; i++ ) 
 {
 while (!test.IsFull())
     test.Put(i);
 cout << "Положили значение " << i << endl;
 }
 while (!test.IsEmpty()) 
 {
 temporary = test.Get();
 cout << "Взяли значение " << temporary << endl;
 }
 return 0;
}  
