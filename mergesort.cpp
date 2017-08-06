#include<bits/stdc++.h>
using namespace std;
#define INF 10000

void merge(int a[], int p, int mid,int q)
{
	int n1,n2;
	n1=mid-p+1;
	n2=q-mid;
	int b[n1+1];
	int c[n2];
	for(int i=0;i<n1;i++)
	{
		b[i]=a[p+i];
	}
	b[n1]= INF;
	for(int i=0;i<n2;i++)
	{
		c[i]=a[i+mid+1];
	}
	c[n2]= INF;
	int r[n];
	int i=0,j=0,k=0;

	while((i<n1) && (j<n2))
	{
        if(b[i]<=c[j])
        {
        	r[k++]=b[i];
        	i++;
        }
        else()
        {
        	r[k++]=c[j];
        	j++;
        }
	}

}

void mergesort(int a[],int p, int q)
{
	if(q==p)
	{
		return;
	}
	
	else()
	{
		int mid = (p+q)/2;
		mergesort(a,p,mid);
		mergesort(a,mid+1,q);
		merge(a,p,mid,q);
	}
}