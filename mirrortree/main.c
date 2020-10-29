#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
	
return(node); 
} 
void mirrortreeofbinarytree(struct node *root){
    if(!root)
    return;

    mirrortreeofbinarytree(root->left);
    mirrortreeofbinarytree(root->right);
    struct node *tmp;
    tmp=root->left;
    root->left=root->right;
    root->right=tmp;
    
    
}
void printtreedata(struct node *root){
    if(!root)
    return;
    
    printtreedata(root->left);
    printf("%d ",root->data);
    printtreedata(root->right);
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


printtreedata(root);
printf("\n");
mirrortreeofbinarytree(root);
printtreedata(root);

return 0; 
} 

