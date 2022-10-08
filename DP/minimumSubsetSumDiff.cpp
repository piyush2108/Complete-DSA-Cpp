#include <iostream>
#include <vector>

using namespace std;

vector<int> isSubset(vector<int> arr, int n, int range){
     vector<int> ans;

     int t[n+1][range+1];

     for(int i=0; i<=n; i++){
          for(int j=0; j<=range; j++){
               if(i == 0) t[i][j] = 0;
               if(j == 0) t[i][j] = 1;
          }
     }

     for(int i=1; i<=n; i++){
          for(int j=1; j<=range; j++){
               if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
               }
               else t[i][j] = t[i-1][j];
          }
     }

     for(int i=0; i<=range; i++){
          if(t[n][i] == 1) ans.push_back(i);
     }

     return ans;
}

int minSubSetDiff(vector<int> arr){
     int n = arr.size();

     int range = 0;
     for(auto x: arr){
          range += x;
     }

     vector<int> ans = isSubset(arr, n, range);
     int minDiff = INT_MAX;
     for(int i=0; i<ans.size()/2; i++){
          minDiff = min(minDiff, abs(range - 2*ans[i]));
     }

     return minDiff;
}

int main(){
     vector<int> arr = {1,2,7};
     cout<<minSubSetDiff(arr);
}