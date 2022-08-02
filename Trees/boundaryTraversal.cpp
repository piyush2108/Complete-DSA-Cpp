//function to perform a boundary traversal on a binary tree
//left boundary nodes -> leaf nodes -> reverse right boundary nodes

//to store the left boundary nodes excluding the leaf node
void leftTraversal(Node* root, vector<int> &ans){

    if(!root || (root->left == NULL && root->right == NULL)) return;

    ans.push_back(root->data);

    if(root->left) leftTraversal(root->left, ans);
    else leftTraversal(root->right, ans);
}

//to store the leaf nodes
void leafTraversal(Node* root, vector<int> &ans){
    
    if(!root) return;

    if(root->left == NULL && root->right == NULL) ans.push_back(root->data);
    leafTraversal(root->left);
    leafTraversal(root->right);
}

//to store the right boundary nodes
void rightTraversal(Node* root, vector<int> &ans){
    
    if(!root || (root->left == NULL && root->right == NULL)) return;

    if(root->right) rightTraversal(root->right, ans);
    else rightTraversal(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root){

    vector<int> ans;
    if(!root) return;

    ans.push_back(root->data);
    //left boundary nodes
    leftTraversal(root->left, ans);

    //leaf nodes
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);

    //right nodes
    rightTraversal(root->right, ans);

    return ans;
}