#include <stdio.h>
#include<stdlib.h>
struct node{
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
void LeftBoundary(struct node *root){
    if(root==NULL)
    return;
    if(root->left){
        printf("%d ",root->data);
       LeftBoundary(root->left);
    }else if(root->right){
        printf("%d ",root->data);
        LeftBoundary(root->right);
    }
}
void RightBoundary(struct node *root)
{
    if(root==NULL)
        return;
        
    if(root->right){
        RightBoundary(root->right);
        printf("%d ",root->data);
    }else if(root->left){
        RightBoundary(root->left);
        printf("%d ",root->data);
    }    
}
void leavesoftree(struct node *root){
    if(root==NULL)
    return;
    leavesoftree(root->left);
    
    if(!(root->left) && !(root->right))
        printf("%d ",root->data);
        
    leavesoftree(root->right);    
}
void BoundaryTraversal(struct node *root){
    
    if(root==NULL)
    return;
    printf("%d ",root->data);
    LeftBoundary(root->left);
    leavesoftree(root->left);
    leavesoftree(root->right);
    RightBoundary(root->right);
}

int main()
{
    printf("Hello World\n");
struct node *root = newNode(10); 
root->left	 = newNode(20); 
root->right	 = newNode(30); 
root->left->left = newNode(40); 
root->left->right = newNode(15);
root->left->right->left = newNode(35); 
root->left->right->right = newNode(66); 

BoundaryTraversal(root);

    return 0;
}
