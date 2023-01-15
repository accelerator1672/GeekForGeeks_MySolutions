//https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1
/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */

class Solution{
  public:
    TNode* Build_BST(LNode** node, int ncount){
        
        if(ncount == 0){return NULL;} // if there are no more nodes to build subtrees
        
        TNode* left = Build_BST(node, ncount/2);
        
        TNode* parent = new TNode((*node)->data);
        *node = (*node)->next;
        
        TNode* right = Build_BST(node, ncount - ncount/2 - 1);
        
        parent->left = left;
        parent->right = right;
        
        return parent;
        
        
    }
    TNode* sortedListToBST(LNode *head){
        
        int ncount = 0;
        
        for(LNode* node = head; node != NULL; node = node->next){ ncount++; }
        
        return Build_BST(&head, ncount);    
       
     }
  
  // HERE IS ALTERNATIVE METHOD USING ARRAY INDEX
  
    /*TNode* Build_BST(vector<int> &vec, int l, int r ){
        if(r-l ==1 ){
            TNode* left = new TNode(vec[l]);
            TNode* parent = new TNode(vec[r]);
            parent->left = left;
            return parent;
        }else if(r==l){
            TNode* node = new TNode(vec[l]);
            return node;
        }else{
            int mid = l+(r+1-l)/2;
            TNode* parent = new TNode(vec[mid]);
            parent->left = Build_BST(vec, l, mid-1);
            parent->right = Build_BST(vec, mid+1, r);
            return parent;
        }
    }
    TNode* sortedListToBST(LNode *head) {
       vector<int> vec;
       for(LNode* node = head; node != NULL; node = node->next){
           vec.push_back(node->data);
       }
 
       return Build_BST(vec, 0, vec.size()-1);
       
    }*/
};
