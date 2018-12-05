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
TPolinomial::TPolinomial(TPolinomial &A)
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
      
  }
}
