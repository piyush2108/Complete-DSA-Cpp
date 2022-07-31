//function to find the first non repeating character every time a new character is inserted to the string

string firstNonRepeating(string str){

    string ans = "";
    map<char, int> count;
    queue<char> q;

    for(int i=0; i<str.length(); i++){

        char ch = str[i];
        count[ch]++;

        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1) q.pop();
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) ans.push_back('#');
    }

    return ans;
}