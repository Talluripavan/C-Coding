#include<iostream>
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

void SPirralOrderOftree(struct node *root){
	
	if(root==NULL)
	return;
	stack<struct node*> s1;
	stack<struct node*> s2;
	
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		
		while(!s1.empty()){
				struct node *tmp=s1.top();
				s1.pop();
				printf("%d ",tmp->data);
				if(tmp->left)
					s2.push(tmp->left);
				if(tmp->left)
					s2.push(tmp->right);	
		}
		while(!s2.empty()){
				struct node *tmp1=s2.top();
				s2.pop();
				printf("%d ",tmp1->data);
				
				if(tmp1->left)
					s1.push(tmp1->right);
				if(tmp1->left)
					s1.push(tmp1->left);
		}
	
}
}
void printPreorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    printPreorder(node->left);
    printPreorder(node->right); 
}  

int main(){
 struct node *root = newNode(10); 
    root->left	 = newNode(20); 
    root->right	 = newNode(30); 
    root->left->left = newNode(40); 
    root->left->right = newNode(15);
    root->left->right->left = newNode(35); 
    root->left->right->right = newNode(66); 
	
	printPreorder(root);
	cout<<endl;
	SPirralOrderOftree(root);
	return 0;
}

