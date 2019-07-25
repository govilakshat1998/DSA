#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void insertAtBeg(Node** head, int x)
{
	Node* new = malloc(sizeof(Node));
	new->next = *head;
	new->data = x;
	*head = new;
}

void traverse(Node* head)
{
	if(head == NULL)
		return;
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void update(Node** head, int k, int len)
{
	if(k>len)
		return;
	Node* last = NULL;
	int pos = 0;

	Node* temp = *head;
	Node* prev = NULL;
	while(temp != NULL)
	{
		if((len-pos)%k == 0)
		{
			Node* del = temp;
			if(prev == NULL)
				*head = temp->next;
			else
				prev->next = temp->next;
			temp = temp->next;
			insertAtBeg(&last, del->data);
			free(del);
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
		pos++;
	}
	temp = last;
	if(temp != NULL)
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = *head;
	}
	*head = last;
}

int main()
{
	int k;
	scanf("%d", &k);
	int ip;
	int len = 0;
	Node* head = NULL;

	while(1)
	{
		scanf("%d", &ip);
		if(ip == -1)
			break;
		insertAtBeg(&head, ip);
		len++;
	}
	update(&head, k, len);
	traverse(head);
}
