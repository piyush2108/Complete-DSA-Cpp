using namespace std;
class Stack{
    
    int MAX = 1000;
    int* arr;
    int top;
    int size;
    int stackSize;

    public:

    Stack(){
        this->size = MAX;
        arr = new int(MAX);
        top = -1;
        stackSize = 0;
    }

    Stack(int size){
        this->size = size;
        arr = new int(size);
        top = -1;
        stackSize = 0;
    }

    void push(int element){
        if(size-top >1){
            top++;
            arr[top] = element;
            stackSize++;
        }
        else cout<<"Stack Overflow"<<endl;
    }

    void pop(){
        if(top >= 0){
            top--;
            stackSize--;
        }
        else cout<<"Stack Underflow"<<endl;
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }

    int peek(){
        if(top >= 0) return arr[top];
        else{
            return -1;  
        }
    }

    int sizeOfStack(){
        return stackSize;
    }
};