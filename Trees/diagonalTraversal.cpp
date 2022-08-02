//function to print the diagonal traversal of binary tree

vector<int> diagonalTraversal(Node* root){

    vector<int> ans;
    queue<Node*> q;
    
    if(!root) return ans;
    
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        while(temp){
            if(temp->left) q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}