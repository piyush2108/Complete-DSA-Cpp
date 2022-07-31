//implementation of two stacks using single array

//for stack1 we will move from left to right and for stack2 we will move from right to left for better space utilization
//we can also use the concept of n/2 but in this the space utilization is not optimal
class twoStack{

    int *arr;
    int top1; //top for stack 1
    int top2; //top for stack 2
    int size; //size of array

    public:

    twoStack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    //to push element in stack 1
    void push1(int num){
        //atleast one empty space available between two stacks
        if(top2-top1 > 1){
            top1++;
            arr[top1] = num;
        }
        else cout<<"Stack Overflow"<<endl;
    }

    //to push element in stack 2
    void push2(int num){
        //atleast one empty space available between two stacks
        if(top2-top1 > 1){
            top2--;
            arr[top2] = num;
        }
        else cout<<"Stack Overflow"<<endl;
    }

    //to pop element from stack 1
    void pop1(){
        if(top >= 0) top1--;  
        else cout<<"Stack Underflow"<<endl;
    }

    //to pop element from stack 2
    void pop2(){
        if(top2 < size) top2++;  
        else cout<<"Stack Underflow"<<endl;
    }

};
