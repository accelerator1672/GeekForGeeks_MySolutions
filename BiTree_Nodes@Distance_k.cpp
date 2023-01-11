//https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    bool rotate(Node* node, int target, Node** new_root){
        
        if(node->data == target){*new_root = node; return 1;}
        
        bool lfound = 0, rfound = 0; 
        
        if(node->left){lfound= rotate(node->left, target, new_root);}
        if(node->right){rfound = rotate(node->right, target, new_root);}
        
        if(lfound){
            
            if(node->left->right){ 
                
               if(node->left->left){
                    Node* virtual_node = newNode(-1);
                    virtual_node ->left = node->left->left;
                    virtual_node ->right = node->left ->right;
                    node->left->left = virtual_node;
                    
               }else{ node->left->left = node->left->right; }
            }
            
            node->left->right = node;
            node->left = NULL;
            
        }else if(rfound){
            
            if(node->right->left){
                if(node->right->right){
                    Node* virtual_node = newNode(-1);
                    virtual_node -> left = node->right->left;
                    virtual_node -> right = node ->right->right;
                    node->right->right = virtual_node;
                }else{ node->right->right =node->right->left; }
            }
            
            node->right->left = node;
            node->right = NULL;
        }
        
        return lfound || rfound;
        
    }
    
    void node_insert(Node *node, int dist, int k, vector<int> &res){
        if(dist == k){res.push_back(node->data); return;}
        
        if(node->left){
            int ldist = (node->left->data < 0) ? dist : dist+1;
            node_insert(node->left, ldist, k, res);
        }
        if(node->right){
            int rdist = (node->right->data <0) ? dist : dist+1;
            node_insert(node->right, rdist, k, res);
            
        }
        
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        Node* new_root;
        vector<int> result;
        
        rotate(root, target, &new_root);
        node_insert(new_root, 0, k, result);
        
        sort(result.begin(), result.end());
        return result;
    }
};
