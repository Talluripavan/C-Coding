#include<stdlib.h>
#include <stdio.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(char data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
      printInorder(node->left); 
      printf("%c ", node->data); 
      printInorder(node->right); 
} 
struct node** Createqueue(int *front,int *rear){
    struct node **queue-(struct node **)malloc(sizeof(struct node*)*50);
    *front=0;
    *rear=0;
    return queue;
}
void enqueue(struct node **queue,int *rear,int node){
    queu[(*rear)++]=node;
    
}
struct node* Dequeuenode(struct node **queue,int *front){
    return queue[(*front)++];
}
int Isqueueempty(int *f,int *r){
    return (*f==*r);
}
void levelordertraversal(struct node *root){
    int front,rear;
    if(root){
    struct node *queue=Createqueue(&front,&rear);
    enqueue(queue,&rear,root);
    
    while(!Isqueueempty(&front,&rear)){
        struct node *tmp=Dequeuenode(queue,&front);
        printf("%d ",tmp->data);
        if(tmp->left)
            enqueue(queue,&rear,tmp->left);
        if(tmp->right)
            enqueue(queue,&rear,tmp->right);
            
            
        }
    }
}
int main()
{
struct node *root = newNode(10); 
root->left	 = newNode(20); 
root->right	 = newNode(30); 
root->left->left = newNode(40); 
root->left->right = newNode(15);
root->left->right->left = newNode(35); 
root->left->right->right = newNode(66); 

levelordertraversal(root);
    
    return 0;
}
