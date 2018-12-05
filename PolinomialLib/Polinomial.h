#pragma once

#include "..//MonomialLib/Monomial.h"

class TPolinomial
{
protected:
  TMonomial *Mass;
  int Size, N;
public:
  TPolinomial(int _N = 10);
  TPolinomial(TPolinomial &A);
  TPolinomial operator + (TPolinomial &A);
  TPolinomial operator - (TPolinomial &A);
  TPolinomial operator * (TPolinomial &A);
  TPolinomial &operator = (TPolinomial &A);
  TPolinomial &operator += (TPolinomial &A);
};

//----------------------------------------------------------------------
TPolinomial::TPolinomial(int _N = 10)
{
  if (_N < 0)
    throw "Negative";
  else
  {
    N = _N; 
    Size = 0;
    Mass = 0;
  }
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial:: operator =(TPolinomial &A)
{
  if (A = this)
    return this;
  if (A.N != this -> N) throw -1;
  else 
  {
    TMonomial *Buf1 = a, *Buf2 = a;
    while (Buf1 != 0)
    {
      Buf1 = Buf1.GetNext();
      delete [] Buf2;
      Buf2 = Buf1;
    }
    Buf1 = A.Mass; Buf2 = new TMonomial(*A.Mass);
    Mass = Buf2;
    while (Buf1 != 0)
    {
     Buf2 -> SetNext(new TMonomial(Buf1));
     Buf1 = Buf1.GetNext();
    }
    return *this;
  }
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator + (TPolinomial &A)
{
  if (this -> N != A.N) 
    throw 1;
  TMonomial *i1 = Mass, *i2 = A.Mass;
  TPolinomial Rez(N);
  TMonomial *i = Rez.Mass;
  while (i1 != 0 && i2 != 0)
  {
    TMonomial *tmp = NULL;
    if (*i1 == *i2)
      {
        tmp = new TMonomial(*i1 + *i2);
        i1 = i1.GetNext();
        i2 = i2.GetNext();
      }
    if (*i1 > *i2)
      {
        tmp = new TMonomial(*i1);
        i1 = i1.GetNext();
      }
    if (*i1 < *i2)
      {
        tmp = new TMonomial(*i2);
        i2 = i2.GetNext();
      }
    if (i == 0)
    {
      i = tmp;
      Rez.Mass = i;
    }
    else 
      i -> SetNext(tmp);
    Rez.Size++;
  }
  if (i1 == 0)
    i1 = i2;
  while (i1 != 0)
  {
    i -> SetNext(new TMonomial(i1));
    Rez.Size++;
  }
  i1 = i1.GetNext();
  return Rez;
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator - (TPolinomial &A)
{
  if (this -> N != A.N) 
    throw 1;
  TMonomial *i1 = Mass, *i2 = A.Mass;
  TPolinomial Rez(N);
  TMonomial *i = Rez.Mass;
  while (i1 != 0 && i2 != 0)
  {
    TMonomial *tmp = NULL;
    if (*i1 == *i2)
      {
        tmp = new TMonomial(*i1 - *i2);
        i1 = i1.GetNext();
        i2 = i2.GetNext();
      }
    if (*i1 > *i2)
      {
        tmp = new TMonomial(*i1);
        i1 = i1.GetNext();
      }
    if (*i1 < *i2)
      {
        tmp = new TMonomial(*i2);
        i2 = i2.GetNext();
      }
    if (i == 0)
    {
      i = tmp;
      Rez.Mass = i;
    }
    else 
      i -> SetNext(tmp);
    Rez.Size++;
  }
  if (i1 == 0)
    i1 = i2;
  while (i1 != 0)
  {
    i -> SetNext(new TMonomial(i1));
    Rez.Size++;
  }
  i1 = i1.GetNext();
  return Rez;
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator * (TPolinomail &A)
{
 if (N != A.N)
   throw -1;
 else
 {
   TMonomial* Sum;
   TPolinomial Rez(N);
   TMonom *i1 = Mass;
   TMonom *i2 = A.Mass;
   while (i1 != 0) 
   {
     while (i2 != 0)
    {
     Sum = new TMonomial((*i1)*(*i2));
     Rez += Sum;
     i2 = i2 -> GetNext();
    }
   i1 = i1 -> GetNext();
   }
 }
  return Rez;
}
//----------------------------------------------------------------------
TPolinomial::TPolinomial(TPolinomail &A)
{
  Size = A.Size;
  N = A.N;
  if (A.Mass == 0)
    Mass = 0;
  else 
    tMonomial *tmp = new TMonomial(*A.Mass);
  TMonomial *Buf = A.Mass;
  Mass = tmp;
  while (Buf != 0)
  {
    tmp -> SetNext (new TMonomial(Buf));
    Buf = Buf.GetNext();
  }
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial:: operator += (TPolinomail &A)
{
  if (N != A.N)
    throw -1;
	TMonomial *_start, *_end;
	_start = Mass;
	_end = Mass -> getnext();
	if (Mass == 0) // если полином пуст
	{
		Mass = new TMonomial(A);
		end = Mass;
	}
	else 
	{
		if (Mass < A) // если моном меньше, чем первый член полинома
		{
			TMonom* tmp = new TMonomial(A);
			tmp->SetNext(Mass);
			Mass = tmp;
		}
		else 
		{
			while (_end != 0)// пробегаемся по всему полиному
			{
				if (_start < A && A < _end)
				{
					TMonom* tmp = new TMonomial(A);
					_start -> GetNext();
					tmp -> SetNext(_end);
					break;
				}
				_start = _end;
				_end = _end -> GetNext();
			}
			if (_end == 0)
			{
				Mass->SetNext(new TMonomial(A));
				end = start->getnext();
			}
		}
	}
	return *this;
}
//----------------------------------------------------------------------
