#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

void push(Node** head_ref, Node** tail, int x, int pos) 
{
    int ct = 0;
    Node *temp = *head_ref;
    Node* node = NULL;
    while(temp != NULL)
    {
        ct++;
        if(ct == pos)
        {
            node = temp;
            break;
        }
        temp = temp->next;
    }
    Node *tmp = (Node *)malloc(sizeof(struct Node)); 
    Node *last = *head_ref; 
    tmp->data = x; 
    tmp->next = NULL; 
    if (*head_ref == NULL) 
    { 
        tmp->prev = NULL; 
        *head_ref = tmp;
        *tail = tmp; 
    }
    else
    {  
    	while (last->next != NULL) 
        	last = last->next; 
	    last->next = tmp; 
	    tmp->prev = node; 
	   *tail = tmp;
    }
}

void checkLoop(Node *head_ref)
{
    Node* tmp = head_ref;
    Node *previous = NULL;
    int ct = 0;
    while(tmp->next != NULL)
    {
        if(tmp->prev != previous)
        {
            Node *temp = tmp->prev;
            while(temp != tmp)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("%d %d\n", temp->data, (temp->prev)->data);
        }
        previous = tmp;
        tmp = tmp->next;        
    }
}

void colour(Node *head_ref)
{
    int c[100];
    Node *tmp = head_ref->next->next;
    Node *parent = head_ref->next;
    Node *grandparent = tmp->prev;
    int ct = 2;
    c[0] = 0;                                     
    c[1] = 1;
    int val;
    while(tmp->next != NULL)
    {
        if(grandparent == parent)
            c[ct] = c[ct-2];
        else
        {
            val = (c[ct-1]+1)%3;
            if(val!=c[ct-2])
                c[ct] = val;
            else
                c[ct] = (val+1)%3;
        }
        parent = parent->next;
        tmp = tmp->next;
        grandparent = tmp->prev;
        ct++;
    }
    if(grandparent == parent)
            c[ct] = c[ct-2];
        else
        {
            val = (c[ct-1]+1)%3;
            if(val!=c[ct-2])
                c[ct] = val;
            else
                c[ct] = (val+1)%3;
        }
        
    for(int i=0;i<=ct;i++)
        printf("%d ",c[i]);
}

void traverse(Node* last)
{
    Node* tmp = last;
    while(tmp->prev!=NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    } 
    printf("%d\n", tmp->data);
        
}

void traverse1(Node *head_ref)
{
    Node *tmp = head_ref;
    while(tmp->next != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d\n" ,tmp->data);
}

int main()
{                                                                   
    Node *head = NULL;
    Node *tail = NULL;
    push(&head, &tail, 1, 0);
    push(&head, &tail, 2, 1);
    push(&head, &tail, 3, 1);
    push(&head, &tail, 4, 2);
    push(&head, &tail, 5, 3);
    // traverse(tail);
    // traverse1(head);
    // checkLoop(head);
    colour(head);
    return 0;
}