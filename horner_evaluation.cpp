//Horner- Evaluation for polynomials 

#include<bits/stdc++.h>
using namespace std;

float Horner_Evaluation(int a[],int n, float x)
{
	int value = a[n-1];
	for(int j=n-2;j>=0;j--)
	{
		value = a[j]+ (x*value);
	}
	return value;
}