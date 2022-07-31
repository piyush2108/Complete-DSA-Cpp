//function to find the first negative integer for every K sized window from an array of size N

vector<long long> printFirstNegative(long long int A[], long long int N, long long int K){

    vector<long long> ans;
    deque<long long int> Q; //to store the indexes of the negative integers

    //store all the negative integers for the first window
    for(int i=0; i<K; i++){
        if(A[i] < 0) Q.push_back(i);
    }

    //store the ans for the first window
    if(!Q.empty()) ans.push_back(A[Q.front()]);
    else ans.push_back(0);

    for(int i=K; i<N; i++){

        //if the element is out of the window remove the element
        if(!Q.empty() && i-Q.front() >= K) Q.pop_front();

        //addition of the new element
        if(A[i] < 0) Q.push_back(i);

        //store the ans for current window
        if(!Q.empty()) ans.push_back(A[Q.front()]);
        else ans.push_back(0);
    }

    return ans;
}