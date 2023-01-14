//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
       Node *fast = head, *slow = head, *saved;
       bool cycle = false;
       
       while(fast != NULL && fast->next != NULL){
           saved = slow;
           fast = fast->next->next;
           slow = slow->next;
           if(fast == slow){
               slow = head; 
               cycle = true;
               break;
           }
       }
       if(!cycle){return;}
       if(fast == head){saved ->next = NULL; return;}
        
       while(slow != fast){
           saved = fast;
           fast = fast->next;
           slow = slow->next;
       }
       saved->next = NULL;
   
    }
};

