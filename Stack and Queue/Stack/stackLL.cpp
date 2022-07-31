using namespace std;

class Node{
    public:

    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    int data;
    Node* top;
    int stackSize;

    public:

    Stack(){
        top = NULL;
        stackSize = 0;
    }

    void push(int data){
        Node* newNode = new Node(data);
        Node* temp = top;
        top = newNode;
        top->next = temp;
        stackSize++;    
    }

    void pop(){
        if(top == NULL) cout<<"Stack Underflow"<<endl;
        else{
            Node* temp = top;
            top = top->next;
            delete(temp);
            stackSize--;
        }
    }

    Node* peek(){
        return top;
    }

    bool isEmpty(){
        if(top == NULL) return true;
        else return false;
    }

    int sizeOfStack(){
        return stackSize;
    }
};