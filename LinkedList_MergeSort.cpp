
//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Linked%20List&sortBy=submissions

//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    int list_length(Node* head){
        int len = 0;
        for(auto node = head; node != NULL; node = node->next){ len++; }
        return len;
    }
    
    Node* mergeSort(Node* head) {
        int len = list_length(head);
        return mergesort(head, len);
    }
    Node* mergesort(Node* head, int len){
       if(len == 1 ){return head;}
        Node *left = head, *right= head;
        Node *saved;
     
        int mid = len/2 + len%2;
      
        for(int i = 0; i < mid; i ++){
            if (i == mid-1){saved =right;}
            right = right->next;
        }
        saved->next = NULL;
  
        left = mergesort(left, mid);
        right = mergesort(right, len/2);
        return merge(left,right);
        
    }
    Node* merge(Node* left, Node* right){
        Node *merged, *temp;
        
        if(left->data <= right->data){
            merged = new Node(left->data);
            temp = merged;
            left = left->next;
        }
        else{
            merged = new Node(right->data);
            temp =merged;
            right = right->next;
        }
        while(left!= NULL || right!= NULL){
            
            if(right == NULL || (left!=NULL && (left->data <= right->data))){
                temp->next = new Node(left->data);
                temp = temp->next;
                left = left->next;
                
            }else{
                temp -> next = new Node(right->data);
                temp = temp->next;
                right = right->next;
            }
        }
        return merged;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
