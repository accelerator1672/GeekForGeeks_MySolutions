//https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1

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
    TNode* Build_BST(vector<int> &vec, int l, int r ){
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
       
    }
};
