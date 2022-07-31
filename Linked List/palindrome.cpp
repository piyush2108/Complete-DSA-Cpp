//functions to reverse a linked list and to check whether the given linked list is a palindrom or not

#include <iostream>
#include "node.cpp"

using namespace std;

//to reverse a linked list
Node* reverseLL(Node* head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = curr;
}

//to reverse a linked list recursively
Node* reverseLL2(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLL2(head->next);
    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;

    return newHead;
}

//to check for palindrome
bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL) return true;

    //mid point of the linked list
    Node* fast = head;
    Node* slow = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* newHead = slow->next;
    slow->next = NULL;
    
    newHead = reverseLL(newHead);

    //compare the sub linked lists
    Node* firstHead = head;
    Node* secondHead = newHead;

    while(firstHead && secondHead){
        if(firstHead->data != secondHead->data){
            return false;
            break;
        } 
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    //rejoin the two parts of the linked list
    firstHead = head;
    secondHead = reverseLL(newHead);

    while(firstHead->next != NULL){
        firstHead = firstHead->next;
    }
    firstHead->next = secondHead;

    return true;
}