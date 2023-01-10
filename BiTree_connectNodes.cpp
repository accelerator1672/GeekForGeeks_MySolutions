//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.

    void connect(Node *root)
    {
      
        queue <Node*> mq;
        Node* current; 
        
        mq.push(root);
        mq.push(NULL);
        
        while(!mq.empty()){
            current = mq.front();
            mq.pop();
            
            if(current != NULL ){
                current->nextRight = mq.front();
                
                if(current -> left){mq.push(current->left);}
                if(current->right){mq.push(current->right);}
         
            }else if(!mq.empty()){
                mq.push(NULL);
            }
        }
       
    }    
      
};
