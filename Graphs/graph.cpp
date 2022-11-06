#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

//creation of graph using adjacency list
template <typename T>
class Graph{
     
     unordered_map<T, list<T>> adj;
     
     public:
     //to add edges to the graph
     void addEdge(T u, T v, bool direct){
          //direct = 0 -> undirected edge
          //direct = 1 -> directed edge
          
          //create and edge from u to v
          adj[u].push_back(v);
          
          //if undirected edge from v to u is also possible
          if(direct == 0) adj[v].push_back(u);

     }

     //to print the adjacency list
     void printAdjList(){
          for(auto x: adj){
               cout<<x.first<<"-> ";
               for(auto i: x.second){
                    cout<<i<<", ";
               }
               cout<<endl;
          }
     }

     //to perform bfs traversal
     void bfsSearch(unordered_map<int, bool> &visited, vector<int> &ans, int node){
          queue<int> q;
          q.push(node);
          visited[node] = 1;

          while(!q.empty()){
               int front = q.front();
               q.pop();

               ans.push_back(front);
               for(auto x: adj[front]){
                    if(!visited[x]){
                         q.push(x);
                         visited[x] = 1;
                    }
               }
          }
     }

     void bfsTraversal(int vertex){
          vector<int> ans;

          unordered_map<int, bool> visited;
          for(auto x: adj){
               visited[x.first] = 0;
          }

          for(int i=0; i<vertex; i++){
               if(!visited[i]){
                    bfsSearch(visited, ans, i);
               }
          }

          for(auto x: ans){
               cout<<x<<" ";
          }
     }

     //to perform dfs traversal

};

int main(){

     int n, m;
     cin>>n>>m;
     
     Graph<int> g;
     for(int i=0; i<m; i++){
          int u, v;
          cin>>u>>v;

          g.addEdge(u, v, 0);
     }

     g.printAdjList();
     g.bfsTraversal(n);
}