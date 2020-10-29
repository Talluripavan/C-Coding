#include<stdio.h>
#include<stdlib.h>

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
      printf("%d ", node->data); 
      printInorder(node->right); 
} 
struct node *BTToDLL(struct node *root){
    if(root==NULL)
    return root;
    //find inorder predecessor after loop
    if(root->left!=NULL){
        struct node *leftptr=BTToDLL(root->left);
        for(;leftptr->right!=NULL;leftptr=leftptr->right);
        
        leftptr->right=root;
        root->left=leftptr;
    }
    //find inorder successor after loop
    if(root->right!=NULL){
        struct node *rightptr=BTToDLL(root->right);
        for(;rightptr->left!=NULL;rightptr=rightptr->left);
        
        rightptr->left=root;
        root->right=rightptr;
    }
    return root;
}
void printDLLnodes(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d->",head->data);
        head=head->right;
    }
}
struct node *ConBinarytreetoDLL(struct node *root){
    if(root==NULL)
    return root;
    
    struct node *head=BTToDLL(root);
    while(head->left!=NULL){
        head=head->left;
    }
   
    return head;
}
void inordersuccessor(struct node *node,int succ){
    
    if (node == NULL) 
        return; 
       
      inordersuccessor(node->left,succ); 
      if(node->data==succ){
         printf("%d ", node->data);
          return;
      }
      inordersuccessor(node->right,succ);
      
}
int main(){
    struct node *root = newNode(10); 
root->left	 = newNode(20); 
root->right	 = newNode(30); 
root->left->left = newNode(40); 
root->left->right = newNode(15);
root->left->right->left = newNode(35); 
root->left->right->right = newNode(66); 

printInorder(root);
 //struct node *head=ConBinarytreetoDLL(root);
 printf("\n");
//printDLLnodes(head);

inordersuccessor(root,40);
}
