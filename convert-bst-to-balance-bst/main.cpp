#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
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
struct node* convertBSTTOBBST(int *nodes,int start,int end){
    if(start>end)
    return NULL;
    
    int mid=(start+end)/2;
    struct node *root=nodes[mid];
    
    root->left=convertBSTTOBBST(nodes,start,mid-1);
    root->right=convertBSTTOBBST(nodes,mid+1,end);
    
    return root;
}
void storenodesintoVector(struct node *root,int *nodes){
    if(root==NULL)
    return;
    static int i;
    storenodesintoVector(root->left,nodes);
    for( i=0;i<=n;i++)
    nodes[i]=root->data;
    storenodesintoVector(root->right,nodes);
}
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
         printInorder(node->left);
         printf("%d ", node->data); 
      printInorder(node->right); 
} 
struct node *ConvertBST_to_BalancedBST(struct node *root){
    struct nodes *nodes[4];
    storenodesintoVector(root,nodes);
    int n=4;
    
   return convertBSTTOBBST(nodes,0,n-1);
}
int main(){
    
  
    struct node *root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5);
    
 printInorder(root);
 cout<<endl;
 struct node *rooot=ConvertBST_to_BalancedBST(root);
 printInorder(rooot);
    
    
    return 0;
}