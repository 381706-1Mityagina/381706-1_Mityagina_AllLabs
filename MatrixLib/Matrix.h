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
  TMatrix operator/(TMatrix<T> &A);
  TMatrix<T> op();

  TVector<T>& operator[](int i);
  double Determinant();
  TMatrix<T> SubMatrix(int i1, int j1);
	//TMatrix<T> InverseMatrix();
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
//-------------------------------------------------------------------------------------------------
template <class T>
double TMatrix<T>::Determinant()
{
	double det = 0;
	// определитель 1-ого порядка совпадает
	// с единственным элементом матрицы
	if (dlina == 1)
		return vector[0][0];
	TMatrix<T> temp(dlina - 1);
	// раскладываем определитель по 0-ой строке
	for (int j = 0; j < dlina; j++)
	{
		// получаем матрицу для вычисления
		// минора элемента a0j
		temp = SubMatrix(0, j);
		// добавляем очередное произведение элемента
		// на его алгебраическое дополнение
		if (j % 2 == 0)
			det += temp.Determinant() * vector[0][j];
		else
			det -= temp.Determinant() * vector[0][j];
	}
	return det;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::SubMatrix(int i1, int j1)
{
	// матрица-результат имеет
	// порядок на 1 меньше исходной
	TMatrix<T> temp(dlina - 1);
	// формируем новую матрицу, игнорируя
	// строку с номером i1 и столбец с номером j1
	for (int i = 0; i < i1; i++)
	{
		for (int j = 0; j < j1; j++)
			temp.vector[i][j] = vector[i][j];
		for (int j = j1 + 1; j < dlina; j++)
			temp.vector[i][j - 1] = vector[i][j];
	}
	for (int i = i1 + 1; i < dlina; i++)
	{
		for (int j = 0; j < j1; j++)
			temp.vector[i - 1][j] = vector[i][j];
		for (int j = j1 + 1; j < dlina; j++)
			temp.vector[i - 1][j - 1] = vector[i][j];
	}
	return temp;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::op()
{
	int n = this->dlina;
	TMatrix<T> res(n);
	// вычисление определителя матрицы
	double det = this->Determinant();
	// если матрица вырожденная,
	// обратной матрицы не существует
	if (det == 0)
		throw 1;
	//ZeroDevideException();
	// вычисление транспонированной матрицы
	// алгебраических дополнений
	TMatrix<T> temp(n - 1);
	int z;
	for (int i = 0; i < n; i++)
	{
		z = i % 2 == 0 ? 1 : -1;
		for (int j = 0; j < n; j++)
		{
			temp = SubMatrix(i, j);
			res[j][i] = z * temp.Determinant() / det;
			z = -z;
		}
	}
	return res;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T>& TMatrix<T>::operator[](int i)
{
	if (i < 0 || i >= dlina)
		throw 1;
	//assert(vector[i] != 0);
	return TVector<TVector<T> >::operator[](i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator/(TMatrix<T> &A)
{
	if (A.Determinant() == 0)
		throw 0;
	else
	{
		TMatrix<T> B = *this;
		TMatrix<T> Rez(this->dlina);
		Rez = B * A.op();
		return Rez;
	}
}
//-------------------------------------------------------------------------------------------------
