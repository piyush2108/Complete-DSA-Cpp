//function to find the minimum time required to burn a complete binary tree if a given target node is set on fire
//given that in 1 sec all nodes connected to target node get burned

//to create a mapping of each node with it's parent node and find the target node
Node* createMapping(Node* root, map<Node*, Node*> &childToParent, int target){
        
    queue<Node*> q;
    q.push(root);
    Node* targetNode = NULL;
    childToParent[root] = NULL;
    
    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();
        
        if(temp->data == target) targetNode = temp;
        
        if(temp->left){
            q.push(temp->left);
            childToParent[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            childToParent[temp->right] = temp;
        }
    }
    
    return targetNode;
}

//to calculate the time required to burn the complete binary tree
void burnTree(Node* targetNode, map<Node*, Node*> childToParent, int &ans){
    
    map<Node*, bool> visited;
    queue<Node*> q;
    
    q.push(targetNode);
    visited[targetNode] = true;
    
    while(!q.empty()){
        
        bool flag = 0;
        int size = q.size();
        
        for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            
            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            
            if(childToParent[front] && !visited[childToParent[front]]){
                flag = 1;
                q.push(childToParent[front]);
                visited[childToParent[front]] = 1;
            }
        }
        
        if(flag) ans++;
    }
}

int minTime(Node* root, int target) 
{
    map<Node*, Node*> childToParent;
    int ans = 0;
    
    Node* targetNode = createMapping(root, childToParent, target);
    burnTree(targetNode, childToParent, ans);
    
    return ans;
}