// Largest Rectangle

#include<bits/stdc++.h>
using namespace std;

struct pair
{
	int f;
	int s;
};
typedef struct pair pair;

int LargestRectangleUtil(pair p[],stack<pair> S)
{
	S.push(p[0]);
	int x=0;
	for(int i=0;i<=n;i++)
	{
		while(p[i].f<S.top().f)
		{
             pair p=S.top();
	     S.pop();
             pair q= S.top();
             int y= (i-q.s-1)*p.f;
             if(y>x)
             {
             	x=y;
             }
		}
		S.push(p[i]);
	}
	return x;
}

int LargestRectangle(int a[],int n)
{
	pair p[n+1];
	p[0].f=0;
	p[0].s=0;
	for(int i=0;i<n;i++)
	{
		p[i+1].f=a[i];
		p[i+1].s=i+1;
	}
	stack<pair> S;
	int res = LargestRectangleUtil(p,S);
	return res;
}
