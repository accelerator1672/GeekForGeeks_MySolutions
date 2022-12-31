//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Linked%20List&sortBy=submissions

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


// } Driver Code Ends

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *reverse(Node* head){
        Node *y=head,*r,*t = NULL; 
        while(y!= NULL){
            r=y->next; y->next = t; t = y; y = r; 
        }
        return t;
    }
    bool isPalindrome(Node *head)
    {
        int len = 0;
        Node *left = head , *right = head, *temp;
        
        for(auto node = head; node != NULL; node = node ->next){ len++ ;}
        
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


//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
