// Radix sort

#include<bits/stdc++.h>
using namespace std;

void countsort(int a[],int n,int exp)
{
	int c[10]={0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<n;i++)
	{
		c[(a[i]/exp)%10]=c[(a[i]/exp)%10]+1;
	}
	for(int i=0;i<10;i++)
	{
		c[i]=c[i-1]+c[i];
	}

	int b[n];
	for(int i=0;i<n;i++)
	{
		b[c[(a[i]/exp)%10]]=a[i];
		c[(a[i]/10)%10]--;
	}

	for(i=0;i<n;i++)
	{
		a[i]=b[i];
	}

}


void radixsort(int a[],int n,int k)
{
	int max=k;
	for(int exp=1;max/exp>0,exp=exp*10)
	{
		countsort(a,n,exp);
	}


}