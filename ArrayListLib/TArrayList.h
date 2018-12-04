#pragma once

template <class T>
class TArrayList
{
protected:
  int Size, Count, Start;
  T* Mas; 
  int *Index;
public:
  TArrayList(int n = 0);
  TArrayList(TArrayList<T> &A);
  bool IsFul();
  bool IsEmpty();
  void PutStart(T B);
  void PutEnd(T B);
  T GetStart();
  T GetEnd();
};

//---------------------------------------------------------------------
template <class T>
TArrayList<T>::TArrayList(int n)
{
  T* mas; int* ind;
  if (Size <= 0) 
	throw "Wrong";
  else
  {
	Size = n;
	mas = new T[Size];
	ind = new int[Size];
	for (int i = 0; i < Size; i++)
	  ind[i] = -2;
  }
}
//---------------------------------------------------------------------
template <class T>
bool TArrayList<T>::IsEmpty()
{
  if (Count == 0)
	return true;
  else 
	return false;
}
//---------------------------------------------------------------------
template <class T>
bool TArrayList<T>::IsFul()
{
  if (Count == Size)
	return true;
  else
	return false;
}
//---------------------------------------------------------------------
template <class T>
TArrayList<T>::TArrayList(TArrayList<T> &A)
{
  Start = A.Start;
  Size = A.Size;
  Count = A.Count;
  if (Size == 0)
  {
	Mas = 0;
	Index = 0;
  }
  else if (Size < 0)
	throw "Wrong";
  else
  {
	Mas = new T[Size];
	Index = new int[Size];
  }
  for (int i = 0; i < Size; i++)
  {
	Mas[i] = A.Mas[i];
	Index[i] = A.Index[i];
  }

}
//---------------------------------------------------------------------
template <class T>
void TArrayList<T>::PutStart(T B)
{
  if (IsFul())
	throw "Wrong";
  else
  {
	for (int i=0; i < Size; i++)
	  if (Index[i] == -2)
	  {
		Index[i] = Start;
		Mas[i] = B;
		Start = i;
		Count++;
		break;
	  }
  }
}
//---------------------------------------------------------------------
template <class T>
void TArrayList<T>::PutEnd(T B)
{
  if (IsFul())
	throw "Wrong";
  else
	for (int i=0; i < Size; i++)
	  if (Index[i]==-2)
  {
		Mas[i] = B;
		for (int j = 0; j < Size; j++)
		  if (Index[i] == -1)
		  {
			Index[j] = i;
			Index[i] = -1;
			break;
		  }
		Count++;
		break;
  }
}
//---------------------------------------------------------------------
template <class T>
T TArrayList<T>::GetStart()
{
  if (IsEmpty())
	throw "Wrong";
  else
  {
	T temporary = Mas[Start];
	int _Start = Index[Start];
	Index[Start] = -2;
	Start = _Start;
	Count--;
	return temporary;
  }
}
//---------------------------------------------------------------------
template <class T>
T TArrayList<T>::GetEnd()
{
  if (IsEmpty())
	throw "Wrong";
  else
  {
	int last_ind = Start, last_but_one_ind = Index[Start];
	while (Mas[last_but_one_ind] != -1)
	{
	  last_ind = last_but_one_ind;
	  last_but_one_ind = Index[last_but_one_ind];
	}
	Index[last_ind] = -1;
	Count--;
	return Mas[last_but_one_ind];
  }
}
//---------------------------------------------------------------------
