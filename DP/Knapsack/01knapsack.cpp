#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int static T[101][1001];

//Dp code

//using top-down approach
int knapSack3(vector<int> weight, vector<int> value, int W, int n){
  for(int i=0; i<=n; i++){
    for(int j=0; j<=W; j++){
      if(i==0 || j==0) T[i][j] = 0;

      else if(weight[i-1] <= j){
        int val1 = value[i-1] + T[i-1][j-weight[i-1]];
        int val2 = T[i-1][j];

        T[i][j] = max(val1, val2);
      }

      else T[i][j] = T[i-1][j];
    }
  }

  return T[n][W];
}

//using Memoization
int knapSack2(vector<int> weight, vector<int> value, int W, int n){
  if(n==0 || W==0) return 0;

  //if already calculated
  if(T[n][W] != -1) return T[n][W];

  else{
    if(weight[n-1] <= W){
      int profit1 = knapSack2(weight, value, W-weight[n-1], n-1);
      int profit2 = knapSack2(weight, value, W, n-1);

      //store the value for future use
      T[n][W] = max(value[n-1]+profit1, profit2);
    }
    //store the value for future use
    else T[n][W] = knapSack2(weight, value, W, n-1);

    return T[n][W];
  }
}

//Recursive code
//Funcition to return the maximum profit
int knapSack1(vector<int> weight, vector<int> value, int W, int n){

  if(n==0 || W==0) return 0;

  if(weight[n-1] <= W){
    int profit1 = knapSack1(weight, value, W-weight[n-1], n-1);
    int profit2 = knapSack1(weight, value, W, n-1);

    return max(value[n-1]+profit1, profit2);
  }

  else return knapSack1(weight, value, W, n-1);

}

int main(){

  vector<int> weight = {1,3,4,5};
  vector<int> value = {1,4,5,7};
  int W = 7;

  memset(T, -1, sizeof(T));
  cout<<knapSack1(weight, value, W, weight.size())<<endl;
  cout<<knapSack2(weight, value, W, weight.size())<<endl;
  cout<<knapSack3(weight, value, W, weight.size())<<endl;
}