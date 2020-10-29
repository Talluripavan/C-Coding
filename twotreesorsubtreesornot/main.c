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
struct node* node = (struct node*) 
					malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 
	
return(node); 
} 
int IdenticaltreesorNot(struct node *root1,struct node *root2){
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    if(root1->data==root2->data &&
    IdenticaltreesorNot(root1->left,root2->left)&&
    IdenticaltreesorNot(root1->right,root2->right))
        return 1;
    else
        return 0;
       
    
}
int subtreeornot(struct node *root1,struct node *root2){
    if(root1==NULL)
        return 0;
    if(root2==NULL)
        return 1;
        if(IdenticaltreesorNot(root1,root2)==1)
            return 1;
        if(subtreeornot(root1->left,root2)||
        subtreeornot(root1->right,root2))
            return 1; 
         else
            return 0;
       
}
	
int main() 
{ 
struct node *root = newNode(10); 
root->left	 = newNode(20); 
root->right	 = newNode(30); 
root->left->left = newNode(40); 
root->left->right = newNode(15);
root->left->right->left=newNode(35); 
root->left->right->right=newNode(25); 

struct node *root1=newNode(15); 
root1->left=newNode(35); 
root1->right=newNode(25); 
 

if(subtreeornot(root,root1))
    printf("Subtree:\n");
else
    printf("Not Subtree:\n");



return 0; 
} 

