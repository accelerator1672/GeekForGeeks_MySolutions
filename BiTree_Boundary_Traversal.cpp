// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Tree&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    
    void left_boundary(Node *node, vector<int> &list){
        if(!node->left && !node->right){return;}

        list.push_back(node->data);
        
        if(node->left){left_boundary(node->left, list);}
        else{left_boundary(node->right, list);}
        
    }
    
    void leaf_nodes (Node* node, vector<int> &list){
        if(!node->left && !node->right){
            list.push_back(node->data);
        }
        
        if(node->left){leaf_nodes(node->left, list);}
        if(node->right){leaf_nodes(node->right, list);}
    }
    
    void right_boundary (Node* node, vector <int> &list){
        if(!node->left && !node->right){return;}
        
        if(node->right){right_boundary(node->right, list);}
        else{right_boundary(node->left, list);}
        
        list.push_back(node->data);
    }
    
    vector <int> boundary(Node *root){
        
        vector<int> list;
        list.push_back(root->data);
        if(root ->left){left_boundary(root->left, list);}
        if(root->left || root->right){leaf_nodes(root, list);}
        if(root -> right){right_boundary(root->right, list);}

        return list;
    }
};
