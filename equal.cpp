#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int i,j,k;
        int a[n];
        int mn=1000;
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            mn = min(mn,a[i]);
        }
        int res = 1000000000;
        for(i=max(0,mn);i<=mn;i++)
        {
            int count =0;
            for(j=0;j<n;j++)
            {
                int temp = a[j]-i;
                count += temp/5 + (temp%5)/2 + (temp%5)%2;
                
            }
            res = min(res,count);
        }
        
        cout<< res<< "\n";
        
        
    }
    
    return 0;
}
