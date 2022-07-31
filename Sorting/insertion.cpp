#include <iostream>
#include <vector>

using namespace std;

//time complexity is O(n^2)
void insertionSort(vector<int> &A, int n){

    for(int i=1; i<n; i++){
        int value = A[i];
        int empty_slot = i;
        while(empty_slot > 0 && A[empty_slot-1] > value){
            A[empty_slot] = A[empty_slot-1];
            empty_slot = empty_slot-1;
        }
        A[empty_slot] = value;
    }

}

int main(){

    vector<int> A = {7, 2, 4, 1, 0, 9, 3};

    cout<<"Array before Insertion Sort: "<<endl;
    for(auto x:A){
        cout<<x<<" ";
    }cout<<endl;

    cout<<"Array after Insertion Sort: "<<endl;
    insertionSort(A, A.size());
    for(auto x:A){
        cout<<x<<" ";
    }

}