#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node{
  
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){

    cout<<"Enter data: ";
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout<<"Enter data for the left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

void buildTreeLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter data for left of "<<temp->data<<": "<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter data for right of "<<temp->data<<": "<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* root){

    if(!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //to check the end of level
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

}

void reverseLevelOrderTraversal(Node* root){

    if(!root) return;
    vector<int> sol;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        sol.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);

    }

    reverse(sol.begin(), sol.end());
    for(auto x:sol){
        if(x != 0) cout<<x<<" ";
        else cout<<endl;
    }

}

void inOrderTraversal(Node* root){
    if(!root) return;

    if(root->left) inOrderTraversal(root->left);
    cout<<root->data<<" ";
    if(root->right) inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    if(root->left) preOrderTraversal(root->left);
    if(root->right) preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(!root) return;

    if(root->left) postOrderTraversal(root->left);
    if(root->right) postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){

    Node* root = NULL;
    // root = buildTree(root); //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildTreeLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    cout<<"Level order traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"Reverse level order traversal: "<<endl;
    reverseLevelOrderTraversal(root);

    cout<<"\nInOrder traversal: ";
    inOrderTraversal(root);

    cout<<"\nPostOrder traversal: ";
    postOrderTraversal(root);

    cout<<"\nPreOrder traversal: ";
    preOrderTraversal(root);
}