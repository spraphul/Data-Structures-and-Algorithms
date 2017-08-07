//Bracket Balancing

#include<bits/stdc++.h>
using namespace std;

bool bracketbalance(char str[])
{
     int i= str.size();
     stack<char> S;

     for(int j=0;j<i;j++)
     {
     	if(str[i]=='(')
     	{
     		S.push(str[i]);
     	}
     	if(str[i]==')')
     	{
     		S.pop();
     	}
     }

     if(S.empty()==true)
     {
     	return true;
     }
     
     return false;
}