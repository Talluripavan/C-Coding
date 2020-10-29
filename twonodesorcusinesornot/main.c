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
//CHECK BOTH LEVEL ARE SAME OR NOT
int levelofchild(struct node *root,int val,int lev){
    if(root==NULL)
        return 0;
    if(root->data==val){
        printf("child=%d \n",lev);
        return lev;
     }
    int ll=levelofchild(root->left,val,lev+1);
     if(ll!=0)
        return ll;
    return levelofchild(root->right,val,lev+1);
    
}
//IS BOTH NODES BELONGS TO SAME PARENT
int Childofsameparent(struct node *root,int c1,int c2){
    if(root==NULL)
        return 0;
        
        return((root->left==c1 && root->right==c2) ||
                (root->left==c1 && root->right==c2) ||
                Childofsameparent(root->left,c1,c2) ||
                Childofsameparent(root->right,c1,c2));
        
}
void TwonodesorCusinesorNOt(struct node* root,int c1,int c2) 
{ 
    if((levelofchild(root,c1,1)==levelofchild(root,c2,1)) && !(Childofsameparent(root,c1,c2)))
            printf("\n BOTH ARE CUSINES\n");
        else
            printf("NOT CUSINES \n");
      
} 

int main()
{
  struct node *root = newNode(10); 
root->left	 = newNode(20); 
root->right	 = newNode(30); 
root->right->left = newNode(22);
root->right->left->right = newNode(33);
root->left->left = newNode(40); 
root->left->right = newNode(15);
root->left->right->left = newNode(35); 
root->left->right->right = newNode(66); 
//root->right->left->right = newNode(22);

TwonodesorCusinesorNOt(root,35,33);
    
    return 0;
}



