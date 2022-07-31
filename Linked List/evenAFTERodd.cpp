//function to arange the element of a linked list such that all even numbers are placed after the odd numbers

#include <iostream>
#include "node.cpp"

Node* evenAfterOdd(Node* head){
    if(head == NULL) return head;

    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data%2 == 0){
            if(evenHead == NULL){
                evenHead = temp;
                evenTail = temp;
            }
            else{
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else{
            if(oddHead == NULL){
                oddHead = temp;
                oddTail = temp;
            }
            else{
                oddTail->next = temp;
                oddTail = temp;
            }
        }
    }
    if(oddHead == NULL){
        head = evenHead;
        evenTail->next = NULL;
    }
    else if(evenHead == NULL){
        head = oddHead;
        oddTail->next = NULL;
    }
    else{
        head = oddHead;
        oddTail->next = evenHead;
        evenTail->next = NULL;
    }
    return head;
}
