#include <iostream>
#include <vector>

using namespace std;

int countSubsetSum(vector<int> arr, int n, int k){
     
     //DP matrix
     int t[n+1][k+1];

     //initialize
     for(int i=0; i<=n; i++){
          for(int j=0; j<=k; j++){
               if(i == 0) t[i][j] = 0;
               if(j == 0) t[i][j] = 1;
          }
     }

     for(int i=1; i<=n; i++){
          for(int j=1; j<=k; j++){
               if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
               }
               else t[i][j] = t[i-1][j];
          }
     }

     return t[n][k];
}

int countTargetSum(vector<int> arr, int target){
     int n = arr.size();

     int sum = 0;
     for(auto x: arr){
          sum += x;
     }
     //concept
     //assign sign +/- to each element and find the number of subsets with sum equals to target
     //1, 1, 2, 3 => -1, +1, -2, +3 / +1, -1, -2, +3 / -1, -1, -2, +3
     //make pairs of +ve and -ve numbers
     //(1,3) - (1,2) / (3) - (1,1,2)
     //reduce this problem to count subset sum with diff
     if((target+sum) % 2 != 0) return 0;
     else return countSubsetSum(arr, n, (target+sum)/2);

}

int main(){
     vector<int> arr = {1,1,2,3};
     cout<<countTargetSum(arr, 1);
}