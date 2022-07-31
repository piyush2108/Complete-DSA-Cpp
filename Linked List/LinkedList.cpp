#include <iostream>
#include "node.cpp"

using namespace std;

//to take input from the user and return the pointer to the head node
Node* takeInput(){
    char ans;
    Node* head = NULL;
    Node* temp;

    cout<<"Do you want to add a node to the linked list: y | n"<<endl;
    cin>>ans;
    while(ans == 'y' || ans == 'Y'){
        int num;
        cin>>num;

        Node* newNode = new Node(num);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }
        
        cout<<"Do you want to add a node to the linked list: y | n"<<endl;
        cin>>ans;
    }
    return head;
}

//to find the length of a linked list
int lengthLL(Node* head){
    if(head == NULL) return 0;

    Node* temp = head;
    int count = 0;
    
    while(temp != NULL){
        temp = temp->next;
        count++;
    }

    return count;
}

//to find the lenght of a linked list using recursion
int lengthLL2(Node* head){
    if(head == NULL) return 0;
    else if(head->next == NULL) return 1;

    return 1+lengthLL2(head->next);
}

//to insert a new element at the end of linked list
void insertLL(Node* head, int n){
    Node* newNode = new Node(n);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

//to insert a new element in a linked list at ith position
void insertLL(Node* &head, int n, int i){
    if(head == NULL) return;

    int length = lengthLL2(head);
    if(i >= length) return;

    Node* newNode = new Node(n);
    Node* temp = head;

    if(i == 0){
        newNode->next = head;
        head = newNode;
        return;
    }

    for(int k=0; k<i-1; k++){
        temp = temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = newNode;
    newNode->next = temp2;
    delete(temp2);
}

//to delete the node at ith position in a linked list
void deleteNode(Node* &head, int i){
    if(head == NULL) return;

    Node* temp = head;
    if(i == 0){
        head = temp->next;
        delete(temp);
        return;
    }

    int count = 0;
    while(temp != NULL && count < i-1){
        temp = temp->next;
        count++;
    }

    if(temp != NULL && temp->next != NULL){
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete(temp2);
    }
}

//to print the linked list
void printLL(Node* head){
    if(head == NULL) return;

    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

//to print the ith node of a linked list
void printNode(Node* head, int i){
    if(head == NULL) return;

    int length = lengthLL2(head);
    if(i >= length) return;

    Node* temp = head;

    for(int k=0; k<i; k++){
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

//to check if a node is present or not, if present return the index
ing findNode(Node* head, int n){
    if(head == NULL) return;

    if(head->data == n) return 0;

    int ans = findNode(head, n);
    if(ans == -1) return ans;
    else return 1+ans;
}

//to find the mid Node of a linked list
Node* midPoint(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL || fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){
    //Static allocation
    // Node n1(2);
    // Node n2(4);
    // Node n3(8);
    // Node n4(0);
    // Node n5(10);

    // Node* head = &n1;  //node n1 is the head node
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    //take input function
    // Node* Head = takeInput();
    // while(Head != NULL){
    //     cout<<Head->data<<" ";
    //     Head = Head->next;
    // }cout<<endl;

    //Dynamic allocation
    // Node *N1 = new Node(3);
    // Node *N2 = new Node(11);
    // Node *N3 = new Node(7);
    // Node *N4 = new Node(5);

    // Node* head2 = N1;  //node N1 is the head node
    // N1->next = N2;
    // N2->next = N3;
    // N3->next = N4;

    // printLL(head2);
    // insertLL(head2, 6);
    // insertLL(head2, 3);
    // printLL(head2);
    // cout<<lengthLL(head2)<<endl;
    // deleteNode(head2, 0);
    // printLL(head2);
    // insertLL(head2, 2, 0);
    // printLL(head2);

    // printNode(head2, 6);
    // printNode(head2, 1);
    // printNode(head2, 0);
    // printNode(head2, 9);
    // printNode(head2, 7);
    // cout<<endl;
    // cout<<lengthLL2(head2);

}