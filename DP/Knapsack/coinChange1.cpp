#include <iostream>
#include <vector>

using namespace std;

int noOfWays(vector<int> coins, int sum){

     int n = coins.size();
     int T[n+1][sum+1];

     for(int i=0; i<=n; i++){
          for(int j=0; j<=sum; j++){
               if(i == 0) T[i][j] = 0;
               if(j == 0) T[i][j] = 1;
          }
     }

     for(int i=1; i<=n; i++){
          for(int j=1; j<=sum; j++){
               if(coins[i-1] <= j){
                    T[i][j] = T[i-1][j] + T[i][j-coins[i-1]];
               }
               else T[i][j] = T[i-1][j];
          }
     }

     return T[n][sum];
}

int main(){
     vector<int> coins = {1,2,3};
     cout<<noOfWays(coins, 5);
}