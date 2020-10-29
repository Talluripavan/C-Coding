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
struct node *Ancestoroftwono(struct node *root,int n1,int n2)
{
    if(root==NULL)
       return NULL;
       
        if(root->data > n1 && root->data > n2)
        return Ancestoroftwono(root->left,n1,n2);
    
        if(root->data < n1 && root->data < n2)
        return Ancestoroftwono(root->right,n1,n2);
    
        return root;
    
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
root->left->right->right = newNode(25); 

printtreedata(root);

struct node *ans=Ancestoroftwono(root,25,15);
printf("%d\n",ans->data);

return 0; 
} 


