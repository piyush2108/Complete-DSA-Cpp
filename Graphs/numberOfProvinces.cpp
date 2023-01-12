//We are given a graph in a from of adjacency matrix with 'n' nodes
//two nodes 'u' and 'v' belong to same province if they are connected
//we need to find the number of provinces

int numProvinces(vector<vector<int>> adj, int n){

     //creating an adjacency list from given adjacency matrix
     vector<int> adjList[n];
     for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
               if(adj[i][j] == 0 && i != j){
                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
               }
          }
     }

     int visited[n];
     int count = 0; //counter for no. of provinces
     for(int i=0; i<n; i++){
          if(!visited[i]){
               count++;
               dfs(i, adjList, visited);
          }
     }

     return count;
}

void dfs(int node, vector<int> adjList, int visited[]){
     visited[node] = 1;

     for(auto it: adjList[node]){
          if(!visited[it]){
               dfs(it, adjList, visited);
          }
     }
}