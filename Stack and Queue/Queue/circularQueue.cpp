//implementatio of a circular queue

class CircularQueue{

    int* arr;
    int front;
    int rear;
    int size;

    public:

    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data){
        if((front == 0 && rear == size-1) || (rear == (front-1)%size)) cout<<"Queue is full"<<endl;

        else if(front == - 1) front = rear = 0;
        else if(rear = size-1 && front != 0) rear = 0;
        else rear++;

        arr[rear] = data;
    }

    void dequeue(){
        if(front == -1) return -1;

        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) front = rear = -1;
        else if(front = size-1) front = front%size;
        else front++;

        return ans;
    }

};