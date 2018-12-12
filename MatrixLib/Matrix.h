#pragma once
#include "..//VectorLib/Vectorlib.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000;

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int n = 10); // конструктор инициализации
  TMatrix(const TMatrix &Matr);  // конструктор копирования, принимающий ссылку на объект класса TMatrix                  
  TMatrix(const TVector<TVector<T> > &Matr);  // конструктор копирования, принимающий ссылку на объект класса TVector<TVector<T>		
  bool operator ==(const TMatrix &Matr) const; // перегрузка оператора сравнения (на равенство)
  bool operator !=(const TMatrix &Matr) const; // перегрузка оператора сравнения (на неравенство)
  TMatrix& operator = (TVector<TVector<T> > &Matr); // перегрузка оператора =
  TMatrix  operator + (const TMatrix &Matr); // перегрузка оператора +
  TMatrix  operator - (const TMatrix &Matr); // перегрузка оператора -
  TMatrix operator*(TMatrix<T> &A); // перегрузка оператора *
	TVector<T>& operator[](int i);
	double Determinant(TMatrix<T> &A, int N);
	TMatrix<T> InverseMatrix();
	TMatrix operator/(TMatrix<T> &A);
	
// операторы ввода-вывода												
  template <class FriendT> friend istream& operator>>(istream &istr, TMatrix<FriendT> &Matr);
 
  template <class FriendT> friend ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr);
 
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int n) : TVector<TVector<T> >(n)
{
  int a = MAX_SIZE;
  if (n < 0 || n > a)
	throw TException("Overflow");
  else
	for (int i = 0; i < n; i++)
	  this->vector[i]= TVector <T>(n - i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &Matr) :TVector<TVector<T> >(Matr) { }
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &Matr) : TVector<TVector<T> >(Matr) { }
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
	throw TException("Different dimensions.");
  else
	return TVector<TVector<T> > :: operator+(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &Matr)
{
  if (this->dlina != Matr.dlina)
	throw TException("Different dimensions.");
  else
	return TVector<TVector<T> > :: operator-(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  istream& operator>>(istream &istr, TMatrix<FriendT> &Matr)
{
  for (int i = 0; i < Matr.dlina; i++)
	istr >> Matr.vector[i];
  return istr;
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr)
{ 
		for (int i = 0; i < Matr.dlina; i++)
		{
			for (int j = 0; j < i; j++)
				ostr << "\t";
			ostr << Matr.vector[i] << endl;
		}
		return ostr;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(TMatrix<T> &A)
{
	if (this -> dlina != A.dlina)
           throw TException("Error! Differen dimentions.");
	
	int _size = this->dlina;
	TMatrix <T> result(_size);
	for (int row = 0; row < _size; row++) // проходим по строкам
		for (int col = row; col < _size; col++) // проходим по столбцам
		{
			for (int inner = row; inner <= col; inner++)
				result.vector[row][col - row] += this->vector[row][inner - row] * A.vector[inner][col - inner];
		}
	return result;
}
//-------------------------------------------------------------------------------------------------
template <class T>
double TMatrix<T>:: Determinant(TMatrix<T> &A, int N)   // Определитель матрицы 
{
	N = A.dlina;
		int i, j;
		TMatrix<T> matr1(N);
		/* int sign=1;*/
		double determ = 0;

		if (N == 2)
		{
			determ = A[0][0] * A[1][1] - A[0][1] * A[1][0];
		}
		else
		{
			//TMatrix<T> matr1(N - 1);
			for (i = 0; i<N; i++)
			{
				for (j = 0; j<N - 1; j++)
				{
					if (j<i) { matr1[j] = A[j]; }
					else { matr1[j] = A[j + 1]; }
				}
				determ += pow(-1, (i + j)) * Determinant(matr1, N - 1) * A[i][N - 1];
			}
			//delete matr1;
		}

		return determ;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>:: InverseMatrix()   // Обратная матрица
{
	double det = Determinant(*this, this->dlina);
	if (det == 0)
		throw TException ("Cannot be equal to 0");

	int _n = this -> dlina;
	TMatrix<T> B(_n), invA(_n);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			int sign = ((i + j) % 2 == 0) ? 1 : -1;
			
			for (int m = 0; m < j; m++)
			{
				for (int n = 0; n < i; n++)   B.vector[m][n] = this->vector[m][n];
				for (int n = i + 1; n < _n; n++) B.vector[m][n - 1] = this->vector[m][n];
			}
			for (int m = j + 1; m < _n; m++)
			{
				for (int n = 0; n < i; n++)   B.vector[m - 1][n] = this->vector[m][n];
				for (int n = i + 1; n < _n; n++) B.vector[m - 1][n - 1] = this->vector[m][n];
			}
			invA[i][j] = sign * Determinant(B, B->dlina) / det;
		}
	}
	return invA;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T>& TMatrix<T>::operator[](int i)
{
	if (i < 0 || i >= this->dlina)
		throw TException("Overflow");
	else
		return TVector<TVector<T> >::operator[](i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &A)
{
if (A.Determinant() == 0)
  throw TException("Cannot be 0");
else
{ 
	TMatrix<T> Rez(this->dlina);
	Rez = this*A.InverseMatrix();
	return Rez;
}
}
//-------------------------------------------------------------------------------------------------
