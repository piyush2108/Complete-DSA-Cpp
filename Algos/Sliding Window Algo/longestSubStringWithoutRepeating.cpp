//function to find the largest substring with no repeating characters

int longestSubString(string str){

    int n = str.size();
    unordered_map<char, int> um;
    int i=0;
    int j=0;
    int maxLen = INT_MIN;
    int count = 0;

    while(j<n){

        um[str[j]]++;
        
        if(um[str[j]] == 1) maxLen = max(maxLen, j-i+1);
        else if(um[str[j]] > 1){
            while(um[str[j]] > 1){
                um[str[i]]--;
                i++;
                if(um[str[i]] == 1) maxLen = max(maxLen, j-i+1);
            }
        }

        j++;
    }

    return maxLen;
}