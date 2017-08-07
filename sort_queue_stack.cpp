//Sorting using stack and queue

#include<bits/stdc++.h>
using namespace std;

void Sort(int a[],int n)
{
	queue<int> Q;
	stack<int> S;
	for(int i=0;i<n;i++)
	{
		Q.push(a[i]);
	}
	while(Q.empty()==false)
	{
		int x= Q.pop();
		while(S.empty()==false && S.top()>x)
		{
             int y = S.pop();
             Q.push(y);

		}
		S.push(x);
	}

	for(int i=0;i<n;i++)
	{
		int r = S.pop()
		a[i]=r;
	}

}