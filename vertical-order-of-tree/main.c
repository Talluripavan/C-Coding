#include<stdlib.h>
#include <stdio.h>
struct hnode {
    struct hnode *left;
    struct snode *next;
    int hd;
    struct hnode *right;
};
struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct snode{
    int data;
    struct snode *link;
};
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
struct snode* NEWNode(int data) 
{ 
    struct snode* node = (struct snode*)malloc(sizeof(struct snode)); 
    node->data = data; 
    node->link = NULL; 
    
  
    return node; 
} 
void printInorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
       
      printInorder(node->left);
      printf("%d ", node->data); 
      printInorder(node->right); 
} 
void findminmaxdistance(struct node *root,int hd,int *min,int *max){
    if(root==NULL)
    return;
    
    if(hd<*min)
    *min=hd;
    if(hd>*max)
    *max=hd;
    findminmaxdistance(root->left,hd-1,min,max);
    findminmaxdistance(root->left,hd+1,min,max);
    
}

void Newnode(struct hnode **hroot,int hd){
    struct hnode *ptr=*hroot;
    struct hnode *newnode=(struct hnode*)malloc(sizeof(struct hnode));
    newnode->left=NULL;
    newnode->next=NULL;
    newnode->right=NULL;
    newnode->hd=hd;
    
    
    
    while(ptr){
        ptr=ptr->right;
    }
    
    ptr->right=newnode;
    return ;
}
void Createhorizantallist(struct hnode **hroot,int min,int max){
    
    struct hnode *newnode=(struct hnode*)malloc(sizeof(struct hnode));
    newnode->left=NULL;
    newnode->next=NULL;
    newnode->right=NULL;
    newnode->hd=min;
    *hroot=newnode;
    
    struct hnode *ptr=*hroot;
    
    
    printf("min-max=%d:%d \n",min,max);
    for(int i=min+1;i<=max;i++){
        struct hnode *newnode=(struct hnode*)malloc(sizeof(struct hnode));
    newnode->left=NULL;
    newnode->next=NULL;
    newnode->right=NULL;
    newnode->hd=i;
    ptr->right=newnode;
    ptr=newnode;
      
    }
    return;
}
void AddnodeToHnodes(struct hnode **hroot,int data,int hd){
    printf("im from AddnodeToHnodes\n");
    struct hnode *hptr=*hroot;
    
    struct snode *tmp=NEWNode(data);
    while(hptr!=NULL)
    {
        printf("Hptr-daata %d\n",hptr->hd);
        if(hptr->hd==hd)
        {
            struct snode *sptr=hptr->next;
            while(sptr){
                sptr=sptr->link;
            }
            sptr->link=tmp;
            
            return;
        }
        else
        hptr=hptr->right;
    }
    
    
    return;
}
void VerticalOrderoftree(struct hnode *hroot,struct node *root,int hd){
    
    if(root==NULL)
    return;
    printf("im from VerticalOrderoftree-%d-%d \n",root->data,hd);
    AddnodeToHnodes(&hroot,root->data,hd);
    VerticalOrderoftree(hroot,root->left,hd-1);
    VerticalOrderoftree(hroot,root->right,hd+1);
    
}
void printList(struct hnode *hroot) 
{     printf("im from printList\n");
  struct hnode *hptr=hroot;
    
    while(hptr)
    {
        printf("%d=",hptr->hd);
        struct snode *sptr=hptr->next;
            while(sptr)
            {   printf("%d->",sptr->data);
                sptr=sptr->link;
            }
            printf("\n");
    
    
        hptr=hptr->right;    
    }
    
    
    return;
} 

int main()
{
    int min=100,max=0,hd=0;
    
 struct node *root = newNode(10); 
root->left	 = newNode(20); 
root->right	 = newNode(30); 
root->left->left = newNode(40); 
root->left->right = newNode(15);
root->left->right->left = newNode(35); 
root->left->right->right = newNode(66); 

findminmaxdistance(root,hd,&min,&max);

struct hnode *hroot=NULL;
Createhorizantallist(&hroot,min,max);
VerticalOrderoftree(hroot,root,0);
printList(hroot);


    
    return 0;
}





