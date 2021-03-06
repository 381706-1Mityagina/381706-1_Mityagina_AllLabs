#include <iostream>
#include "..//stackL/Stack.h"
#include "../Exception/Exception.h"

template <class T>
class TNewStack :public TStack<T> 
{
public:
  TNewStack(int _size = 0, T* _mas = 0);     // êîíñòðóêòîð
  TNewStack(TNewStack <T> &NS);              // êîíñòðóêòîð êîïèðîâàíèÿ
  int GetFreeMemory();                       // ïîëó÷åíèå ñâîáîäíîé ïàìÿòè (êîë-âî ñâîáîäíûõ ïîçèöèé)
  int GetSize();                             // ïîëó÷åíèå ðàçìåðà
  int GetTop();                              // ïîëó÷åíèå ïåðâîãî ýëåìåíòà
  void SetMas(int _size, T* _mas);           // çàäàòü ìàññèâ 
  void Put(T _A);                            // ïîëîæèòü ýëåìåíò  
  T Get();                                   // ïîëó÷èòü çíà÷åíèå ýëåìåíòà
  ~TNewStack();
};
//--------------------------------------------------------------------------
template <class T>
TNewStack<T>::~TNewStack()
{
  TStack<T>::top = 0;
  TStack<T>::size = 0;
  delete[] TStack<T>::mas;
}
//--------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(int _size, T* _mas)
{
  if (_size <= 0) 
    throw TException("Unacceptable size");
  TStack<T>::size = _size;
  TStack<T>::top = 0;
  if (_mas == 0) 
    TStack<T>::mas = 0;
  else
    TStack<T>::mas = _mas;
}
//--------------------------------------------------------------------------
template <class T>
TNewStack<T>::TNewStack(TNewStack <T> &NS)
{
  TStack<T>::size = NS.TStack<T>::size;
  TStack<T>::top = NS.TStack<T>::top;
  if (NS.TStack<T>::mas == 0) TStack<T>::mas = 0;
  else
    TStack<T>::mas = NS.TStack<T>::mas;
}
//--------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetFreeMemory()
{
  return (TStack<T>::size - TStack<T>::top);
}
//--------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetSize()
{
  return TStack<T>::size;
}
//--------------------------------------------------------------------------
template <class T>
int TNewStack<T>::GetTop()
{
  return TStack<T>::top;
}
//--------------------------------------------------------------------------
template <class T>
void TNewStack<T>::SetMas(int _size, T* _mas)
{
  if (_size <=0)
    throw TException("Unacceptable size");
  TStack<T>::size = _size;
  TStack<T>::mas = _mas;
}
//--------------------------------------------------------------------------
template <class T>
void TNewStack<T>::Put(T _A)
{
  TStack<T>::mas[TStack<T>::top] = _A;
  TStack<T>::top++;
}
//--------------------------------------------------------------------------
template <class T>
T TNewStack<T>::Get()
{
  TStack<T> :: top--;
  return TStack<T> :: mas[TStack<T> :: top];
}
//--------------------------------------------------------------------------
//                                                                        //
//                     class TMStack                                      //
//                                                                        //
//--------------------------------------------------------------------------
template <class T>
class TMStack 
{
protected:
  int size;                          // ðàçìåð 
  T* mas;                            // ìàññèâ ýëåìåíòîâ
  int n;                             // êîë-âî ñòåêîâ
  TNewStack<T>** newS;               // ìàññèâ óêàçàòåëåé
  int GetFreeMemory();               // ïîëó÷èòü ñâîáîäíóþ ïàìÿòü 
  void Repack(int k);                // ïåðåïàêîâêà

public:
  TMStack(int _n, int _size);        // êîíñòðóêòîð èíèöèàëèçàöèè
  TMStack(TMStack<T> &A);            // êîíñòðóêòîð êîïèðîâàíèÿ

  ~TMStack();

  int GetSize()                      // ïîëó÷èòü ðàçìåð
  {
    return size; 
  }

  T Get(int _n);                     // âçÿòü çíà÷åíèå èç n-îãî ñòåêà

  void Set(int _n, T p);             // ïîëîæèòü çíà÷åíèå â _n-ûé ñòåê

  bool IsFull(int _n);               // ïðîâåðêà ñòåêà íà ïîëíîòó 
  bool IsEmpty(int _n);              // ïðîâåðêà ñòåêà íà ïóñòîòó 
};
//--------------------------------------------------------------------------
template <class T>
TMStack<T> ::TMStack(int _n, int _size)
{
  if (_n <= 0 || _size <= 0)
    throw TException ("Negative leight, unfortunatelly");

  n = _n; 
  size = _size; 

  newS = new TNewStack<T> *[n];
  mas = new T[size]; 

  int* smth = new int[n];

  smth[0] = int(double(size) / n) + (size % n);

  for (int i = 1; i < n; i++)
    smth[i] = int(double(size) / n);

  newS[0] = new TNewStack<T>(smth[0], &mas[0]);

  for (int i = 1; i < n; i++)
  {
    int temp = smth[0] + (i - 1)*smth[i];
    newS[i] = new TNewStack<T>(smth[i], &mas[temp]);
  }
}
//--------------------------------------------------------------------------
template <class T>
TMStack<T> ::TMStack(TMStack &A)
{
  size = A.size;
  n = A.n;

  mas = new T[size];
  newS = new TNewStack<T> *[n];

  for (int i = 0; i < size; i++)
    mas[i] = A.mas[i];

  int* smth = new int[n];

  for (int i = 0; i < n; i++)
    smth[i] = A.newS[i]->TNewStack<T>::GetSize();

  int countingSize = 0;
  newS[0] = new TNewStack<T>(*(A.newS[0]));
  newS[0]->TNewStack<T>::SetMas(smth[0], mas);
  for (int i = 1; i < n; i++)
  {
    newS[i] = new TNewStack<T>(*(A.newS[i]));

    int temp = smth[0] + countingSize;

    newS[i]->TNewStack<T>::SetMas(smth[i], &mas[temp]);
    countingSize += smth[i];
  }
}
//--------------------------------------------------------------------------
template <class T>
TMStack<T> ::~TMStack()
{
  n = 0;
  size = 0;
  delete[]newS;
  delete[]mas;
}
//--------------------------------------------------------------------------
template<class T>
void TMStack<T>::Set(int _n, T p)
{
  if (IsFull(_n))
    Repack(_n);

  newS[_n]->Put(p);
}
//--------------------------------------------------------------------------
template<class T>
T TMStack<T>::Get(int _n)
{
  if (IsEmpty(_n))
    throw TException("Empty, unfortunatelly");

  return newS[_n] -> Get();
}
//--------------------------------------------------------------------------
template<class T>
bool TMStack<T>::IsFull(int _n)
{
  return (newS[_n]->GetFreeMemory() <= 0);
}
//--------------------------------------------------------------------------
template<class T>
bool TMStack<T>::IsEmpty(int _n)
{
  return (newS[_n]->GetFreeMemory() == newS[_n]->GetSize());
}
//--------------------------------------------------------------------------
template <class T>
int TMStack<T>::GetFreeMemory()
{
  int count = 0;

  for (int i = 0; i < n; i++)
  {
    count += newS[i]->GetFreeMemory();
  }

  return count;
}
//--------------------------------------------------------------------------
template <class T>
void TMStack<T>::Repack(int k)
{
  cout << "\tRepacking ..." << endl;

  int FreeForNow = GetFreeMemory();
  int eq_add = FreeForNow / n;
  int full_add = FreeForNow % n;

  int* sizeNewOne = new int[n];
  T** startNewOne = new T*[n];
  T** startOldOne = new T*[n];

  for (int i = 0; i < n; i++)
    sizeNewOne[i] = eq_add + newS[i]->GetTop();
	
  sizeNewOne[k] += full_add;
  startNewOne[0] = startOldOne[0] = mas;

  for (int i = 1; i < n; i++)
  {
    startNewOne[i] = startNewOne[i - 1] + sizeNewOne[i - 1];
    startOldOne[i] = startOldOne[i - 1] + newS[i - 1]->GetSize();
  }

  for (int i = 0; i < n; i++)
  {
    if (startNewOne[i] <= startOldOne[i])
      for (int j = 0; j < newS[i]->GetTop(); j++)
        startNewOne[i][j] = startOldOne[i][j];

    else
    {
      int s = i + 1;

      for (s; s < n; s++)
        if (startNewOne[s] <= startOldOne[s])
          break;

      for (int j = s - 1; j >= i; j--)
        for (int r = newS[j]->GetTop() - 1; r >= 0; r--)
          startNewOne[j][r] = startOldOne[j][r];

      i = s - 1;
      }
  }

  for (int i = 0; i < n; i++)
    newS[i]->SetMas(sizeNewOne[i], startNewOne[i]);

  delete[] sizeNewOne;
  delete[] startNewOne;
  delete[] startOldOne;
}
//--------------------------------------------------------------------------
