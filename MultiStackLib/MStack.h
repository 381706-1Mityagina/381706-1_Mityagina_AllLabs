#pragma once

#include <iostream>

#include "../StackLib/Stack.h"
/* нужно написать класс исключений */

template <class T>
class TNewStack :public TStack<T> 
{
public:
	TNewStack(int _Size = 0, T* _Mas = 0)
  {
		TStack<T>::Size = _Size;
		TStack<T>::Top = 0;
		if (_Mas == 0) TStack<T>:: Mas = 0; 
		else 
			TStack<T>:: Mas = _Mas;
	}
  
	TNewStack(TNewStack <T> &NewOne) 
  {
		TStack<T>:: Size = NewOne.TStack<T>::Size;
		TStack<T>:: Top = NewOne.TStack<T>::Top;
		if (NewOne.TStack<T>::Mas == 0) 
      TStack<T>::Mas = 0;
		else 
			TStack<T>::Mas = NewOne.TStack<T>::Mas;
	}
  
	int CountFree() 
  {
		return (TStack<T>::Size - TStack<T>::Top);
	}
  
	int GetSize() 
  {
		return TStack<T>::Size;
	}
  
  int GetTop() 
  {
    return TStack<T>::Top;
  }
  
  void SetMas(int _Size, T* _Mas) 
  {
    TStack<T>::Size = _Size;
    TStack<T>::Mas = _Mas;
  }
};
//-------------------------------------------------------------------------------------//
//                              another class                                          //
//-------------------------------------------------------------------------------------//

template <class T>
class TMStack 
{
protected:
	int size;
	T* mas;
	int n;
	TNewStack<T>** NewOne;
	int GetFreeMem();
  void Repack(int k);
public:
	TMStack(int _size, int _n);
	TMStack(TMStack<T> &MultiS);
	void Put(int _n, T A);
	T Get(int _n);
	bool IsFull(int _n);
	bool IsEmpty(int _n);
	
	void Print() 
  {
		for (int i = 0; i < size; i++)
			  std::cout << i << " " << TMStack<T>::mas[i] << std::endl;
		std::cout << std::endl;
	}
};
//-------------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(int _size, int _n) 
{
  if ((_n <= 0) || (_size <= 0)) 
    throw "Wrong";	
  n = _n;
	size = _size;
	mas = new T[size];
	NewOne = new TNewStack<T>*[n];

	int* needed = new int[n];
	needed[0] = (int(double(size) / n) + (size % n));
	for (int i = 1; i < n; i++)
		needed[i] = int(double(size) / n);
	NewOne[0] = new TNewStack<T>(needed[0], &mas[0]);
	for (int i = 1; i < n; i++)
		NewOne[i] = new TNewStack<T>(needed[i], &mas[needed[0] + (i - 1) * needed[i]]);
}
//-------------------------------------------------------------------------------------
template <class T>
TMStack<T>::TMStack(TMStack<T> &MultiS) 
{
	size = MultiS.size;
	n = MultiS.n;
	mas = new T[size];
	NewOne = new TNewStack<T>*[n];
	for (int i = 0; i < size; i++) 
		mas[i] = MultiS.mas[i];
	int* needed = new int[n];
	for (int i = 0; i < n; i++)
		needed[i] = MultiS.NewOne[i]->TNewStack<T>::GetSize();
	int sizeCounter = 0;
	NewOne[0] = new TNewStack<T>(*(MultiS.NewOne[0]));
  NewOne[0]->TNewStack<T>::SetMas(needed[0], mas);
	for (int i = 1; i < n; i++)
	{
		NewOne[i] = new TNewStack<T>(*(MultiS.NewOne[i]));
		NewOne[i]->TNewStack<T>::SetMas(needed[i], &mas[needed[0] + sizeCounter]);
		sizeCounter += needed[i];
	}
}
//-------------------------------------------------------------------------------------
template <class T>
int TMStack<T>::GetFreeMem() 
{
	int count = 0;
	for (int i = 0; i < n; i++)
		count += NewOne[i]->CountFree();
	return count;
}
//-------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Repack(int k) 
{
  int FreeM = GetFreeMem();
  if (FreeM == 0)
    throw "Wrong";
  int AddEqually = int(double(FreeM) / n), AddWhole = FreeM % n;
  int* ChangedSize = new int[n];
  T ** TheSameStart = new T*[n], **ChangedStart = new T*[n];
  
  for (int i = 0; i < n; i++)
    ChangedSize[i] = AddEqually + ns[i]->TNewStack<T>::GetTop();
  ChangedSize[k] += AddWhole;
  ChangedStart[0] = TheSameStart[0] = mas;
  
  for (int i = 1; i < n; i++)
  {
    ChangedStart[i] = ChangedStart[i - 1] + ChangedSize[i - 1];
    TheSameStart[i] = TheSameStart[i - 1] + NewOne[i - 1]->TNewStack<T>::GetSize();
  }
  for (int i = 0; i < n; i++)
  {
    if (ChangedStart[i] <= TheSameStart[i])
      for (int j = 0; j < NewOne[i]->TNewStack<T>::GetTop(); j++)
        ChangedStart[i][j] = TheSameStart[i][j];
    else
    {
      int s = i + 1;
      for (; s < n; s++)
        if (ChangedStart[s] <= TheSameStart[s])
          break;
      for (int j = s - 1; j >= i; j--)
        for (int r = NewOne[i]->TNewStack<T>::GetTop() - 1; r >= 0; r--)
          ChangedStart[j][r] = TheSameStart[j][r];
      i = s - 1; 
    }
  }
  for (int i = 0; i < n; i++)
    NewOne[i]->TNewStack<T>::SetMas(ChangedSize[i], ChangedStart[i]);
  delete[] ChangedSize;
  delete[] ChangedStart;
  delete[] TheSameStart;
}
//-------------------------------------------------------------------------------------
template <class T>
void TMStack<T>::Put(int _n, T A)
{
  if (_n < 0 || _n >= size) 
    throw "Wrong";
	if (IsFull(_n)) Repack(_n);
	NewOne[_n]->TStack<T>::Put(A);
}
//-------------------------------------------------------------------------------------
template <class T>
T TMStack<T>::Get(int _n) 
{
	if (_n >= 0 && _n < n)
      return (NewOne[_n]->TStack<T>::Get());	
  else 
    throw "Wrong";
}
//-------------------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsFull(int _n) 
{
  if (_n < 0 || _n >= size) 
    throw "Wrong";
	return (NewOne[_n]->TStack<T>::IsFull());
}
//-------------------------------------------------------------------------------------
template <class T>
bool TMStack<T>::IsEmpty(int _n) 
{
  if (_n < 0 || _n >= size) 
    throw "Wrong";
	return (NewOne[_n]->TStack<T>::IsEmpty());
}
//-------------------------------------------------------------------------------------
