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
int max(int a,int b){
    return (a>=b)?a:b;
}

int DiameterofBinarytree(struct node *root,int *height){
    int lheight=0,rheight=0;
    int ldiameter=0,rdameter=0;
    
    if(root==NULL){
        *height=0;
        return 0;
    }
    
    ldiameter=DiameterofBinarytree(root->left,&lheight);
    rdameter=DiameterofBinarytree(root->right,&rheight);
    
    *height= max(lheight,rheight)+1;
    
    return max(lheight+rheight+1,max(ldiameter,rdameter));
}
void Diameteroftree(struct node *root)
{
    int height=0;
    DiameterofBinarytree(root,&height);
    printf("%d ",height);
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

Diameteroftree(root);
    
    return 0;
}

