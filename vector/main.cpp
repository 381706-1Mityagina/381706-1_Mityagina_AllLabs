#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
  float a[3] = { 0.6, 5.7, 0.4 };
	float b[3] = { 0.85, 1.3, 5.8 };
	int c[3] = { 4, 5, 7 };
  
  TVector<int> Sum;
	TVector<float> Razn;
	TVector<float> Umn;
	TVector<float> Del;
	TVector<float> A(a, 3);
	TVector<float> B(b, 3);
	TVector<int> C(c, 3);
	
	//std::cout << A << "\n" << B << "\n" << C << "\n" << "\n";
return 0;
}
