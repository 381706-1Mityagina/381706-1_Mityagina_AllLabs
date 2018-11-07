#pragma once

template <class T>
class TStack {
protected:
	int Size;
	int TopOne;
	T* Mas;
public:
	TStack(int n = 0);
	TStack(TStack<T> &A);
	void Put(T A);
	T Get();
	bool IsFull();
	bool IsEmpty();
};
//-----------------------------------------------------------
template <class T>
TStack <T> :: TStack(int n) {
	if (n < 0) throw 1;
	else 
		if (n == 0) {
			Size = TopOne = 0;
			Mas = NULL;
		}
		else {
			Size = n;
			Top = 0;
			Mas = new T[Size];
			for (int i = 0; i < Size; i++)
				Mas[i] = 0;
		}
}
//-----------------------------------------------------------
template <class T>
TStack <T> :: TStack(TStack <T> &A) {
	Size = A.Size;
	Top = A.TopOne;
	if (Size == 0)
		Mas = NULL;
	else {
		Mas = new T[Size];
		for (int i = 0; i < Size; i++)
			Mas[i] = A.Mas[i];
	}
}
//-----------------------------------------------------------
template <class T>
void TStack<T> :: Put(T A) {
	if (IsFull())
		throw 1;
	else {
		Mas[TopOne] = A;
		Top++;
	}
}
//-----------------------------------------------------------
template <class T>
T TStack<T> :: Get() {
	if (IsEmpty()) 
		throw 1;
	else {
		TopOne--;
		return Mas[Top + 1];
	}
}
//-----------------------------------------------------------
template <class T>
bool TStack<T> :: IsFull() {
	if (TopOne >= Size)
		return true;
	else
		return false;
}
//-----------------------------------------------------------
template <class T>
bool TStack<T> :: IsEmpty() {
	if (TopOne == 0)
		return true;
	else
		return false;
}