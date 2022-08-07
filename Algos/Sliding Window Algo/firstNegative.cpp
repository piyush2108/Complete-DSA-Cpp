//function to find first negative number in every window of size k in an array

vector<int> firstNegative(vector<int> arr, int k){

    int n = arr.size();
    vector<int> ans;
    queue<int> q;
    int i=0;
    int j=0;

    while(j<n){

        if(arr[j] < 0) q.push(arr[j]);

        if(j-i+1 == k){
            int front = q.front();
            if(!q.empty()) ans.push_back(front);
            else ans.push_back(0);

            if(front == arr[i]) q.pop();
            i++;
            j++;
        }
        else j++;
    }

    return ans;
}