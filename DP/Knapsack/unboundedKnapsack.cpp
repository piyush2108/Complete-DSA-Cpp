#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(vector<int> weight, vector<int> value, int k){
     int n = weight.size();
     int T[n+1][k+1];

     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(i == 0 || j == 0) T[i][j] = 0;
          }
     }

     for(int i=1; i<=n; i++){
          for(int j=1; j<=k; j++){
               if(weight[i-1] <= j){
                    //here we re consider the value even after taking into account its value
                    //this is the major difference between 0-1 and unbounded knapsack
                    //in 0-1 after doing calculations with a particular weight we consider the weight as processed
                    //in unbounded knapsack if we neglect a weight we consider it as processed else we treat it as unprocessed
                    int val1 = value[i-1] + T[i][j-weight[i-1]];
                    int val2 = T[i-1][j];
                    T[i][j] = max(val1, val2);
               }
               else T[i][j] = T[i-1][j];
          }
     }

     return T[n][k];
}

int main(){
     vector<int> weight = {1,3,4,5};
     vector<int> value = {1,4,5,7};
     int W = 7;

     cout<<unboundedKnapsack(weight, value, W);
}