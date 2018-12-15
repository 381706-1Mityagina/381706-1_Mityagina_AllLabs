#pragma once
#pragma once

#include "TElement.h"

template <class T>
class TList 
{
protected:
	TElement <T>* begin; //Указатель на первое звено списка
	int size; // размер
public:
	TList(); // конструктор по умолчанию
	TList(TList<T> &List); // конструктор копирования
	virtual ~TList(); // деструктор
	
	T viewData(TElement<T>* ptr) { return ptr->data; } 
	T* viewPtr(TElement<T>* ptr) { return ptr; }

	int GetSize() { return size; }
	void PutBegin(T A); //Установить начальное звено
	void PutEnd(T A); //Установить последнее звено
	T GetBegin(); // получить значение первого звена
	T GetEnd(); // получить значение последнего звена
				
	bool IsFull(); // проверка на полноту
	bool IsEmpty(); // проверка на пустоту
};

//-----------------------------------------------------------
template <class T>
TList<T>::TList()
{
	size = 0;
	begin = 0;
}
//-----------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &List)
{
	size = List.size;
	TElement<T>* A = List.begin, B;
	if (List.begin == 0)
		begin = 0;
	else {
		begin = new TElement<T>(*List.begin); 
		B = begin;
		while (A->GetNext() != 0) 
		{
			B->SetNext(new TElement<T>(*(A->GetNext()))); 
			A = A->GetNext();
			B = B->GetNext();
		}
	}
}
//-----------------------------------------------------------
template <class T>
TList<T>::~TList() 
{
	while (begin != 0)          
	{
		TElement <T> *temporary = begin->GetNext();   
		delete begin;                
		begin = temporary;
	}
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T A)
{
	if (begin == 0) 
	{
		TElement <T>* temporary = new TElement <T>(A, 0);
		begin = temporary;
	}
	else 
	{
		TElement <T>* temporary = new TElement <T>(A, begin);
		begin = temporary;
	}
	size++;
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T A)
{
  if (begin != 0) {
    TElement <T> *a = begin;
    while (a->GetNext() != 0)
      a = a->GetNext();
    a->SetNext(new TElement <T>(A, 0));
  }
  else 
    begin = new TElement<T>(A, 0);
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{
	if (IsEmpty())
		throw "List's empty";
	else 
	{
		TElement<T> *A = begin;
		T temporary = begin->TElement<T>::GetData();
		begin = begin->TElement<T>::GetNext();
		delete A;
		return temporary;
	}
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
	if (!IsEmpty()) 
	{
		TElement<T>* temp = begin;
		while ((temp->GetNext())->GetNext() != 0)
			temp = temp->GetNext();

		T temp1 = (temp->GetNext())->GetData();

		temp->SetNext(0);

		return temp1;
	}
	else
		throw "smth";
}
//-----------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElement<T>* A = new TElement<T>();
		if (A == 0)
			return false;
		else 
		{
			delete A;
			return true;
		}
	}
	catch (...)
	{
		return false;
	}
	//return true; 
 //do i really need this line? that's the question.-.
}
//-----------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{
	//if (begin == 0)
	if (size == 0)
		return true;
	else
		return false;
}
//-----------------------------------------------------------
