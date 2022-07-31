#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &A, int m, int n){

    int temp = A[m];
    A[m] = A[n];
    A[n] = temp;

}

//time complexity is O(n^2)
void selectionSort(vector<int> &A, int n){

    for(int i=0; i<n-1; i++){
        int min_i = i;
        for(int j=i+1; j<n; j++){
            if(A[j] < A[min_i])
                min_i = j;
        }
        swap(A, i, min_i);
    }

}

int main(){

    vector<int> A = {2, 7, 4, 1, 5, 3};

    cout<<"Array before Selection Sort: "<<endl;
    for(auto x:A){
        cout<<x<<" ";
    }cout<<endl;

    cout<<"Array after Selection Sort: "<<endl;    
    selectionSort(A, A.size());
    for(auto x:A){
        cout<<x<<" ";
    }

}