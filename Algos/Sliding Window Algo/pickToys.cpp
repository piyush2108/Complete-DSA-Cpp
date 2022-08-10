//same ques as longest substring of size k with k = 2

int maxToys(string str){

    int n = str.size();
    unordered_map<char, int> um;
    int i=0;
    int j=0;
    int maxToys = INT_MIN;

    while(j<n){

        um[str[j]]++;

        if(um.size() == 2){
            maxToys = max(maxToys, j-i+1);
            j++;
        }
        else if(um.size() > 2){
            while(um.size() > 2){
                um[str[i]]--;
                if(um[str[i]] == 0) um.erase(str[i]);
                i++;
            }
            j++;
        }
        else j++;
    }

    return maxToys;
}