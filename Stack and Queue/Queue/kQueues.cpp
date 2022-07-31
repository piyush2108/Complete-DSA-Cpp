//function for k queues to store elements using one array

#include <iostream>

using namespace std;

class kQueue{

    public:
    int n;
    int k;
    int* front;
    int* rear;
    int* arr;
    int* next;
    int freeSlot;

    kQueue(int n, int k){
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n]; 
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freeSlot = 0;
    }

    void enqueue(int data, int qn){
        
        //check for overflow
        if(freeSlot == -1){
            cout<<"No space is available to store data"<<endl;
            return; 
        }

        //find first free index
        int index = freeSlot;

        //update free slot
        freeSlot = next[index];

        //check if first element
        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            //link the new element to the previous element of the same queue
            next[rear[qn-1]] =  index;
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qn-1] = index;

        //push the element
        arr[index] = data;
    }

    int dequeue(int qn){

        //check for underflow
        if(front[qn-1] == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        };

        //index to pop 
        int index = front[qn-1];

        //update front
        front[qn-1] = next[index];

        //link the new free slot to existing free slot
        next[index] = freeSlot;
        freeSlot = index;
        return arr[index];
    }

    void qfront(int qn){

        //check for empty queue
        if(front[qn-1] == -1){
            cout<<"Queue is empty"<<endl;
            return;
        }

        else cout<<"Front of Queue "<<qn<<": "<<arr[front[qn-1]]<<endl;
    }

};

int main(){

    kQueue Q(10, 3);
    
    Q.enqueue(10, 1);
    Q.enqueue(15, 1);
    Q.enqueue(20, 2);
    Q.enqueue(25, 1);

    Q.qfront(1);
    Q.qfront(2);

    cout<<"Popped element: "<<Q.dequeue(1)<<endl;
    Q.qfront(1);
    cout<<"Popped element: "<<Q.dequeue(2)<<endl;
    cout<<"Popped element: "<<Q.dequeue(1)<<endl;
    cout<<"Popped element: "<<Q.dequeue(1)<<endl;

}