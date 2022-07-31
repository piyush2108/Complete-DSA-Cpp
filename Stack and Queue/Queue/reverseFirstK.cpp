//function to reverse the first K elementf of a queue leaving other elements in same order

queue<int> reverseFirstK(queue<int> q, int K){

    int n = q.size();
    stack<int> S;

    for(int i=0; i<n; i++){
        S.push(q.front());
        q.pop();
    }

    for(int i=0; i<n; i++){
        q.push(S.top());
        S.pop();
    }

    for(int i=0; i<n-K; i++){
        q.push(q.front());
        q.pop();
    }

    return q;
}