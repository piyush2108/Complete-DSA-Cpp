#include <iostream>
#include <vector>

using namespace std;

void mergeArrays(vector<int> &A, vector<int> &L, vector<int> &R){

    int sizeL = L.size();
    int sizeR = R.size();
    int i=0, j=0, k=0;

    while(i<sizeL && j<sizeR){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < sizeL){
        A[k] = L[i];
        i++; k++;
    }
    while(j < sizeR){
        A[k] = R[j];
        j++; k++;
    }

}

//time complexity is O(nlogn)
void mergeSort(vector<int> &A, int n){

    if(n < 2) return;
    int mid = n/2;

    vector<int> L;
    vector<int> R;

    for(int i=0; i<n; i++){
        if(i<mid){
            L.push_back(A[i]);
        }
        else R.push_back(A[i]);
    }

    mergeSort(L, L.size());
    mergeSort(R, R.size());

    mergeArrays(A, L, R);

}

int main(){

    vector<int> A = {3, 9, 8, 0, 1, 4, 1};

    cout<<"Array before Merge Sort: "<<endl;
    for(auto x:A){
        cout<<x<<" ";
    }cout<<endl;

    cout<<"Array before Merge Sort: "<<endl;
    mergeSort(A, A.size());
    for(auto x:A){
        cout<<x<<" ";
    }

}