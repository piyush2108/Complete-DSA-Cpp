#include <iostream>
#include <vector>

using namespace std;

bool isEqualPartition(vector<int> arr, int n){
     
     int sum = 0;
     //sum of the elements of the given array
     for(int i=0; i<n; i++){
          sum += arr[i];
     }

     //concept
     //to find S1 = S2
     //but S1 + S2 = sum of the elements of the given array
     //so 2S1 = sum => S1 = sum/2
     if(sum%2 != 0) return false;
     int k = sum/2;
     
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
               if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
               }
               else t[i][j] = t[i-1][j];
          }
     }

     return t[n][k];
     
}

int main(){
     vector<int> A = {1,5,11,5};   

     if(isEqualPartition(A, A.size())) cout<<"TRUE"<<endl;
     else cout<<"FALSE"<<endl;
}