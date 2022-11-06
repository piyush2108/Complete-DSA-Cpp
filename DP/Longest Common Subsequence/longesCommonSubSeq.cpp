#include <iostream>
#include <cstring>
using namespace std;

int static t[1001][1001];

//using Top-Down approach
int lcs(string s1, string s2, int n1, int n2){

     //declaration of top down dp matrix
     int T[n1+1][n2+1];
     //initialization of top down dp matrix
     for(int i=0; i<=n1; i++){
          for(int j=0; j<=n2; j++){
               if(i == 0 || j == 0) T[i][j] = 0;
          }
     }

     for(int i=1; i<=n1; i++){
          for(int j=1; j<=n2; j++){
               if(s1[i-1] == s2[j-1]){
                    T[i][j] = 1 + T[i-1][j-1];
               }
               else T[i][j] = max(T[i-1][j], T[i][j-1]);
          }
     }

     return T[n1][n2];
}

//using Memoization
int lcs(string s1, string s2, int n1, int n2){

     if(n1 == 0 || n2 == 0) return 0;
     if(t[n1][n2] != -1) return t[n1][n2];

     if(s1[n1-1] == s2[n2-1]){
          return t[n1][n2] = 1 + lcs(s1, s2, n1-1, n2-1);
     }
     else return t[n1][n2] = max(lcs(s1, s2, n1-1, n2), lcs(s1, s2, n1, n2-1));

}

//Recursive solution
int lcs(string s1, string s2, int n1, int n2){
     if(n1 == 0 || n2 == 0) return 0;

     if(s1[n1-1] == s2[n2-1]){
          return 1 + lcs(s1, s2, n1-1, n2-1);
     }
     else return max(lcs(s1, s2, n1-1, n2), lcs(s1, s2, n1, n2-1));
}

int longestCommonSubSeq(string str1, string str2){
     return lcs(str1, str2, str1.length(), str2.length());
}

int main(){
     string str1 = "abcdgh";
     string str2 = "abedfhr";
     memset(t, -1, sizeof(t));

     cout<<"Length of longest common sub sequence: "<<longestCommonSubSeq(str1, str2);
}