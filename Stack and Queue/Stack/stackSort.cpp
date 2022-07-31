//to insert the element in a sorted order
void sortedInsert(stack<int> stack, int num){

    //Base condition => if stack is empty or top is less than num simply push the element
    if(stack.empty() || stack.top() < num){
        stack.push(num);
        return;
    }

    //pop the top element and place the element in sorted order in rest of the stack
    int n = stack.top();
    stack.pop();

    sortedInsert(stack, num);
    stack.push(n);
}

//function to sort a given stack
void sortStack(stack<int> &stack){

    //Base condition => if stack is empty return
    if(stack.empty()) return;

    //pop the top element of the stack and sort rest of the stack and then place the popped element at the correct position(sorted position)
    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sortedInsert(stack, num);
}