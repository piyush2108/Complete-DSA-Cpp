#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = start + (end-start)/2; //to prevent int overflow

        if(arr[mid] == num) return mid;
        else if(num > arr[mid]) start = mid+1;
        else end = mid-1;
    }
    return -1;
}

int binarySearchReverse(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == num) return mid;
        else if(num > arr[mid]) end = mid-1;
        else start = mid+1;
    }
    return -1;
}



int main(){

    vector<int> arr = {1, 2, 4, 6, 9, 12, 15, 16, 18, 20};
    vector<int> arr2 = {20, 18, 16, 15, 12, 9, 6, 4, 2, 1};
    vector<int> arr3 = {2, 3, 5, 7, 10, 10, 10, 11, 14, 16, 21};
    vector<int> arr4 = {12, 15, 16, 18, 20, 1, 2, 4, 6, 9};

    // cout<<binarySearch(arr, 1)<<endl;
    // cout<<binarySearchReverse(arr2, 4)<<endl;
    // cout<<orderAgnosticSearch(arr, 12)<<endl;
    // cout<<orderAgnosticSearch(arr2, 12)<<endl;
    // cout<<firstOccurence(arr3, 10)<<endl;
    // cout<<lastOccurence(arr3, 10)<<endl;
    // cout<<countOccurence(arr3, 10)<<endl;
    // cout<<countRotated(arr4)<<endl;
    // cout<<findElementRotated(arr4, 2)<<endl;
    // cout<<searchInNearlySorted(arr, 1)<<endl;
    // cout<<elementFloor(arr, 15)<<endl;
    // cout<<elementCeil(arr, 1)<<endl;
    // cout<<minDiffElement(arr, 10);

}