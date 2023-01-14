//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *reverse(Node* head){  
        Node *y=head,*r,*t = NULL; 
        while(y){ r=y->next; y->next = t; t = y; y = r;}
        return t;
    }
  
    bool isPalindrome(Node *head)
    {
        int len = 0;
        Node *left = head , *right = head, *temp;
        
        for(auto node = head; node != NULL; node = node ->next){ len++;}
        
        if(len == 1){return 1;}
  
        for(int i = 0; i<len/2; i++){
            if(i == (len/2)-1){temp = right;}
            right = right->next;
        } 
        
        temp ->next = NULL;
        
        if(len%2){right = right->next;}
        
        right = reverse(right);
        
        while(left != NULL){
            if(left -> data != right ->data){return 0;}
            left = left->next;
            right = right ->next;
        }
        return 1;
        
    }
};
