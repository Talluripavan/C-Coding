#include<stdlib.h>
#include <stdio.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *
newNode (char data)
{
  struct node *node = (struct node *) malloc (sizeof (struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}



int Ancestorsofanode(struct node *root,int ancestro){
    if(root==NULL)
        return 0;
    
    if(root->left->data==ancestro || root->right->data==ancestro || Ancestorsofanode(root->left,66) || Ancestorsofanode(root->right,66))
    {
        printf("%d ",root->data);
        return 1;
    }
    return 0;
}    
    
    

  int main ()
  {
    struct node *root = newNode (10);
    root->left = newNode (20);
    root->right = newNode (30);
    root->left->left = newNode (40);
    root->left->right = newNode (15);
    root->left->right->left = newNode (35);
    root->left->right->right = newNode (66);
    
    //printInorder (root, 2,0);
    Ancestorsofanode(root,66);

    return 0;
  }

