#include <bits/stdc++.h> 
#include<stdio.h>
#include<stdlib.h>
using namespace std; 

struct node  
{  
    int data;  
   struct node* left;
   struct node* right;  
};

void printLevelOrder(struct noe *root){
    queue<int> que;
    
    que.push(root->data);
    
    while(que.empty()==false){
        int tmp=que.front();
        que.pop();
        cout<<tmp->data<<"->";
        que.push(tmp->left->data);
        que.push(tmp->right->data);
        
    }
}










node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return(Node);  
}  


int main()  
{  
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
  
    cout << "Level Order traversal of binary tree is \n";  
    printLevelOrder(root);  
  
    return 0;  
}  
 