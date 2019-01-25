#pragma once
#include <iostream>
#include "TElement.h"

using namespace std;
template <class T>
class TList
{
protected:
	TElement<T> *pFirst, *pLast, *pPrev, *pCurr, *pStop;
	int size, pos;
public:
	TList(); // конструктор
	~TList();// деструктор
	void AddFirst(T a);     // добавить в начало
	void AddCurrent(T a);   // добавить текущий
	void AddLast(T a);      // добавить в конец

	T viewData() { return pCurr->data; } // получить элемент
	T* viewPtr() { return pCurr; }

	void delFirst();   // удалить из начала
	void delCurrent(); // удалить текущий

	// проверки 
	bool isEnd() { return pCurr == pStop; } 
	bool isStart() { return pCurr == pFirst; }
	bool isEmpty() { return pFirst == NULL; }
	bool isFull();

	T operator[](int m);

	// helpers
	void reset();
	void goNext();
};
//-------------------------------------------------------------------------------
template <class T>
TList<T>::TList()
{
	pFirst = pLast = pCurr = pStop = NULL;
	size = 0;
	pos = -1;
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::AddFirst(T a)
{
	TElement<T> *tmp = new TElement <T>;
	tmp->data = a;
	if (size == 0)
	{
		pFirst = pLast = pCurr = tmp;
		tmp->next = pStop;
	}
	else
	{
		tmp->next = pFirst;
		pFirst = tmp;
		if (size == 1) pPrev = pFirst;
	}

	pos++;
	size++;
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::AddCurrent(T a) 
{
	if (pFirst == pCurr) AddFirst(a);
	else
	{
		TElement<T> *tmp = new TElement<T>;
		tmp->data = a;
		tmp->next = pCurr;
		pPrev->next = tmp;
		pCurr = tmp;
		size++;
	}
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::AddLast(T a) 
{
	if (pFirst == NULL) AddFirst(a);
	else 
	{
		TElement<T> *tmp = new TElement<T>;
		tmp->data = a;
		pLast->next = tmp;
		tmp->next = pStop;
		pLast = tmp;
		size++;
	}
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::delFirst() 
{
	if (size == 1)
	{
		delete pFirst;
		pFirst = pLast = pPrev = pCurr = pStop;
	}
	else
	{
		TElement<T> *tmp = pFirst->next;
		delete pFirst;
		pFirst = tmp;
	}
	size--;
	pos--;
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::delCurrent() 
{
	if (pCurr == pFirst)
		delFirst();
	else
	{
		pCurr = pCurr->next;
		delete pPrev->next;
		pPrev->next = pCurr;
		size--;
	}
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::reset() 
{
	pPrev = pCurr = pFirst;
	pos = 0;
}
//-------------------------------------------------------------------------------
template <class T>
void TList<T>::goNext() 
{
	pPrev = pCurr;
	pCurr = pCurr->next;
	pos++;
}
//-------------------------------------------------------------------------------
template <class T>
T TList<T>::operator[](int m) 
{
	for (reset(); !isEnd(); goNext()) 
	{
		if (pos == m - 1)
			return pCurr->data;
	}
}
//-------------------------------------------------------------------------------
template <class T>
TList<T>::~TList() 
{
	int listsize = size;
	for (int i = 0; i < listsize; i++)
		delFirst();
}
//-------------------------------------------------------------------------------
template <class T>
bool TList<T>::isFull()
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
	//do i really need this line? 
}
//-----------------------------------------------------------
