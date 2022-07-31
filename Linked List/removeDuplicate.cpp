//functions to remove the duplicate elements from a linked list which is sorted in ascending order
//eg.  1-1-1-2-3-3-5-8-8-9 => 1-2-3-5-8-9

#include <iostream>
#include "node.cpp"

using namespace std;

//return the new head after removing the duplicate elements
//Method 1 using recursion
Node* removeDuplicates(Node* head){
    //base condition (when the list is empty or only contain a single element simply return the head)
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* newHead = removeDuplicates(temp->next);

    if(head->data != newHead->data){
        head->next = newHead;
        return head;
    }
    else{
        head->next = newHead->next;
        delete(newHead);
        return head;
    }
}

//Method 2
Node* removeDuplicates(Node* head){
    //base condition
    if(head == NULL) return head;

    Node* temp1 = head;
    Node* temp2 = head->next;

    while(temp2 != NULL){
        Node* n = temp2;
        if(temp1->data == temp2->data){
            delete(temp2);
            temp2 = n->next;
        }
        else{
            temp1->next = temp2;
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    temp1->next = NULL;
    return head;
}