#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 

void printArray(int ints[], int len)  
{  
    int i;  
    for (i = 0; i < len; i++)  
    {  
        cout << ints[i] << " ";  
    }  
    cout<<endl;  
}
void PrintRootToLeafPath(struct node* root,int path[],int level) 
{ 
        if (root == NULL) 
        return; 
        
        path[level]=root->data;
        level++;
        
        if(root->left==NULL && root->right==NULL)
        printArray(path,level);
        else{
        PrintRootToLeafPath(root->left,path,level);
        PrintRootToLeafPath(root->right,path,level);
        }
}  
void RootToLeafPath(struct node *root){
    int path[20];
    
    PrintRootToLeafPath(root,path,1);
}
int main(){
 struct node *root = newNode(10); 
    root->left	 = newNode(20); 
    root->right	 = newNode(30); 
    root->left->left = newNode(40); 
    root->left->right = newNode(15);
    root->left->right->left = newNode(35); 
    root->left->right->right = newNode(66); 
	
	RootToLeafPath(root);
return 0;	
}