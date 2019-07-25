#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

void push(Node** head, int x) 
{ 
    Node *tmp = (Node *)malloc(sizeof(Node)); 
    tmp->data = x;  
    if (*head == NULL) 
    { 
        tmp->prev = NULL; 
        *head = tmp; 
        tmp->next = NULL;
    }
    else
    {  
    	Node *last = *head; 
    	while (last->next != NULL) 
        	last = last->next; 
        tmp->next = NULL;
	    last->next = tmp; 
	    tmp->prev = last; 
	}
}

Node *search(Node *head, int k,int l)
{
	int ct = 0;
	Node *tmp = head;
	while(tmp != NULL)
	{
		ct++;
		if(ct == l-k+1)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void traverse(Node *head)
{
	Node *tmp = head;
	while(tmp->next != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

int main()
{
	Node *head = NULL;
	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	Node *tmp = search(head, 2, 4);
	printf("%d", tmp->data);
	return 0;
}
