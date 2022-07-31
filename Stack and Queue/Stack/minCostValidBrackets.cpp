//function to find minimum operations to make a string with valid brackets
int findMinCount(string str){

    //if the length of string is odd return -1(valid brackets not possible)
    if(str.length()%2 != 0) return -1;

    stack<char> S;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];

        if(ch == '{') S.push(ch);
        else{
            if(!S.empty && S.top == '{') S.pop();
            else S.push(ch);
        }
    }
    //after this step the stack contains only invalid brackets

    //count for remaining open and close brackets
    int a = 0, b=0;

    while(!S.empty()){
        if(S.top() == '{') a++;
        else b++;
        S.pop();
    }

    int minCount = (a+1)/2 + (b+1)/2;

    return minCount;

}