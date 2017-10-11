#include<bits/stdc++.h>
#include <limits.h>
#include<vector>
using namespace std;

#define pra 100000

stack<int> St;
 
// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree
 
// Function to print shortest path from source to j
// using parent array

 
// A utility function to print the constructed distance
// array
int minDistance(int dist[], bool sptSet[],int n)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
void printSolution(int parent[],int src,int dest, vector<int> path)
{

    // Base Case : If j is source
    if (parent[dest]==-1)
    {    //path.push_back(dest);
       St.push(dest);
        
        return;}
 
    printSolution(parent,src, parent[dest],path);
    St.push(dest);
    //path.push_back(dest);
    //printf("%d", dest);


}

 
void dijkstra(int graph[][pra], int src,int dest, vector<int> path,int n)
{
    int dist[n];  // The output array. dist[i] will hold
                  // the shortest distance from src to i
 
    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[n];
 
    // Parent array to store shortest path tree
    int parent[n];
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < n; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < n-1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet,n);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < n; v++)
 
            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] <= dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }  
    }
 
    /*for(int i=0;i<n;i++)
    {
        printf("%d ",parent[i]);
    }*/
  printSolution(parent,src,dest, path);
}

struct rana
{
    int a ;
    int b;
};
typedef struct rana rana;

int tushar(int graph[][pra],int S[], int u,int v,int n)
{
    int sum =S[u];
   for(int i=0;i<n;i++)
   {
      if(graph[u][i]==1 && (i!=v))
      {
            //sum = sum+S[i];
            sum = sum + tushar(graph,S,i,u,n);
      }
   }
   return sum;
}

rana Ques(int graph[][pra], vector<int> path, int n, int S[])
{
     int i =0;
     int j = path.size();
     rana p;
     p.a = 0;
     p.b =0;
     /*for(int s=0;s<j;s++)
     {
        printf("%d ",path[s]);
     }*/
     printf("\n");
     while(j!=i)
     {
           p.a += tushar(graph,S,path[i],path[i+1],n);
           i++;
           printf("%d ",p.a);
    if(j!=i)
    {
    p.b += tushar(graph,S,path[j-1],path[j-2],n);
    j--;
    }
          // printf("%d ",p.b);
        
    }
    printf("\n");
     return p;


}



int main()
{

    int n;
    cin>> n;
    int S[n];
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    int graph[n][pra];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
    int q;
    cin>>q;
    int SA=0,SB=0;
    int NA=0,NB=0;

    for(int i=0;i<q;i++)
    {
        vector<int> path;
        stack<int> india;
        int a,b;
        cin>>a;
        cin>>b;
        
        
        dijkstra(graph, a-1,b-1, path,n);
        while(St.empty()!=true)
        {
            int x = St.top();
            //cout<<x;
            
            india.push(x);
            St.pop();
        }
        while(india.empty()!=true)
        {
            int x = india.top();
            //cout<<x;
            
            path.push_back(x);
            india.pop();
        }
        
     /*   for(int l=0;l<path.size();l++)
        {
            cout<<path[l]<<"\t";
        }*/
        
       // cout<<path.size();
        
        
       // for (int l= 0; l<path.size(); ++l)
        //cout << path[l]<< '\t';
        
       
       int suma, sumb;
        rana p = Ques(graph,path,n,S);
        suma = p.a;
        sumb = p.b;
        if(sumb>suma)
        {
            NB+=1;
        }
        else
        {
            NA+=1;
        }
        SA+= suma;
        SB+=sumb;


    }
   printf("%d %d %d %d",NA,SA,NB,SB);
   return 0;
}