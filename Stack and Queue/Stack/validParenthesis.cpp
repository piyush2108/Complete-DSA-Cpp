//function to check for the given string that the parentheses are valid or not (for every open bracket there should be a close bracket)
bool isValidParenthesis(string statement){

    stack<char> S;

    //if the character is a open parenthesis -> push in the stack
    //if the character is a close parentesis -> check if top of stack is the corresponding open bracket or not(if not return false else pop the top)
    for(int i=0; i<statement.length(); i++){
        char ch = statement[i];

        if(ch == '[' || ch == '{' || ch=='(') S.push(ch);
        else{
            if(!S.empty()){
                if((ch == '}' && S.top() == '{') || 
                   (ch == ']' && S.top() == '[') || 
                   (ch == ')' && S.top() == '(')) S.pop();
                else return false;
            }
            else return false;
        }
    }

    if(S.empty()) return true;
}