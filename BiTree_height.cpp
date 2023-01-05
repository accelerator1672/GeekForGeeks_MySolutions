//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Tree&sortBy=submissions
/*
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
class Solution{
    public:
    
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
       if(node == NULL){ return 0;}
       int l = 0, r =0;
       l = 1+height(node->left);
       r = 1+height(node->right);
       
       return max(l,r);
    }
};
