#pragma once
#include "..//VectorLib/Vector.h"
template <class T>
class Matrix
{
private:
  Vector<T> *M;
  int Size;
public:
  Matrix(int _Size = 20);
  ~Matrix();
  Matrix(const Matrix<T>& Matr);
  Matrix<T>& operator=(const Matrix<T>& Matr);
  Vector<T>& operator[](int i);
  const Vector<T>& operator[](int i) const;
  Matrix<T> operator+(const Matrix<T>& Matr);
  Matrix<T>& operator+=(const Matrix<T>& Matr);
  Matrix<T> operator-(const Matrix<T>& Matr);
  Matrix<T>& operator-=(const Matrix<T>& Matr);
  Matrix<T> operator*(const Matrix<T>& Matr);
  Matrix<T>& operator*=(const Matrix<T>& Matr);
};

//Верхнетреугольные матрицы
//template <class ValType>
//class TMatrix : public TVector<TVector<ValType> > {
//public:
//  TMatrix(int s = 10); // (#О1)
//  TMatrix(const TMatrix &mt); // копирование (#Л1)
//  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа (#Л2)
//  TMatrix & operator==(const TMatrix &mt); // сравнение (#П1)
//  TMatrix & operator= (const TMatrix &mt); // присваивание (#О2)
//  TMatrix operator+ (const TMatrix &mt); // сложение (#П2)
//  TMatrix operator- (const TMatrix &mt); // вычитание (#С1)
//  TMatrix operator* (const TMatrix &mt); // умножение (#С2)
//										 // ввод / вывод
//  friend istream & operator>>(istream &in, TMatrix &mt) { //(#П3)
//
//
//	return in;
//  }
//  friend ostream & operator<<(ostream &out, const TMatrix &mt) { //(#С3)
//
//
//	return out;
//  }
//};
//template <class ValType> //
//TMatrix<ValType> ::TMatrix(int s) : TVector<TVector<ValType> >(s) {
//  for (int i = 0; i < s; i++)
//	pVector[i] = TVector<ValType>(s - i, i);
//}
//template <class ValType> // конструктор копирования
//TMatrix<ValType> ::TMatrix(const TMatrix<ValType> &mt) :
//
//  template <class ValType> // конструктор преобразования типа
//TMatrix<ValType> ::TMatrix(const TVector<TVector<ValType> > &mt) :
//
//  template <class ValType> // присваивание
//TMatrix<ValType> & TMatrix<ValType>::operator=(const TMatrix<ValType> &mt) {
//  if (this != &mt) {
//	if (Size != mt.Size) {
//	  delete[] pVector;
//	  pVector = new TVector<ValType>[mt.Size];
//	}
//	Size = mt.Size; StartIndex = mt.StartIndex;
//	for (int i = 0; i<Size; i++) pVector[i] = mt.pVector[i];
//}
//return *this;
//}
//template <class ValType> // сложение
//TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt) {
//
//}
//// TVector О3 Л2 П4 С6
//// TMatrix О2 Л2 П3 С3
//#endif 
// ---------------------------------------------------------------------------

template <class T>
Matrix<T>::Matrix(int _Size)
{
  Vector<T> Tmp(_Size);
  M = new Vector<T>[_Size];
  Size = _Size;
  for (int i = 0; i<Size; i++)
  {
	Vector<T> tmp(Size - i, i);
	M[i] = tmp;
  }
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T>::~Matrix()
{
  delete[] M;
  M = 0;
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T>::Matrix(const Matrix<T>& Matr)
{
  M = new Vector<T>[Matr.Size];
  Size = Matr.Size;
  for (int i = 0; i<Size; i++)
	M[i] = Matr.M[i];
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& Matr)
{
  if (this != &Matr)
  {
	if (Size != Matr.Size)
	{
	  delete[] M;
	  Size = Matr.Size;
	  M = new Vector<T>[Matr.Size];
	}
	for (int i = 0; i<Size; i++)
	  M[i] = Matr.M[i];
  } 
  return (*this);
}

// ---------------------------------------------------------------------------
template <class T>
Vector<T>& Matrix<T>::operator[](int i)
{
  return (*this).M[i];
}

// ---------------------------------------------------------------------------
template <class T>
const Vector<T>& Matrix<T>::operator[](int i) const
{
  return (*this).M[i];
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& Matr)
{
  Matrix<T> Tmp(Matr.Size);

  for (int i = 0; i<Size; i++)
  {
	for (int j = i; j < Size; j++)
	  Tmp[i][j] = M[i][j] + Matr[i][j];
  }

  return Tmp;
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& Matr)
{
  for (int i = 0; i<Size; i++)
	M[i] += Matr[i];
  return *(this);
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& Matr)
{
  Matrix<T> Tmp(Matr.Size);

  for (int i = 0; i<Size; i++)
  {
	for (int j = i; j < Size; j++)
	  Tmp[i][j] = M[i][j] - Matr[i][j];
  }


  return Tmp;
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& Matr)
{
  for (int i = 0; i<Size; i++)
	M[i] -= Matr[i];
  return *(this);
}

// ---------------------------------------------------------------------------
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& Matr)
{
  Matrix<T> TmpMatr(Matr.Size);
  for (int i = 0; i<Matr.Size; i++)
	for (int j = 0; j<(i + 1); j++)
	  for (int k = j; k<(i + 1); k++)
		TmpMatr[j][i] += M[j][k] * Matr[k][i];
  return TmpMatr;
}
// ---------------------------------------------------------------------------
template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& Matr)
{
  Matrix<T> TmpMatr(Matr.Size);
  for (int i = 0; i<Size; i++)
	for (int j = 0; j<Size; j++)
	  for (int k = 0; k<Size; k++)
		TmpMatr[i][j] += M[i][k] * Matr[k][j];
  for (int i = 0; i<Size; i++)
	for (int j = 0; j<Size; j++)
	  M[i][j] = TmpMatr[i][j];
  return *(this);
}
// ---------------------------------------------------------------------------
