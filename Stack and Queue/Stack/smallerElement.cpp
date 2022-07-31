//next smaller element for each array element
vector<int> nextSmaller(vector<int> arr, int n){

    stack<int> S;
    S.push(-1);

    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        while(S.top() >= arr[i]){
            S.pop();
        }
        ans[i] = S.top();
        S.push(arr[i]);
    }
    return ans;
}

//previous smaller element for each array element
vector<int> prevSmaller(vector<int> arr, int n){

    stack<int> S;
    S.push(-1);

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        while(S.top() >= arr[i]){
            S.pop();
        }
        ans[i] = S.top();
        S.push(arr[i]);
    }
    return ans;
}