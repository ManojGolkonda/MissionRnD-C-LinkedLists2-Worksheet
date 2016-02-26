/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	if (K < 1 || head == NULL)
		return NULL;
	struct node *current = head;
	int count = K - 1;
	while (current != NULL)
	{
		if (count--)
		{
			current = current->next;
		}
		else if (current->next!=NULL)
		{
			count = K - 1;
			struct node *temp = current->next;
			struct node *newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = K;
			newnode->next = temp;
			current->next = newnode;
			current = temp;
		}
		else
		{
			current->next = (struct node *)malloc(sizeof(struct node));
			current->next->num = K;
			current->next->next = NULL;
			return head;
		}
	}
	return head;
}
