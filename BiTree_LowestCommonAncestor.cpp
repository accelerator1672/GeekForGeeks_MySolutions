//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    int find_lca(Node * node, int n1, int n2, Node** common){
        int count = 0, lcount = 0, rcount = 0;
        if(node->data == n1 || node -> data == n2){ (n1==n2) ? count++ : count+=2 ;}
        
        if(node->left){lcount += find_lca(node->left, n1, n2, common);}
        if(node->right){rcount += find_lca(node->right, n1, n2, common);}
        
        if(count + lcount + rcount == 2){*common =  node;}
        else if(count){*common = node;}
      
        
        return count || lcount || rcount;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       Node *common = root;
       find_lca(root, n1, n2, &common);
       return common;
   
    }
};
