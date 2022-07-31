#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &A, int n, int m){

    int temp = A[n];
    A[n] = A[m];
    A[m] = temp;

}

int partitionIndex(vector<int> &A, int start, int end){

    int pivot = A[end];
    int pIndex = start;

    for(int i=start; i<end; i++){
        if(A[i] <= pivot){
            swap(A, i, pIndex);
            pIndex++;
        }
    }
    swap(A, pIndex, end);
    return pIndex;

}

//time complexity is O(nlogn)
void quickSort(vector<int> &A, int start, int end){

    if(start >= end) return;
    int pIndex = partitionIndex(A, start, end);
    quickSort(A, start, pIndex-1);
    quickSort(A, pIndex+1, end);

}

int main(){

    vector<int> A = {3, 9, 0, 1, 4, 1, 6, 2};

    cout<<"Array before Quick Sort:"<<endl;
    for(auto x:A){
        cout<<x<<" ";
    }cout<<endl;

    quickSort(A, 0, A.size()-1);
    cout<<"Array after Quick Sort:"<<endl;
    for(auto x:A){
        cout<<x<<" ";
    }

}