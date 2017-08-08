#include <bits/stdc++.h>

using namespace std;

long getWays(long n, long m, vector < long > c){
    
    long table[n+1][m];
    for(int i=0;i<m;i++)
    {
        table[0][i]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y;
            if((i-c[j])>=0)
            {
                x= table[i-c[j]][j];
            }
            else
            {
                x=0;
            }
            
            if(j>=1)
            {
                y = table[i][j-1];
            }
            else
            {
                y = 0;
            }
            table[i][j]=x+y;
        }
    }
    
    return table[n][m-1];
    // Complete this function
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n,m,c);
    cout << ways;
    return 0;
}
