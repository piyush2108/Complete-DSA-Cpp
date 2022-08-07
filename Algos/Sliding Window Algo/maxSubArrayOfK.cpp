//function to find the max/min subarray of size k from a given array

int maxSubarray(vector<int> arr, int k){

    int n = arr.size();
    int maxSum = INT_MIN;
    int sum = 0;
    int i = 0;
    int j = 0;

    while(j<n){

        sum += arr[j];

        if(j-i+1 == k){
            maxSum = max(maxSum, sum);
            sum -= arr[i];
            i++;
            j++;
        }
        else j++;

    }

    return maxSum;
}