/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) 
{
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 && !head2)
	{
		return head1;
	}
	else if (head2 && !head1)
	{
		return head2;
	}
	else
	{
		struct node *temp1 = head1;
		struct node *temp2 = head2;
		struct node *head;
		if (temp2->num < temp1->num)
		{
			head = temp2;
			temp2 = temp2->next;
		}
		else
		{
			head = temp1;
			temp1 = temp1->next;
		}
		struct node *current = head;
		while (temp1 && temp2)
		{
			if (temp2->num < temp1->num)
			{
				current->next = temp2;
				temp2 = temp2->next;
				current = current->next;
			}
			else
			{
				current->next = temp1;
				temp1 = temp1->next;
				current = current->next;
			}
		}
		while (temp1)
		{
			current->next = temp1;
			temp1 = temp1->next;
			current = current->next;
		}
		while (temp2)
		{
			current->next = temp2;
			temp2 = temp2->next;
			current = current->next;
		}
		current->next = NULL;
		return head;
	}
}
