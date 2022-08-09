//function to find the longest substring with k unique characters

int longestSubString(string str, int k){

    int n = str.size();
    unordered_map<char, int> um;
    int i=0;
    int j=0;
    int maxLen = INT_MIN;
    int count = 0;

    while(j<n){

        if(um.find(str[j]) != um.end()){
            if(um[str[j]] == 0) count++;
            um[str[j]]++;
        }
        else{
            um[str[j]]++;
            count++;
        }

        if(count == k){
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if(count > k){
            while(count > k){
                um[str[i]]--;
                if(um[str[i]] == 0) count--;
                i++;
                if(count == k) maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        else j++;
    }

    if(maxLen == INT_MIN) return -1;
    return maxLen;
}