struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.

    int weight(Node* node, int * ptr){
        int l = 0 , r = 0;
        if(node == NULL){return 0;}
        
        if(node -> left){l = 1 + weight(node->left, ptr);}
        if(node -> right){r = 1 + weight(node->right, ptr);}
        if(l+r+1> *ptr){*ptr = l+r+1; }
        
        return (l > r ? l : r);
    }
    int diameter(Node* root) {
        int d = 0;
        weight(root, &d);
        return d;
    }
};
