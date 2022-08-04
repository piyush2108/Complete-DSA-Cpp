//functions to construct a binary tree from (given inorder and preorder traversal) and (given inorder and postorder traversal)

//using InOrder and PreOrder traversal
void createMapping(int in[], map<int, int> &nodeToIndex, int n){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* helper(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
    
    if(index >= n || inOrderStart > inOrderEnd) return NULL;
    
    int element = pre[index++];
    Node* root = new Node(element);
    int position = nodeToIndex[element];
        
    root->left = helper(in, pre, index, inOrderStart, position-1, n, nodeToIndex);
    root->right = helper(in, pre, index, position+1, inOrderEnd, n, nodeToIndex);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node* root = helper(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
    return root;
}

//using InOrder and PostOrder traversal
void createMapping(int in[], map<int, int> &nodeToIndex, int n){
    for(int i=0; i<n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* helper(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
    
    if(index < 0 || inOrderStart > inOrderEnd) return NULL;
    
    int element = post[index--];
    Node* root = new Node(element);
    int position = nodeToIndex[element];
        
    root->right = helper(in, post, index, position+1, inOrderEnd, n, nodeToIndex);
    root->left = helper(in, post, index, inOrderStart, position-1, n, nodeToIndex);
    
    return root;
} 

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postOrderIndex = n-1;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node* root = helper(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
    return root;
}