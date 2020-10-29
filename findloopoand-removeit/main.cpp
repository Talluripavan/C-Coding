#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void push(struct node** head_ref, int new_data) 
{ 
   
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
int removeloopinlinkedlist(struct node *slow,struct node *fast){
    struct node *ptr1=NULL;
    
    while(slow!=fast){
        ptr1=slow;
        slow=slow->next;
        fast=fast->next;
        
        if(slow==fast)
        break;
    }
    ptr1->next=NULL;
    
    
    return 0;
}
int DetectLoop(struct node *head){
    struct node *fast=head;
    struct node *slow=head;
    
    while(slow && fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        
        if(fast==slow){
            removeloopinlinkedlist(slow,head);
            return 1;
        }
    }
    return 0;
}
void linkedlistprint(struct node *head){
    struct node *tmp=head;
    if(tmp==NULL)
        return ;
    while(tmp){
        cout<<"->"<<tmp->data;
        tmp=tmp->next;
        
    }
}

int main() 
{ 
    struct node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
    head->next->next->next->next = head; 
   linkedlistprint(head);   
   cout<<endl;
    if (DetectLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
    linkedlistprint(head);    
  
    return 0; 
} 
