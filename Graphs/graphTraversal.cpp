//BFS traversal
//we are given an adjacency list and no of vertices
vector<int> bfs(int n, vector<int> adj){

     vector<int> bfs;
     int visited[n] = {0}; //make a visited array and initially mark every position as 0
     visited[0] = 1;

     queue<int> q;
     q.push(0);

     //pop out a node from the queue, if its neighbour is not visited put it in the queue
     //do this till the queue is not empty
     while(!q.empty()){
          int node = q.front();
          q.pop();

          bfs.push_back(node);
          for(auto it: adj[node]){
               if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
               }
          }
     }

     return bfs;
}