//function to pop the middle element from a stack
void solve(stack<int> &inputStack, int count, int size){
    
    //if count is equal to half the size of stack -> pop the top element
    if(count == size/2){
        inputStack.pop();
        return;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
    solve(inputStack, ++count, size);
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){

    int count = 0;
    solve(inputStack, count, N);
   
}