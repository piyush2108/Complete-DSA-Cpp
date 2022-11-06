#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int> coins, int sum){
     
     int n = coins.size();
     int T[n+1][sum+1];

     for(int i=0; i<=n; i++){
          for(int j=0; j<=sum; j++){
               if(i == 0) T[i][j] = INT_MAX - 1;
               if(j == 0) T[i][j] = 0;
               if(i == 1){
                    if(j % coins[i-1] == 0) T[i][j] = j/coins[i-1];
                    else T[i][j] = INT_MAX - 1;
               }
          }
     }

     T[0][0] = 0;

     for(int i=1; i<=n; i++){
          for(int j=1; j<=sum; j++){
               if(coins[i-1] <= j){
                    T[i][j] = min(T[i-1][j], T[i][j-coins[i-1]] + 1);
               }
               else T[i][j] = T[i-1][j];
          }
     }

     return T[n][sum];
}

int main(){
     vector<int> coins = {1,2,3};
     cout<<minCoins(coins, 5);
}