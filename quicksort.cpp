#include<bits/stdc++.h>
using namespace std;

int Partition(int a[],int p, int q)
{
	int i =p-1;
	int pivot = a[q];
	for(int j = p;j<=q-1;j++)
	{
		if(a[j]<=pivot)
		{
			int temp=a[j];
			a[j]=a[i+1];
			a[i+1]=temp;
			i=i+1;

		}
	}
	int l=a[i+1];
	a[i+1]=a[q];
	a[q]=l;
	return i+1;
}


void quicksort(int a[],int p, int q)
{
	if(p>=q)
	{
        return;
	}
	int m = Partition(a,p,q);
	quicksort(a,p,m);
	quicksort(a,m+1,q);
}