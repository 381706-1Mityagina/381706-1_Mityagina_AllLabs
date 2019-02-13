#include "Poland.h"
#include <cstdlib>

//-------------------------------------------------------------
TString::TString()
{
  mas = 0; size = 0;
}
//-------------------------------------------------------------
TString::TString(TString &A)
{
  size = A.size;
  if (size != 0)
   {
    mas = new char[size];
    //mas[0] = '('; mas[size - 1] = ')';
    for (int i = 0; i < size; i++)
     mas[i] = A.mas[i];
   }
  else mas = 0;
  /*size = A.size + 2;
  if (size != 0)
  {
  mas = new char[size];

  for (int i = 1; i < size - 2; i++)
  mas[i] = A.mas[i];	
  A.mas[A.size - 2] = ')';
  A.mas[A.size- 1] = '\0';
  }
  else mas = 0;*/
}
//-------------------------------------------------------------
TString::TString(char *str)
{
	if (str == 0)
		throw TException("String is empty.");
	if (str[0] == '\0')
		return;
	char smth = 1;
	//char smth;
	int s = 0;

	while (smth != '\0')
	{
		s++; smth = str[s];
	}

	size = s + 1;
	mas = new char[size];
	for (int i = 0; i < size - 1; i++)
		mas[i] = str[i];
	mas[size - 1] = 0;
}
//-------------------------------------------------------------
TString::~TString()
{
	if (mas != 0)
		delete[]mas;
}
//-------------------------------------------------------------
int TString::GetSize()
{
	return size;
}
//-------------------------------------------------------------
TString &TString::operator = (TString &A)
{
	if (this != &A)
	{
		size = A.size;

		if (size != 0)
		{
			if (mas != 0)
				delete[]mas;
			mas = new char[A.size];
			//	mas[0] = '('; mas[size] = ')';
			for (int i = 0; i < A.size; i++)
				mas[i] = A.mas[i];
		}
		else
		{
			if (mas != 0)
				delete[]mas;
			size = 0;
		}
	}
	return *this;
	/*if (this != &A)
	{
	size = A.size + 2;

	if (size != 0)
	{
	if (mas != 0)
	delete[]mas;
	mas = new char[A.size + 2];
	mas[0] = '(';
	for (int i = 1; i < size - 2; i++)
	mas[i] = A.mas[i];
	A.mas[A.size - 2] = ')';
	A.mas[A.size - 1] = '\0';
	}
	else
	{
	if (mas != 0)
	delete[]mas;
	size = 0;
	}
	}
	return *this;*/
}
//-------------------------------------------------------------
TString TString::operator + (TString &A)
{
	TString res;

	res.mas = new char[size + A.size - 1];

	for (int i = 0; i < size - 1; i++)
		res.mas[i] = mas[i];
	for (int i = size - 1; i < size + A.size - 1; i++)
		res.mas[i] = A.mas[i - (size - 1)];
	return res;
}
//-------------------------------------------------------------
istream& operator >> (istream &in, TString &A)
{
	char str[256] = { 0 };
	in >> str;
	char smth = 1;
	//char smth;
	int s = 0;

	while (smth != '\0')
	{
		s++; smth = str[s];
	}

	A.size = s + 1;
	A.mas = new char[A.size];
	for (int i = 0; i < A.size - 1; i++)
		A.mas[i] = str[i];
	A.mas[A.size - 1] = 0;
	return in;

	//char str[256] = { 0 };
	//in >> str;
	//char smth = 1;
	////char smth;
	//int s = 0;

	//while (smth != '\0')
	//{
	//	s++; smth = str[s];
	//}

	//A.size = s + 3;
	//A.mas = new char[A.size];
	//A.mas[0] = '(';
	//for (int i = 1; i < A.size - 2; i++)
	//	A.mas[i] = str[i];
	//A.mas[A.size - 2] = ')';
	//A.mas[A.size - 1] = '\0';
	//return in;
}
//-------------------------------------------------------------
char &TString::operator[](int n)
{
	if ((n >= 0) && (n < size))
		return mas[n];
	else
		throw TException("Unacceptable index");
}
//-------------------------------------------------------------
ostream &operator << (ostream &out, TString &A)
{
	out << A.mas;
	return out;
}
//-------------------------------------------------------------
void TString::Print()
{
	for (int i = 0; i < size; i++)
		cout << mas[i];
	cout << "\n";
}
//-----------------------------------------------------------//
//                                                           //
//                  other methods                            //
//                                                           //
//-----------------------------------------------------------//
bool IsOperation(char symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '(' || symbol == ')');
}
//-------------------------------------------------------------
int GetPriority(const char operation)
{
	switch (operation)
	{
	case '(': return 1;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
		//default: throw TException("Unacceptable symbol");
	default: return 0;
	}
}
//-------------------------------------------------------------
double GettingRez(TQueue<char> queue)
{
	double r;
	TStack <double> St(queue.GetSize());
	if (IsOperation(queue.GetButDontDelQ()))
		throw TException("Shouldnt be here. Queue is uncurr.1");

	while (!queue.IsEmpty())
	{
		char A = queue.Get();
		if (A == '{')
		{
			A = queue.Get();
			double temporary = atof(&A);
			while (!queue.IsEmpty() && queue.GetButDontDelQ() != '}')
			{
				A = queue.Get();
				temporary = temporary * 10 + atof(&A);
			}
			queue.Get();
			St.Put(temporary);
		}
		else if (IsOperation(A))
		{
			double Fi = St.Get(), Sec = St.Get(), Th;

			if (A == '+') Th = Sec + Fi;
			if (A == '-') Th = Sec - Fi;
			if (A == '*') Th = Sec * Fi;
			if (A == '/') Th = Sec / Fi;
			St.Put(Th);
		}
		else
			throw TException("Shouldnt be here .-.");
	}
	r = St.Get();
	if (!St.IsEmpty())
		throw TException("Shouldnt be here. Queue is uncurr.2");
	return r;
}
//-------------------------------------------------------------
TQueue<char> ToPolish(TString str)
{
	int op_sk = 0, cl_sk = 0;
	TQueue<char> Qu(str.GetSize() * 5);
	TStack<char> St(str.GetSize() * 2);

	for (int i = 0; i < str.GetSize(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-')
			{
				Qu.Put('{'); Qu.Put('0'); Qu.Put('}');
			}

			else if (IsOperation(str[0]))
			{
				if (GetPriority(str[0]) != 1)
					throw TException("Ruins logic of math. expr.1");
			}
		}

		if ((i > 0) && (str[i] == '-') && (str[i - 1] == '('))
		{
			Qu.Put('{'); Qu.Put('0'); Qu.Put('}');
		}

		if (!IsOperation(str[i]) && isdigit(str[i]))
		{
			Qu.Put('{');
			while ((isdigit(str[i + 1])) && (i < str.GetSize()))
			{
				Qu.Put(str[i]);
				i++;
			}
			Qu.Put(str[i]);
	 		Qu.Put('}');
		}

		else if (St.IsEmpty() && IsOperation(str[i]))
		{
			//if (St.IsEmpty())
			St.Put(str[i]);
			if (str[i] == '(')
				op_sk++;

			if (str[i] == ')')
				throw TException("Shouldn't be here. Ruins logic of math. expr.");
		}

		else if (IsOperation(str[i]))
		{
			if (str[i] == '(')
			{
				St.Put(str[i]);
				op_sk++;
			}
			else if (str[i] == ')')
			{
				while (St.GetButDontDel() != '(')
					Qu.Put(St.Get());
				St.Get();
				//if (IsOperation(str[i +1]) && GetPriority(str[i + 1]) != 1)
				//St.Put(str[i + 1]);
				cl_sk++;
			}
			else
			{
				int pr = GetPriority(str[i]);
				if (pr > GetPriority(St.GetButDontDel()))
					St.Put(str[i]);
				else if (pr <= GetPriority(St.GetButDontDel()) && pr != 0)
				{
					while (pr <= GetPriority(St.GetButDontDel()) && !St.IsEmpty())
						Qu.Put(St.Get());
					St.Put(str[i]);
				}
			}
		}
		else if (str[i] != '\0')
			throw TException("Ruins logic of math. expr  .-.2");
	}
	while (!St.IsEmpty())
		Qu.Put(St.Get());
	if (op_sk != cl_sk)
	{
		cout << op_sk << ", " << cl_sk << "\n";
		throw TException("Ruins logic of math. expr  .-.3");
	}

	return Qu;
}
//-------------------------------------------------------------	
