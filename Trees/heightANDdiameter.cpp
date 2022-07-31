//function to calculate the height of a binary tree
//height -> longest path between a root and a leaf node

int heightBT(Node* root){

    //base condition
    if(!root) return 0;

    int maxHeight = max(heightBT(root->left), heightBT(root->right));

    return 1+maxHeight;
}

//function to calculate the diameter of a binary tree
//diameter -> number of nodes on the longest path between two end nodes

//return ans as a pair (diameter, height)
pair<int, int> helper(Node* root){
    if(!root){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = helper(root->left);
    pair<int, int> right = helper(root->right);

    int sol1 = left.first; //diameter from left node
    int sol2 = right.first; //diameter from second node
    int sol3 = left.second + right.second +1; //diameter from both left and right node

    pair<int, int> ans;
    ans.first = max(sol1, sol2); //diameter
    ans.second = max(left.second, right.second) + 1; //height

    return ans;
}

int diameter(Node* root){

    pair<int, int> ans = helper(root);
    return ans.first;

}