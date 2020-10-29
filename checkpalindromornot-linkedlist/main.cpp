#include<bits/stdc++.h> 
#include<stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
  int data;
  struct node *next;
};

void Newnode (struct node **head, int data)
{
  struct node *nnode = (struct node *) malloc (sizeof (struct node));
  nnode->data = data;
  nnode->next = *head;
  *head = nnode;

}

int Palindromeornot(struct node *h){
    if(h==NULL)
        return 0;
    stack<int> st;
    
     struct node *head = h;
  while (head)
    {
        st.push(head->data);
        head = head->next;
    }
        
  while (h)
    {
        int val=st.top();
                st.pop();
        if(val!=h->data)
            return 0;
            
        h = h->next;
    }
    
    return 1;
}

void printLl (struct node *h)
{
  struct node *head = h;
  while (head)
    {
      printf ("%d ->", head->data);
      head = head->next;
    }
}


int main ()
{
  printf ("Hello World\n");
  struct node *head = NULL;
  Newnode (&head, 10);
  Newnode (&head, 20);
  Newnode (&head, 30);
  Newnode (&head, 20);
  Newnode (&head, 10);
  
  printLl(head);
  printf ("\n");
  
  if(Palindromeornot(head))
    cout<<"NOT PALINDROM"<<endl;
  else
    cout<<" PALINDROM"<<endl;
    
  
  return 0;
}


