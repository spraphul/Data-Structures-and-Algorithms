// Recursive FFT 

#include<bits/stdc++.h>
#include<complex>
#include<math.h>
using namespace std;
#define pi 3.14 // for precision use value of pi upto atleast 10 digits after decimal

complex<float>* FFT(int a[], int n)
{
     complex<float> w;
     real(w)= cos(2*pi/n);
     imag(w)= sin(2*pi/n);

     if(n==1)
     {
     	return a;
     }
     else()
     {
     	complex<float> y[n];
     	int a0[n/2];
     	int a1[n/2];
     	for(int i=0;i<n;i+=2)
     	{
             a0[i/2]=a[i];
             a1[i/2]=a[i+1];
     	}

     	int* y0 = FFT(a0,n/2);
     	int* y1 = FFT(a1,n/2);
     	complex<float> w1 =w;
     	for(int k=0;k<n/2;k++)
     	{
     		y[k]=y0[k]+w1*y1[k];
     		y[k+n/2]=y0[k]-w1*y1[k];
     		w1 = w1*w;
     	}
     }

     return y;


}