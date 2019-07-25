#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void insertAtEnd(Node** head, int x)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data=x;
	if(*head == NULL)
	{
		tmp->next= NULL;
		*head=tmp;
	}
	else
	{
		Node *last = *head;
		while(last->next != NULL)
			last = last->next;
		tmp->next= NULL;
		last->next = tmp;
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
	Node* head = NULL;
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 20);
	insertAtEnd(&head, 30);
	insertAtEnd(&head, 40);
	insertAtEnd(&head, 50);
	Node *tmp = search(head, 2, 5);
	printf("%d\n", tmp->data);
	traverse(head);
	return 0;
}
