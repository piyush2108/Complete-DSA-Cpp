//function to print the left and right view of a given binary tree

//left view
void helper(Node* root, vector<int> &ans, int level){

    if(!root) return;

    if(level == ans.size()) ans.push_back(root->data);

    helper(root->left, ans, level+1);
    helper(root->right, ans, level+1);
}

vector<int> leftView(Node* root){

    vector<int> ans;
    if(!root) return ans;

    helper(root, ans, 0);
    return ans;
}

//right view
void helper(Node* root, vector<int> &ans, int level){

    if(!root) return;

    if(level == ans.size()) ans.push_back(root->data);

    helper(root->right, ans, level+1);
    helper(root->left, ans, level+1);
}

vector<int> rightView(Node* root){

    vector<int> ans;
    if(!root) return ans;

    helper(root, ans, 0);
    return ans;
}