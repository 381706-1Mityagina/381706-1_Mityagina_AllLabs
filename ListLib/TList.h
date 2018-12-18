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
	TElement<T> *a = List.begin, *b;
	if (List.begin == 0)
		begin = 0;
	else
	{
		begin = List.begin;
		b = begin;
		while (a->GetNext() != 0)
		{
			b->SetNext(new TElement<T>(*a->GetNext()));
			a = a->GetNext();
			b = b->GetNext();
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
	if (begin != 0) 
	{
		TElement <T> *a = begin;
		while (a -> GetNext() != 0)
			a = a -> GetNext();
		a -> SetNext(new TElement <T>(A, 0));
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
		TElement<T>* a = begin;
		TElement<T>* b = begin->GetNext();
		if (b == 0)
		{
			T temp = a->TElement<T>::GetData();
			delete a;
			begin = 0;
			return temp;
		}
		else
		{
			while (b->GetNext() != 0)
			{
				a = b;
				b = b->GetNext();
			}
			T temp = b->GetData();
			delete b;
			a->SetNext(0);
			return temp;
		}
	}
	else
		throw -1;
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
