// Heap Implementation

#include<bits/stdc++.h>
using namespace std;


// functions 
// Max_heapify, Build_max_heap, Heap_sort, Max_Heap_Insert, Heap_Extract_Max, Heap_Increase_Key

void Max_heapify(int a[], int n, int i)
{
    int left = 2*i;
    int right = 2*i +1;
    int largest = i;
    if((left<=n) && (a[left]>a[i]))
    {
          largest = left;
    }
    
    if((right<=n) && (a[right]>a[i]))
    {
    	largest = right;
    }

    if(largest!= i)
    {
    	int temp = a[i];
    	a[i]= a[largest];
    	a[largest]=temp;
    	Max_heapify(a,n,largest);
    }

}

void Build_max_heap(int a[], int n)
{
	for(int i=n/2;i>=0;i--)
	{
		Max_heapify(a,n,i);
	}
}

void Heap_sort(int a[], int n)
{
	Build_max_heap(a,n);
	int b[n];
	int k=0;
	for(int i=n-1;i>=1;i--)
	{
		b[k]=a[0];
		k++;
		a[0]=a[i];
		n=n-1;
		Max_heapify(a,n,0);

	}

	for(int i=0;i<n;i++)
	{
		a[i]=b[i];
	}
}

int Max_Heap_Minimum(int heap[],int n)
{
	return heap[0];
}

int Heap_Extract_Max(int heap[],int n)
{
	int x=heap[0];
	a[0]=heap[n];
	n=n-1;
	Max_heapify(heap,n,0);
	return x;
}


void Heap_Increase_Key(int a[], int n, int i, int k)
{
	if(a[i]>=k)
	{
		cout<<"ERROR";
		return;
	}

	a[i]=k;
	while(i>0 && a[i]>a[i/2])
	{
		int temp =a[i];
		a[i]=a[i/2];
		a[i/2]=temp;
		i=i/2;
	}
}


void Max_Heap_Insert(int a[],int n,int k);
{
	a[n]=NINF;
	int temp = a[0];
	a[0]=a[n];
	a[n]=temp;
	Heap_Increase_Key(a,n+1,0,k);
}