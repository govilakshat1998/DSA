#include<stdio.h>
#include<stdlib.h>

struct snode
{
	int data;
	struct snode *next;
};

struct dnode
{
	int data;
	struct dnode *prev;
	struct dnode *next;
};

void cir()
{
	printf("cir");
	struct snode *head;
	head = (struct snode*)malloc(sizeof(struct snode));

	int n;
	scanf("%d",&n);

	int num;
	scanf("%d",&num);
	head->data = num;
	head->next = head;

	struct snode *tmp,*fn;
	tmp = head;

	for(int i=2;i<=n;++i)
	{
		fn = (struct snode*)malloc(sizeof(struct snode));
		scanf("%d",&num);
		fn->data = num;
		tmp->next = fn;
		fn->next = head;
		tmp = tmp->next;
	}

	int k;
	scanf("%d",&k);
	tmp = head;

	for(int i=1;i<n-k+1;++i)
	{
		tmp = tmp->next;
	}

	printf("%d\n",tmp->data);
}

void doub()
{
	printf("doub");
	struct dnode *head;
	head = (struct dnode*)malloc(sizeof(struct dnode));

	int n;
	scanf("%d",&n);

	struct dnode* tmp, *fn;

	int num;
	scanf("%d",&num);
	head->data = num;
	head->prev = NULL;
	head->next = NULL;
	tmp = head;

	for(int i=2;i<=n;++i)
	{
		fn = (struct dnode*)malloc(sizeof(struct dnode));
		scanf("%d",&num);

		fn->data = num;
		fn->prev = tmp;
		fn->next = NULL;
		tmp->next = fn;
		tmp = tmp->next;
	}

	int k;
	scanf("%d",&k);
	tmp = head;

	for(int i=0;i<n-k;++i)
	{
		tmp = tmp->next;
	}

	printf("%d\n",tmp->data);
}

void single()
{
	printf("single");
	struct snode *head;

	int n;
	scanf("%d",&n);

	head = (struct snode*)malloc(sizeof(struct snode));
	int num;
	scanf("%d",&num);
	head->data = num;
	head->next = NULL;
	struct snode *tmp,*fn;
	tmp = head;

	for(int i=2;i<=n;++i)
	{
		fn = (struct snode*)malloc(sizeof(struct snode));

		scanf("%d",&num);
		fn->data = num;
		fn->next = NULL;
		tmp->next = fn;
		tmp = tmp->next;
	}

	int k;
	scanf("%d",&k);
	tmp = head;

	for(int i=1;i<=n-k;++i)
	{
		tmp = tmp->next;
	}

	printf("%d\n",tmp->data);
}

int main()
{
	int n;
	scanf("%d",&n);

	if(n == 0)
		single();
	else if(n == 1)
		doub();
	else if(n == 2)
		cir();

	return 0;
}