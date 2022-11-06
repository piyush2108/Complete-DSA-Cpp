#include <iostream>
#include <vector>

using namespace std;

int countOfSubsetSum(vector<int> arr, int n, int sum){
     //DP matrix
     int t[n+1][sum+1];

     //initialize
     for(int i=0; i<=n; i++){
          for(int j=0; j<=sum; j++){
               if(i == 0) t[i][j] = 0;
               if(j == 0) t[i][j] = 1;
          }
     }

     for(int i=1; i<=n; i++){
          for(int j=1; j<=sum; j++){
               if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
               }
               else t[i][j] = t[i-1][j];
          }
     }

     return t[n][sum];
}

int countSubsetsOfDiff(vector<int> arr, int diff){
     
     int n = arr.size();
     int sum = 0;
     //find sum of the elements of array
     for(auto x: arr){
          sum += x;
     }

     //concept
     //to find S1 - S2 = diff
     //but S1 + S2 = sum of elements of the given array
     //by adding these two equations we get
     //2S1 = diff + sum => S1 = (diff + sum)/2

     if((diff + sum)%2 != 0) return 0;

     else return countOfSubsetSum(arr, n, (diff + sum)/2);
}

int main(){
     vector<int> arr = {1,1,2,3};
     cout<<countSubsetsOfDiff(arr, 1);
}