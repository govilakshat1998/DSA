#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void add(Node **head, int x) 
{	
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = x;
	if(*head == NULL)
	{
		*head = tmp;
		tmp->next = tmp;
	}
	else
	{
		Node *last = *head;	
		while(last->next != *head)
			last = last->next;
		last->next = tmp;
		tmp->next = *head;
    }
} 

Node *search(Node *head, int k,int l)
{
	int ct = 0;
	Node *tmp = head;
	while(tmp->next != head)
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
	Node* tmp = head;
	while(tmp->next != head)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);
}

int main()
{
	Node* head = NULL;
	add(&head,10);
	add(&head,20);
	add(&head,30);
	add(&head,40);
	traverse(head);
	Node *tmp = search(head, 2, 4);
	printf("%d\n", tmp->data);
	return 0;
}