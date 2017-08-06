#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>> t;
	while(t--)
	{
	    int n;
	    cin>> n;
	    int a[n];
	    int b[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>> a[i];
	        cin>> b[i];
	    }
	    unordered_map<int, int> mp;
	    for(int i=0;i<n;i++)
	    {
	        mp[a[i]]++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(mp.find(b[i])==mp.end())
	        {
	            cout<<0;
	            break;
	        }
	        if(mp[b[i]]==0)
	        {
	            cout<< 0;
	            break;
	        }
	        mp[b[i]]--;
	    }
	    cout<<1<<" ";
	    
	}
}
