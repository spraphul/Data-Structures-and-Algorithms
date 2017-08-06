#include<bits/stdc++.h>
using namespace as std;
#define N 10

void print_sol(int a[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << a[i][j]<< " ";
		}
		cout<< "\n";
	}

	return ;
}

bool isSafe(int a[N][N], int row, int col)
{
	for(int i=0;i<col;i++)
	{
		if(a[row][i]==true)
		{
			return false;
		}
	}

	for(int i=row,int j=col;i>=o && j>=0;i--,j--)
	{
		if(a[i][j]==true)
		{
			return false;
		}
	}

	for(int i=row,int j=col;i<N && j>=0;i++,j--)
	{
		if(a[i][j]==true)
		{
			return false;
		}
	}

}


bool solve(int a[N][N], int col)
{
	if(col>=N)
	{
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(isSafe(a,i,col))
		{
			a[i][col]=1;
			if(solve(a,col+1))
			{
				return true;
			}

			a[i][col]=0;
		}
	}

	return false;
}


void NQueen(int N)
{
	int a[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i][j]=0;
		}
	}

	if(solve(a,0)==true)
	{
		print_sol(a);
	}

	else()
	{
        cout << "Solution Not Possible";
	}
}

int main()
{
	NQueen(N);
	return 0;
}

