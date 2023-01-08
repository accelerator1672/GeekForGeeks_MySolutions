//https://practice.geeksforgeeks.org/problems/sum-tree/1

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    int weight(Node *node, int *ptr){
        
        int mweight = node->data, lweight = 0, rweight =0;
  
        if(node->left){lweight+= weight(node->left, ptr);}
        if(node->right){rweight+=weight(node->right, ptr);}
              
        if(*ptr && (node->left || node->right) && (mweight != lweight+rweight)){
            *ptr = 0;
        }
        
        return mweight+lweight+rweight;
    }
    
    bool isSumTree(Node* root)
    {
        int sum_tree = 1;
        
        weight(root, &sum_tree);
        
        return sum_tree;
    }
};
