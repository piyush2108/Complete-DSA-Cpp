//We are given a matrix of size m x n
//0's in the matrix represent water and 1's represent land
//we need to calculate the number of islands

int numIslands(vector<vector<char>> &grid){
     int n = grid.size();
     int m = grid[0].size();

     vector<vector<int>> visited(n, vector<int>(m, 0));

     //we traverse the whole grid and check if there is a land which is not visited
     //if there is a land which is not visited, we call traverse algo on that cell
     for(int row=0; row<n; row++){
          for(int col=0; col<n; col++){
               if(!visited[row][col] && grid[row][col] == '1'){
                    bfs(row, col, visited, grid);
               }
          }
     }
}

void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> grid){
     visited[row][col] = 1;
     int n = grid.size();
     int m = grid[0].size();

     queue<pair<int, int>> q;
     q.push({row, col});

     while(!q.empty()){
          int r = q.front().first;
          int c = q.front().second;
          q.pop();

          for(int i=-1; i<=1; i++){
               for(int j=-1; j<=1; j++){
                    int nrow = r + i;
                    int ncol = c + j;

                    if(nrow >= 0 && nrow < n &&
                    ncol >=0 && ncol < m &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                         visited[nrow][ncol] = 1;
                         q.push({row, col});
                    }      
               }
          }
     }
}