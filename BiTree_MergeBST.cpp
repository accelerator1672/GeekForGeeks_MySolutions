//https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void node_insert(Node *node, vector<int> &vec){
        
        if(node->left){node_insert(node->left,vec);}
        vec.push_back(node->data);
        if(node->right){node_insert(node->right, vec);}
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> vec1, vec2, vec;
       
       node_insert(root1, vec1);
       node_insert(root2, vec2);
       
       int sz1 = vec1.size(), sz2 = vec2.size();
       int ptr1 = 0, ptr2 = 0;
       
       while(ptr1 != sz1 || ptr2 != sz2){
        
           if(ptr1 == sz1){
               vec.push_back(vec2[ptr2]);
               ptr2++;
           }
           else if(ptr2 == sz2){
               vec.push_back(vec1[ptr1]);
               ptr1++;
           }else if(vec1[ptr1] < vec2[ptr2]){
               vec.push_back(vec1[ptr1]);
               ptr1++;
           }else{
               vec.push_back(vec2[ptr2]);
               ptr2++;
           }
           
       }
       
       return vec;
    }
};
