#include <iostream>
#include <vector>

using namespace std;

int countSubsetsSum(vector<int> arr, int k, int n){
     //DP matrix
     int t[n+1][k+1];

     //initialization
     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(i == 0) t[i][j] = 0;
               if(j == 0) t[i][j] = 1;
          }
     }

     
     for(int i=1; i<=n; i++){
          for(int j=1; j<=k; j++){
               //if element in the array is less than the target sum 
               if(arr[i-1] <= j){
                    //either include or exclude it and add the outcome of both the cases
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
               }
               //exclude when element is greater
               else t[i][j] = t[i-1][j];
          }
     }

     return t[n][k];
}

int main(){
     vector<int> A = {2,3,5,6,8,10};
     cout<<countSubsetsSum(A, 10, A.size());
}