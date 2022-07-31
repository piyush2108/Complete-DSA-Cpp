using namespace std;

class Queue{

    int* arr;
    int qfront;
    int qrear;
    int size;

    public:

    Queue(){
        size = 1000;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    Queue(int data){
        this->size = size;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    void enqueue(int data){
        if(qrear == size) cout<<"Queue Overflow"<<endl;
        else{
            arr[qrear] = data;
            qrear++;
        }
    }

    void dequeue(){
        if(qfront == qrear) cout<<"Queue is empty"<<endl;
        else{
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear){
                qfront = 0;
                qrear = 0;
            }
        }
    }

    int front(){
        if(qfront == qrear) return -1;
        else return arr[qfront];
    }

    int back(){
        return arr[qrear-1];
    }

    bool isEmpty(){
        if(qfront == qrear) return true;
        else return false;
    }

};