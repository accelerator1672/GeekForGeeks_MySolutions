https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int common_root(Node* node, Node** common, int a, int b){
        int count = 0, lcount = 0, rcount = 0;
        
        if(node->data == a || node->data == b){ (a==b) ? (count+=2) : (count++); }
        
        if(node->left){lcount = common_root(node->left, common, a, b);}
        if(node->right){rcount = common_root(node->right, common, a, b);}
        
        if(count + lcount +rcount == 2){*common = node;}
        
        return count || lcount || rcount;
        
    }
    int distance(Node* node, int data, int *dist){
        if(node->data == data){return 1;}
        
        int lfound=0, rfound=0;
        
        if(node->left){lfound = distance(node->left, data, dist);}
        if(node->right){rfound = distance(node->right, data, dist);}
        
        if(lfound || rfound){(*dist)++;}
        
        return lfound || rfound;
    }
    int findDist(Node* root, int a, int b) {

        Node* common;
        int adist = 0, bdist = 0;

        common_root(root, &common, a, b);

        distance(common, a, &adist);
        distance(common, b, &bdist);
        
        return adist+bdist;
    }
};
