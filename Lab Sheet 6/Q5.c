#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

void insert(Node** head, int x)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = x;
	tmp->next = NULL;
	if(*head==NULL)
		*head = tmp;
	else
	{
		Node* last = *head;
		while(last->next!=NULL) 
			last = last->next;
		last->next = tmp;
	}
}

void print(Node* head)
{
	Node* tmp = head;
	while(tmp!=NULL) 
	{
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}

void merge(Node* head1, Node* head2, Node** mergehead)
{
	Node* tmp1 = head1;
	Node* tmp2 = head2;
	if(tmp1->data <= tmp2->data) 
	{
		*mergehead = tmp1;
		tmp1 = tmp1->next; 
	}
	else
	{
		*mergehead = tmp2;
		tmp2 = tmp2->next;
	}

	Node* tmp3 = *mergehead;
	while(tmp1!=NULL && tmp2!=NULL)
	{		
		if(tmp1->data <= tmp2->data)
		{
			tmp3->next  = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			tmp3->next = tmp2;
			tmp2 = tmp2->next;
		}
		tmp3 = tmp3->next;
	}
	
	while(tmp1!=NULL) 
	{
		tmp3->next = tmp1;
		tmp1 = tmp1->next;
		tmp3 = tmp3->next;
	}
	while(tmp2!=NULL) 
	{
		tmp3->next = tmp2;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
	}
}

int main()
{
	int n,m;
	scanf("%d",&n);
	Node* head1 = NULL;
	Node* head2 = NULL;
	int a;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(&head1,a);
	}

	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a);
		insert(&head2,a);
	}

	Node* mergehead = NULL;
	merge(head1,head2,&mergehead);
	print(mergehead);
}