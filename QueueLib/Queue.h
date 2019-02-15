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
    TStack<T>::mas[Start] = A;
    Start = (Start + 1) % TStack<T>::size;
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
    T temporary = TStack<T>::mas[TStack<T>::top];
    TStack<T>::top = (TStack<T>::top + 1) % TStack<T>::size;
    Count--;

    return temporary;
  }
}
//-----------------------------------------------------------------
template <class T>
bool TQueue<T>::IsFull()
{
if (Count == TStack<T>::size)
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
