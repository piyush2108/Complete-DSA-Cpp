//functions to merge two sorted linked list and do a Merge Sort on a linked list

#include <iostream>
#include "node.cpp"
#include "LinkedList.cpp"

using namespace std;

//to merge two sorted linked lists
Node* mergeSortedLL(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        if(head1 == NULL) return head2;
        else return head1;
    }

    Node* fHead = NULL;
    Node* fTail = NULL;

    if(head1->data < head2->data){
        fHead = head1;
        fTail = head1;
        head1 = head1->next;
    }
    else{
        fHead = head2;
        fTail = head2;
        head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            fTail->next = head1;
            fTail = head1;
            head1 = head1->next;
        }
        else{
            fTail->next = head2;
            fTail = head2;
            head2 = head2->next;
        }
    }

    if(head1 == NULL) fTail->next = head2;
    else fTail->next = head1;

    return fHead;
}

//to merge sort a linked list
Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* mid = midPoint(head);

    Node* head1 = head;
    Node* head2 = mid->next;

    mid->next = NULL;

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    return mergeSortedLL(head1, head2);
}

