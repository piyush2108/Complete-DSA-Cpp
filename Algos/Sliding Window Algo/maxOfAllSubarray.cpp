//function to find max of for each subarray from a given array

vector<int> maxOfAll(vector<int> arr, int k){

    int n = arr.size();
    vector<int> ans;
    deque<int> q;

    int i=0;
    int j=0;

    if(k > n){
        ans.push_back(*max_element(arr.begin(), arr.end()));
    }

    while(j<n){
        while(!q.empty() && arr[j]>q.back()){
            q.pop_back();
        }
        q.push_back(arr[j]);

        if(j-i+1 == k){
            ans.push_back(q.front());

            if(q.front() == arr[i]) q.pop_front();
            i++;
            j++;
        }
        else j++;
    }

    return ans;
}