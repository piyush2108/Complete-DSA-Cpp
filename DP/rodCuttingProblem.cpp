#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> price, vector<int> length, int k){
     int n = length.size();

     int T[n+1][k+1];

     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(i == 0 || j == 0) T[i][j] = 0;
          }
     }

     for(int i=1; i<=n; i++){
          for(int j=1; j<=k; j++){
               if(length[i-1] <= j){
                    int val1 = price[i-1] + T[i][j-length[i-1]];
                    int val2 = T[i-1][j];
                    T[i][j] = max(val1, val2);
               }
               else T[i][j] = T[i-1][j];
          }
     }

     return T[n][k];
}

int main(){

     vector<int> price = {1,2,3,4,5,6,7,8};
     vector<int> length = {1,5,8,9,10,17,17,20};
     int L = 8;     

     cout<<maxProfit(price, length, L);
}