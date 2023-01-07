//https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node *link = head, *saved, *new_head;
        int count = 0;
        for(link = head; link->next != NULL; link = link->next){
            count++;
            if(count == k){ saved = link; }
        }
        if(k == ++count){return head;}
        
        new_head = saved->next;
        saved ->next = NULL;
        link->next = head;
        
        return new_head;
        
    }
};
