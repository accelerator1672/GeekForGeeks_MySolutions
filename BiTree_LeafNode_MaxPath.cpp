//https://practice.geeksforgeeks.org/problems/maximum-path-sum/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Tree&sortBy=submissions
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

class Solution {
public:
    int max_weight(Node* node, int *ptr, bool root){
        
        int ldata = 0, rdata = 0;
        bool valid = root && ((!node->left && node->right) || (!node->right && node->left));
        
        if(node -> left){ ldata = max_weight(node->left, ptr , 0);}
        if(node -> right){ rdata = max_weight(node->right, ptr, 0);}
        
        if(node->left && node->right || valid){
            
            if(node->data + ldata + rdata > *ptr){
                *ptr = ldata + rdata + node->data;
            }
            valid = 1;
        
        }
        if(valid){return node->data + max(ldata,rdata);}
        else{ return node->left ? ldata+node->data : rdata+node->data; }
    }
    int maxPathSum(Node* root)
    {
        int sum = -1000000;
        max_weight(root, &sum, 1);
       
        return sum;
    }
};
