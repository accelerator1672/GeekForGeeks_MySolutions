//https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
  public:
  
    void find_depth(Node * node, int depth, int *ptr){
        if(depth > *ptr){*ptr = depth;}
        if(node->left){find_depth(node->left, depth+1, ptr);}
        if(node->right){find_depth(node->right, depth+1, ptr);}
    }
    
    
    bool rotate(Node* node, int target, Node** new_root){
        
        if(node->data == target){*new_root = node; return 1;}
        
        bool lfound = 0, rfound = 0; 
        
        if(node->left){lfound= rotate(node->left, target, new_root);}
        if(node->right){rfound = rotate(node->right, target, new_root);}
        
        if(lfound){
            
            if(node->left->right){ node->left->left = node->left->right;}
            
            node->left->right = node;
            node->left = NULL;
            
        }else if(rfound){
            
            if(node->right->left){node->right->right = node->right->left;}
            
            node->right->left = node;
            node->right = NULL;
        }
   
        return lfound || rfound;
    }
    
    int minTime(Node* root, int target) 
    {

        Node* new_root;
        int max_depth = 0;
        
        rotate(root, target, &new_root);

        find_depth(new_root, 0, &max_depth);
        
        return max_depth;
    }
};
