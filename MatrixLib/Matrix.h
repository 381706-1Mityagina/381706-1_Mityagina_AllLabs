/* #pragma once
#include "..//VectorLib/Vectorlib.h"
#include <iostream>

#define MAX_SIZE 10000;

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int n = 10);
  TMatrix(const TMatrix &Matr);                    
  TMatrix(const TVector<TVector<T> > &Matr);			
  bool operator ==(const TMatrix &Matr) const;
  bool operator !=(const TMatrix &Matr) const;
  TMatrix& operator = (TVector<TVector<T> > &Matr);
  TMatrix  operator + (const TMatrix &Matr);
  TMatrix  operator - (const TMatrix &Matr);
												
  template <class FriendT> friend istream& operator>>(istream &istr, TMatrix<FriendT> &Matr);
 
  template <class FriendT> friend ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr);
 
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int n) : TVector<TVector<T> >(n)
{
  int a = MAX_SIZE;
  if (n < 0 || n > a)
	throw 1;
  else
	for (int i = 0; i < n; i++)
	  this->Vector[i]= TVector <T>(n - i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &Matr) : TVector<TVector<T> >(Matr) {}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &Matr) : TVector<TVector<T> >(Matr) {}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &Matr) const
{
  return TVector<TVector<T> >::operator==(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &Matr) const
{
  return TVector<TVector<T> >::operator!=(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(TVector<TVector<T> > &Matr)
{
  TVector<TVector<T> >::operator=(Matr);
  return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &Matr)
{
  if (this -> dlina != Matr.dlina)
	throw 1;
  else
	return TVector<TVector<T> > :: operator+(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &Matr)
{
  if (this->dlina != Matr.dlina)
	throw 1;
  else
	return TVector<TVector<T> > :: operator-(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  istream& operator>>(istream &istr, TMatrix<FriendT> &Matr)
{
  for (int i = 0; i < Matr.dlina; i++)
	istr >> Matr.Vector[i];
  return istr;
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr)
{
  for (int i = 0; i < Matr.dlina; i++)
	ostr << Matr.Vector[i] << endl;
  return ostr;
}
//-------------------------------------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& Matr)
{
Matrix<T> TmpMatr(Matr.Size);
for (int i=0;i<Matr.Size;i++)
for (int j=0;j<(i+1);j++)
for (int k=j;k<(i+1);k++)
	
TmpMatr[j][i]+=M[j][k]*Matr[k][i];

return TmpMatr;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator*=(const TMatrix<T>& Matr)
{
TMatrix<T> TmpMatr(TMatr.Size);
for (int i=0;i<Size;i++)
for (int j=0;j<Size;j++)
for (int k=0;k<Size;k++)

TmpMatr[i][j]+=M[i][k]*Matr[k][j];

for (int i=0;i<Size;i++)
for (int j=0;j<Size;j++)
M[i][j]=TmpMatr[i][j];

return *(this);
}
//------------------------------------------------------------------------------------------------- */
#pragma once
#include "..//VectorLib/Vectorlib.h"
#include <iostream>

using namespace std;

template <class T>
class TMatrix : public TVector<T>
{
protected:
	int MSize; 
public:
	TMatrix();
	TMatrix(int _MSize);
	TMatrix(TMatrix<T> &A);
	TMatrix(const TVector <T> &A);
	~TMatrix();
	TVector<T> operator [](int _I);
	TMatrix<T> operator +(TMatrix<T> &A);
	TMatrix<T> operator -(TMatrix<T> &A);
	TMatrix<T>& operator =(const TMatrix<T> &A);
	bool operator ==(const TMatrix &A) const;
	TMatrix<T> operator*(const TMatrix<T>& Matr);
	TMatrix<T>& operator*=(const TMatrix<T>& Matr);
	int GetMSize();

	template <class T1>
	friend istream& operator >>(istream &istr, TMatrix<T1> &A)
	{
		for (int i = 0; i < A.TVector<T1>::Size; i++)
			istr >> A.TVector<T1>::Vector[i];
		return istr;
	}
	
	template <class T1>
	friend ostream& operator <<(ostream &ostr, TMatrix<T1> &A)
	{
		for (int i = 0; i < A.TVector<T1>::Size; i++)
			ostr << A.TVector<T1>::Vector[i] << endl;
		return ostr;
	}
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> :: TMatrix() 
{
	TVector<T>::Size = 0;
	MSize = 0;
	TVector<T>::Vector = 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> :: TMatrix(int _MSize) 
{
	if (_MSize >= 0)
	{
		TVector<T>::Size = _MSize * (_MSize + 1) / 2;
		MSize = _MSize;
		if (TVector<T>::Size != 0)
		{
			TVector<T>::Vector = new T[TVector<T>::Size];
			for (int i = 0; i < TVector<T>::Size; i++)
			{
				TVector<T>::Vector[i] = 0;
			}
		}
		else
			TVector<T>::Vector = 0;
	}
	else
		throw "WRONG";
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> :: TMatrix(TMatrix<T> &A) 
{
	TVector<T>::Size = A.TVector<T>::Size;
	MSize = A.MSize;
	TVector<T>::Vector = new T [TVector<T>::Size];
	for (int i = 0; i < TVector<T>::Size; i++)
	{
		TVector<T>::Vector[i] = A.TVector<T>::Vector[i];
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> :: TMatrix(const TVector<T> &A) 
{
	TVector<T>::Size = A.TVector<T>::Size;
	for (int i = 0; i < TVector<T>::Size; i++)
		TVector<T>::Vector[i] = A.TVector<T>::Vector[i];
	int i = 1, s = TVector<T>::Size;
	while (s != 0) 
	{
		TVector<T>::Size = TVector<T>::Size - i;
		i++;
	}
	MSize = i - 1;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> :: ~TMatrix()
{
	MSize = 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T> TMatrix<T> :: operator [](int _Index)
{
	TVector<T> A(MSize);
	for (int i = 0; i <_Index; i++)
		A[i] = 0;
	int tmp = _Index;
	for (int i = MSize * (MSize + 1) / 2 - _Index * (_Index + 1) / 2; i < MSize; i++)
	{
		A[tmp] = TVector<T>::Vector[i];
		tmp++;
	}
	return A;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T>& TMatrix<T> :: operator=(const TMatrix<T> &A) 
{
	if (this != &A) 
	{
		if (TVector<T>::Size != A.TVector<T>::Size)
		{
			delete [] TVector<T>::Vector;
			
			if (A.TVector<T>::Size != 0)
				TVector<T>::Vector = new T [A.TVector<T>::Size];
			else
				TVector<T>::Vector = 0;
		}
		TVector<T>::Size = A.TVector<T>::Size;
		MSize = A.MSize;
		
		for (int i = 0; i < TVector<T>::Size; i++)
			TVector<T>::Vector[i] = A.TVector<T>::Vector[i];
	}
	return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T> 
TMatrix<T> TMatrix<T> :: operator+ (TMatrix<T> &A)
{
	TMatrix<T> Rez (MSize);
	if (TVector<T>::Size == A.TVector<T>::Size)
	{
		for (int i = 0; i < TVector<T>::Size; i++)
			Rez.TVector<T>::Vector[i] = TVector<T>::Vector[i] + A.TVector<T>::Vector[i];
		return Rez;
	}
	else
		throw "WRONG";
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T> :: operator- (TMatrix<T> &A)
{
	TMatrix<T> Rez(MSize);
	if (TVector<T>::Size == A.TVector<T>::Size)
	{
		for (int i = 0; i < TVector<T>::Size; i++)
			Rez.TVector<T>::Vector[i] = TVector<T>::Vector[i] - A.TVector<T>::Vector[i];
		return Rez;
	}
	else
		throw "WRONG";
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T> :: operator ==(const TMatrix &A) const
{
	if (TVector<T>::Size == A.TVector<T>::Size && MSize == A.MSize)
	{
		for (int i = 0; i < TVector<T>::Size; i++)
		{
			if (TVector<T>::Vector[i] != A.TVector<T>::Vector[i])
				return 0;
		}
		return 1;
	}
	else
		throw "WRONG";
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& Matr)
{
TMatrix<T> TmpMatr(Matr.MSize);
for (int i=0; i < Matr.MSize; i++)
for (int j=0; j < (i+1); j++)
for (int k=j; k < (i+1); k++)
TmpMatr[j][i] += M[j][k]*Matr[k][i];

return TmpMatr;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator*=(const TMatrix<T>& Matr)
{
TMatrix<T> TmpMatr(Matr.MSize);
for (int i=0;i<MSize;i++)
for (int j=0;j<MSize;j++)
for (int k=0;k<MSize;k++)
TmpMatr[i][j]+=M[i][k]*Matr[k][j];

for (int i=0;i<MSize;i++)
for (int j=0;j<MSize;j++)
M[i][j]=TmpMatr[i][j];

return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
int TMatrix<T> :: GetMSize()
{
	return MSize;
}
//-------------------------------------------------------------------------------------------------
