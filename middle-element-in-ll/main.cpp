#include<stdlib.h>
#include <stdio.h>
struct node
{
  int data;
  struct node *next;
};
void
Newnode (struct node **head, int data)
{
  struct node *nnode = (struct node *) malloc (sizeof (struct node));
  nnode->data = data;
  nnode->next = *head;
  *head = nnode;

}

void
printLl (struct node *h)
{
  struct node *head = h;
  while (head)
    {
      printf ("%d ->", head->data);
      head = head->next;
    }
}

void
Middleofnode (struct node *head)
{
  struct node *fhead = head;

  if (head != NULL)
    {
      while (fhead != NULL && fhead->next != NULL)
	{
	  head = head->next;
	  fhead = fhead->next->next;
	}
      printf ("MIDDLE ELE:%d \n", head->data);
    }
}

void
LOPPISTHERENOT (struct node *head)
{
  struct node *fhead = head;


  while (fhead && head && fhead->next)
    {
      if (fhead == head)
	{
	  printf (" loop \n");
	  return;
	}
      head = head->next;
      fhead = fhead->next->next;
    }

}

int
main ()
{
  printf ("Hello World\n");
  struct node *head = NULL;
  Newnode (&head, 10);
  Newnode (&head, 20);
  Newnode (&head, 30);
  Newnode (&head, 40);
  Newnode (&head, 50);
  printLl (head);
  printf ("\n");
  Middleofnode (head);
  printf ("\n");
  LOPPISTHERENOT (head);
  return 0;
}
