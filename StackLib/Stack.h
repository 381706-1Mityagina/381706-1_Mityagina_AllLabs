#pragma once

#include <iostream>
#include "..//Exception/Exception.h"

template <class T>
class TStack
{
protected:
  int Size;
  int Top;
  T* Mas;
public:
  int GetSize() { return Size; }
  TStack(int n = 0);
  TStack(TStack<T> &S);
  T Get();
  void Put(T A);
  bool IsFull();
  bool IsEmpty();
};
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(int n)
{
  if (n < 0) throw 1;
  else
	if (n == 0)
	{
	  Size = Top = 0;
	  Mas = NULL;
	}
	else
	{
	  Size = n;
	  Top = 0;
	  Mas = new T[Size];
	  for (int i = 0; i < Size; i++)
		Mas[i] = 0;
	}
}
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(TStack <T> &S)
{
  Size = S.Size;
  Top = S.Top;
  if (Size == 0)
	Mas = NULL;
  else
  {
	Mas = new T[Size];
	for (int i = 0; i < Size; i++)
	  Mas[i] = S.Mas[i];
  }
}
//----------------------------------------------------------------------
template <class T>
void TStack<T> ::Put(T A)
{
  if (IsFull())
	throw TException("Stack is full");
  else
  {
	Mas[Top] = A;
	Top++;
  }
}
//----------------------------------------------------------------------
template <class T>
T TStack<T> ::Get()
{
  if (IsEmpty())
	throw TException("Stack is empty");
  else
  {
	Top--;
	return Mas[Top];
  }
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsFull()
{
  if (Top >= Size)
	return true;
  else
	return false;
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsEmpty()
{
  if (Top == 0)
	return true;
  else
	return false;
}
//----------------------------------------------------------------------
