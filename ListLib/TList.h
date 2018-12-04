#pragma once
#pragma once

#include "TElement.h"

template <class T>
class TList 
{
protected:
	TElement <T>* begin;
	int size;
public:
	TList(); 
	TList(TList<T> &List); 
	virtual ~TList();
	
	T viewData(TElement<T>* ptr) { return ptr->data; }
	T* viewPtr(TElement<T>* ptr) { return ptr; }

	int GetSize() { return size; }
	void PutBegin(T A); 
	void PutCurrent(T A);
	void PutEnd(T A); 
	T GetBegin(); 
	T GetCurrent(); 
	T GetEnd(); 

				
	bool IsFull();
	bool IsEmpty();
	
	virtual void DelFirst(void);
	virtual void DelCurrent(void);
	virtual void DelList(void);

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
void TList<T>::PutCurrent(T A)
{
	
}
//-----------------------------------------------------------
template <class T>
void TList<T>::DelFirst(void)
{
   if (size)
	{
		TElement<T>* temporary = begin -> next;
		T result= begin->data;
		delete begin;
		begin = temporary;
		size--;
	}
	else
		throw "Error";	
}
//-----------------------------------------------------------
template <class T>
void TList<T>::DelCurrent(void)
{
	
}
//-----------------------------------------------------------
template <class T>
void TList<T>::DelList(void)
{

}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T A)
{
	if (begin != 0) 
	{
		TElement <T> *B = begin;
		while (B->GetNext() != 0)
			B = B->GetNext();
		B->SetNext(new TElement <T>(A, 0));
	}
	else
		begin = new TElement <T>(A, 0);
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
T TList<T>::GetCurrent()
{
	
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetEnd()
{
	
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
