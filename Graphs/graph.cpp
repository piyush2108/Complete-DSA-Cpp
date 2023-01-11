#include <iostream>
#include <vector>

using namespace std;

int main(){
     int m, n; //no. of nodes and no. of edges as input
     cin>>n>>m;

     //store a graph using adjacency matrix
     int adj[n+1][m+1]; //declaration of adjacency matrix
     for(int i=0; i<m; i++){
          int u, v;
          cin>>u>>v;

          adj[u][v] = 1;
          adj[v][u] = 1;
     }

     //store a graph using adjacency list
     vector<int> adj[n+1];
     for(int i=0; i<m; i++){
          int u, v;
          cin>>u>>v;

          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     return 0;
}