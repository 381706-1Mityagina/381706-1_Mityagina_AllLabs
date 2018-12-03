#pragma once

template <class T>
class TMonomial
{
protected:
	int* Power;
	int Size;
	double Coeff;
	TMonomial *Next;
public:
	TMonomial(int _Size, int *M, double _Coeff, TMonomial *_Next);
	TMonomial(TMonomial<T> &A);
	void SetPower(int *M);
	void SetSize(int _Size);
	void SetCoeff(double _Coeff);
	void SetNext(TMonomial* _Next);
	int *GetPower();
	int GetSize();
	double GetCoeff();
	TMonomial* GetNext();
	TMonomial &operator = (TMonomial &A);
	TMonomial operator + (TMonomial &A);
	TMonomial operator - (TMonomial &A);
	TMonomial operator * (TMonomial &A);
	bool operator == (TMonomial &A);
	bool operator < (TMonomial &A);
	bool operator > (TMonomial &A);

	friend istream& operator>>(istream &in, TMonomial &m)
	{
		in >> m.Coeff >> m.Power;
		return in;
	}
	friend ostream& operator<<(ostream &out, TMonomial &m)
	{
		out << m.GetCoeff() << ' ' << m.GetPower();
		return out;
	}
};

//------------------------------------------------------------------
template <class T>
TMonomial<T>::TMonomial(int _Size, int *M, double _Coeff, TMonomial *_Next)
{
	if (_Size > 999999)
	{
		throw "Int overflow";
	}
	else
	{
		if (_Size <= 0) throw "Wrong";
		else Size = _Size;
		Coeff = _Coeff;
		Power = M;
		Next = _Next;
	}
}
//------------------------------------------------------------------
template <class T>
TMonomial<T>::TMonomial(TMonomial<T> &A)
{
	Size = A.Size;
	Power = new int[Size];
	for (int i = 0; i < Size; i++)
		Power[i] = A.Power[i];
	Coeff = A.Coeff;
	Next = A.Next;
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetPower(int *M)
{
	try
	{
		for (int i = 0; i < Size; i++)
		{
			if (M[i] >= 0)
				Power[i] = M[i];
			else
				throw - 1;
		}
	}
	catch (..)
	{
		throw - 2;
	}
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetSize(int _Size)
{
	if (_Size <= 0)
		throw "Wrong";
	else
	{
		Size = _Size;
		TMonomial temp;
		if (_Size == Size)
		{
			temp = *this;
		}
		else if (_Size < Size)
		{
			temp.Power = new int[_Size];
			for (int i = 0; i < _Size; i++)
				temp.Power[i] = Power[i];
			delete[]Power;
			Size = _Size;
			Power = new int[Size];
			for (int i = 0; i < Size; i++)
				Power[i] = temp.Power[i];
		}
		else if (_Size > Size)
		{
			temp.Power = new int[Size];
			for (int i = 0; i < Size; i++)
				temp.Power[i] = Power[i];
			delete[]Power;
			Size = _Size;
			Power = new int[Size];
			for (int i = 0; i < Size; i++)
				Power[i] = temp.Power[i];
		}
	}
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetCoeff(double _Coeff)
{
	Coeff = _Coeff;
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetNext(TMonomial* _Next)
{

}
//------------------------------------------------------------------
template <class T>
int *TMonomial<T>::GetPower()
{
	return Power;
}
//------------------------------------------------------------------
template <class T>
int TMonomial<T>::GetSize()
{
	return Size;
}
//------------------------------------------------------------------
template <class T>
double TMonomial<T>::GetCoeff()
{
	return Coeff;
}
//------------------------------------------------------------------
template <class T>
TMonomial* TMonomial<T>::GetNext()
{
	return Next;
}
//------------------------------------------------------------------
template <class T>
TMonomial &TMonomial<T>::operator = (TMonomial &A)
{
	Coeff = A.Coeff;
	delete[]Index;
	Size = A.Size;
	Index = new int[Size];
	for (int i = 0; i < Size; i++)
		Index[i] = A.Inde[i];
	Next = A.Next;
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial<T>::operator + (TMonomial &A)
{
	TMonomial temporary(*this);
	if (Size != A.Size)
		throw "Wrong";
	else
	{
		for (int i = 0; i < Size; i++)
			if (Index[i] != A.Index[i])
				throw "Wrong";
		temporary.Coeff = Coeff + A.Coeff;
		return temporary;
	}
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial<T>::operator - (TMonomial &A)
{
	TMonomial temporary(*this);
	if (Size != A.Size)
		throw "Wrong";
	else
	{
		for (int i = 0; i < Size; i++)
			if (Index[i] != A.Index[i])
				throw "Wrong";
		temporary.Coeff = Coeff - A.Coeff;
		return temporary;
	}
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial<T>::operator * (TMonomial &A)
{
	TMonomial temporary(*this);
	if (Size != A.Size)
		throw "Wrong";
	else
	{
		Coeff = Coeff * A.Coeff;
		for (int i = 0; i < Size; i++)
			temporary.Index[i] = Index[i] + A.Index[i];
		return temporary;
	}
}
//------------------------------------------------------------------
template <class T>
bool TMonomial<T>::operator == (TMonomial &A)
{
	if (Size == A.Size)
	{
		for (int i = 0; i < Size; i++)
			if (Index[i] != A.Index[i])
				return false;
		return true;
	}
	else
		return false;
}
//------------------------------------------------------------------
template <class T>
bool TMonomial<T>::operator < (TMonomial &A)
{
	if (Size != A.Size)
		throw "Wrong";
	for (int i = 0; i < Size; i++)
		if (Index[i] > A.Index[i])
			return false;
	return true;
}
//------------------------------------------------------------------
template <class T>
bool TMonomial<T>::operator > (TMonomial &A)
{
	if (Size != A.Size)
		throw "Wrong";
	for (int i = 0; i < Size; i++)
		if (Index[i] < A.Index[i])
			return false;
	return true;
}
//------------------------------------------------------------------