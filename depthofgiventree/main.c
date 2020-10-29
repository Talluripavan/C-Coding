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


void
printInorder (struct node *node, int k,int d)
{
  if (node)
    {
      
      if (k == node->data)
	{
	  printf ("%d-Depth=%d ", node->data, max);
	  return;
	}
    
	  printInorder (node->left,k,d+1);
       
	  printInorder (node->right,k,d+1);
	  
	}

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
    
    printInorder (root, 2,0);

    return 0;
  }
