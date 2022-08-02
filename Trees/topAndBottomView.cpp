//function to print the top view and bottom view of a given binary tree

//top view of a binary tree
vector<int> topView(Node* root){

    vector<int> ans;
    if(!root) return ans;

    map<int, int> nodes;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;   //hd -> horizontal distance

        if(nodes.find(hd) == nodes.end()) nodes[hd] = frontNode->data;

        if(frontNode->left) q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right) q.push(make_pair(frontNode->right, hd+1));
    }

    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;
}

//bottom view of a binary tree
vector<int> topView(Node* root){

    vector<int> ans;
    if(!root) return ans;

    map<int, int> nodes;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;   //hd -> horizontal distance

        nodes[hd] = frontNode->data;

        if(frontNode->left) q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right) q.push(make_pair(frontNode->right, hd+1));
    }

    for(auto i: nodes){
        ans.push_back(i.second);
    }

    return ans;
}