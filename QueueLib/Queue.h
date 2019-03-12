#pragma once

#include "..//StackLib/Stack.h"

template <class T>
class TQueue : public TStack <T> 
{
protected:
  int Start; // Начало очереди
  int Count; // Кол-во элементов в очереди -> =конец очереди
public:
  TQueue(int N = 0); // конструктор с параметром
  TQueue(TQueue <T> &Q); // конструктор копирования
  T Get(); // взять элемент
  void ShowQ(); // вывести элементы очереди
  T GetButDontDelQ(); // получить вершину(начало) очереди
  void Put(T A); // положить в конец очереди
  bool IsFull(); // проверка на полноту
  bool IsEmpty(); // проверка на пустоту
};
//-----------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int N) : TStack<T>(N) 
{
  Start = 0;
  Count = 0; 
}
//-----------------------------------------------------------------
template <class T>
TQueue<T>::TQueue(TQueue<T> &Q) : TStack<T>(Q) 
{ 
  Start = Q.Start; 
  Count = Q.Count; 
}
//-----------------------------------------------------------------
template <class T>
void TQueue<T>::Put(T A) 
{
if (IsFull())
 throw TException("Queue is full.");
else 
{
  /*TStack<T>::mas[Start] = A;
  Start = (Start + 1) % TStack<T>::size;*/
  TStack<T>::Put(A);
  TStack<T>::Top = TStack<T>::Top % TStack<T>::Size;
  Count++;
 }
}
//-----------------------------------------------------------------
template <class T>
T TQueue<T>::Get() 
{
if (IsEmpty())
 throw TException("Queue is empty.");
else 
{
 T temporary = TStack<T>::Mas[Start];
 Start = (Start + 1) % TStack<T>::Size;
 Count--;
 return temporary;
 }
}
//-----------------------------------------------------------------
template <class T>
T TQueue<T>::GetButDontDelQ()
{
  return TStack<T>::Mas[Start];
}
//-----------------------------------------------------------------
template <class T>
void TQueue<T>::ShowQ()
{
  int t = TStack<T>::Top;
  int s = TStack<T>::Size;
  for (int i = Start; i < t; i = (i + 1) % s)
  cout << TStack<T>::Mas[i];
}
//-----------------------------------------------------------------
template <class T>
bool TQueue<T>::IsFull()
{
if (Count == TStack<T>::Size)
 return true;
else
 return false;
}
//-----------------------------------------------------------------
template <class T>
bool TQueue<T>::IsEmpty() 
{
if (Count == 0)
 return true;
else
 return false;
} 
//-----------------------------------------------------------------
