#include <iostream>
#include <queue>
#include "queueArray.cpp"

using namespace std;

int main(){

    //Implementation of Queue using Linked List
    Queue Q;

    Q.enqueue(2);
    Q.enqueue(1);
    Q.enqueue(0);
    Q.enqueue(4);

    Q.dequeue();

    // //Implementation of Queue using array
    // Queue Q;

    // Q.enqueue(2);
    // Q.enqueue(9);
    // Q.enqueue(0);
    // Q.enqueue(3);
    // Q.enqueue(6);

    // cout<<Q.front()<<endl;
    // cout<<Q.back()<<endl;

    // Q.dequeue();
    // Q.dequeue();
    // if(Q.isEmpty()) cout<<"Queue is empty"<<endl;
    // else cout<<"Queue is not empty"<<endl;

    // cout<<Q.front()<<endl;
    // cout<<Q.back()<<endl;

    // //Queue in STL
    // queue<int> Q;

    // //to insert element in queue (insert to back)
    // Q.push(3);
    // Q.push(10);
    // Q.push(4);
    // Q.push(0);
    // Q.push(7);

    // //3(front) 10 4 0 7(back)
    // //to print the size of Queue
    // cout<<"Size of queue is: "<<Q.size()<<endl;

    // //to pop element from queue (pop from front)
    // cout<<"Element at front: "<<Q.front()<<endl;
    // cout<<"Element at back: "<<Q.back()<<endl;
    // Q.pop();
    // Q.push(3);
    // cout<<"Element at front: "<<Q.front()<<endl;
    // cout<<"Element at back: "<<Q.back()<<endl;
    
    // //to check if queue is empty or not
    // if(Q.empty()) cout<<"Queue is empty."<<endl;
    // else cout<<"Queue is not empty"<<endl;
    // cout<<"Size of queue is: "<<Q.size()<<endl;

}