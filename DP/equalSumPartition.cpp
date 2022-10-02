#include <iostream>
#include <vector>

using namespace std;

bool isEqualPartition(vector<int> arr, int n){
     
     int sum = 0;
     for(int i=0; i<n; i++){
          sum += arr[i];
     }
     if(sum%2 != 0) return false;

     int k = sum/2;

     int t[n+1][k+1];
     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(i == 0) t[i][j] = 0;
               if(j == 0) t[i][j] = 1;
          }
     }

     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
               }
               else t[i][j] = t[i-1][j];
          }
     }

     return t[n][k];
     
}

int main(){
     vector<int> A = {1,5,11,6};   

     if(isEqualPartition(A, A.size())) cout<<"TRUE"<<endl;
     else cout<<"FALSE"<<endl;
}