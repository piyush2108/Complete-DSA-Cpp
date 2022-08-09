//function to find the largest subarray of sum k

//this approach won't work if array contain negative numbers
int largestSubarray(vector<int> arr, int k){

    int n = arr.size();
    int sum = 0;
    int i=0;
    int j=0;
    int maxWin = 0;

    while(j<n){
    
        sum += arr[j];

        if(sum == k){
            maxWin = max(maxWin, j-i+1);
            sum -= arr[i];
            j++;
        }
        else if(sum > k){
            while(sum > k){
                sum -= arr[i];
                i++;
                if(sum == k) maxWin = max(maxWin, j-i+1);
            }
            j++;
        }
        else j++;   
    }

    return maxWin;
}