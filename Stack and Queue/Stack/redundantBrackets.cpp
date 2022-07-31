//function to check if the given expression contains a pair of redundant brackets
bool isRedundant(string &s){

    //if string is empty return false
    if(s.empty()) return false;

    stack<char> S;
    for(int i=0; i<s.lenght(); i++){
        if(s[i] >= 97 && s[i] <= 122) continue;

        else if(s[i] == ')'){
            if(S.top() == '+' || 
               S.top() == '-' || 
               S.top() == '*' || 
               S.top() == '/'){
                while(S.top() != '('){
                    S.pop();
                }S.pop();
               }
            else return true;
        }

        else S.push(s[i]);
    }

    return false;

}