//functions to insert or delete a node from ith position in a linked list

#include <iostream>
#include "node.cpp"

using namespace std;

int lenghtLL(Node* head){
    if(head == NULL) return 0;

    Node* temp = head;
    return 1+lenghtLL(temp->next);
}

//to insert a node at ith position in a linked list
//return the new head after inserting the element
Node* insertNode(Node* head, int i, int n){
    if(head == NULL) return head;

    Node* temp = head;
    if(i == 0){
        Node* newNode = new Node(n);
        head = newNode;
        newNode->next = temp;
        return head;
    }
    
    head->next = insertNode(temp->next, i-1, n);
    return head; 
}

//to delete a node at ith position in a linked list
Node* deleteNode(Node* head, int i){
    if(head == NULL) return head;

    Node* temp = head;
    if(i == 0){
        head = temp->next;
        delete(temp);
        return head;
    }

    head->next = deleteNode(temp->next, i-1);
    return head;
}