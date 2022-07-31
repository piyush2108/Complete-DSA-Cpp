#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &A, int m, int n){

    int temp = A[m];
    A[m] = A[n];
    A[n] = temp;

}

//time complexity is O(n^2)
void bubbleSort(vector<int> &A, int n){

    for(int i=0; i<n; i++){
        int flag = 0;
        for(int j=0; j<n-i-1; j++){
            if(A[j] > A[j+1])
                swap(A, j, j+1);
                flag = 1;
        }
        if(flag == 0) break;
    }

}

int main(){

    vector<int> A = {2, 4, 7, 3, 1, 9};

    cout<<"Array before Bubble Sort: "<<endl;
    for(auto x:A){
        cout<<x<<" ";
    }cout<<endl;

    cout<<"Array after Bubble Sort: "<<endl;
    bubbleSort(A, A.size());
    for(auto x:A){
        cout<<x<<" ";
    }

}