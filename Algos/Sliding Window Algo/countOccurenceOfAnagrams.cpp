//function to count the occurence of anagrams in a string

//str1 -> text
//str2 -> word
int findOccurence(string str1, string str2){

    int n = str1.size();
    int k = str2.size();

    map<char, int> m;
    for(auto i: str2){
        m[i]++;
    }

    int ans = 0;
    int count = m.size();
    int i=0; int j=0;

    while(j<n){

        if(m.find(str1[j]) != m.end()){
            m[str1[j]]--;
            if(m[str1[j]] == 0) count--;
        } 

        if(j-i+1 == k){
            if(count == 0) ans++;
            
            if(m.find(str1[i]) != m.end()){
                m[str1[i]]++;
                if(m[str1[i]] == 1) count++;
            }

            i++; j++;
        }
        else j++;
    }

    return ans;
}