//function to find if there is a celebrity in the party or not
bool isCeleb(vector<vector<int>> M, int num, int n){

    //row check
    for(int i=0; i<n; i++){
        if(M[num][i] != 0) return false;
    }

    //column check
    for(int i=0; i<n; i++){
        if(i != num && M[i][num] != 1) return false;
    }

    return true;
}

int findCelebrity(vector<vector<int>> &M, int n){

    stack<int> S;
    for(int i=0; i<n; i++){
        S.push(i);
    }

    while(S.size() > 1){
        int A = S.top();
        S.pop();
        int B = S.top();
        S.pop();

        if(M[A][B] == 1){
            S.push(B);
        }
        else S.push(A);
    }

    bool ans = isCeleb(M, S.top(), n);
    if(ans) return S.top();
    else return -1;
}