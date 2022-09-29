//to find a subset in the given array with sum equals to k
#include <iostream>
#include <vector>

using namespace std;

bool isSubsetPossible(vector<int> arr, int k, int n){
     //declare the array
     bool t[n+1][k+1];

     //initialize the array t
     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(i==0) t[i][j] = 0;
               if(j==0) t[i][j] = 1;
          }
     } 

     for(int i=1; i<=n; i++){
          for(int j=1; j<=k;j++){
               if(arr[i-1] <= k){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[-1][j];
               }
               else t[i][j] = t[i-1][j];
          }
     }

     return t[n][k];
}

int main(){
     vector<int> A = {2,3,7,8,10};
     
     if(isSubsetPossible(A, 11, A.size())) cout<<"TRUE"<<endl;
     else cout<<"FALSE"<<endl;
}