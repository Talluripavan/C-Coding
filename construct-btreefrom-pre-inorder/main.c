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
int Searchelement(char in[],int start,int end,int value){
    
    for(int i=start;i<end;i++){
        if(in[i]==value)
            return i;
        
    }
}
struct node *Builttree(char in[],char pre[],int start,int end)
{
    static int preindex=0;
    
    if(start>end)
        return NULL;
    
    struct node *tmp=newNode(pre[preindex++]);
    if(start==end)
        return tmp;
    int inindex=Searchelement(in,start,end,tmp->data);   
    
    tmp->left=Builttree(in,pre,start,preindex-1);
    tmp->left=Builttree(in,pre,preindex+1,end);
    
    return tmp;
    
}
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
      printInorder(node->left); 
      printf("%c ", node->data); 
      printInorder(node->right); 
} 

int main()
{
    char in[]={'a','b','c','d','e','f'};
    char pre[]={'c','e','a','d','f','b'};
    int n=sizeof(in)/sizeof(in[0]);
    printf("%d \n",n);
    struct node *root=Builttree(in,pre,0,n);
    
    printInorder(root);
    return 0;
}
