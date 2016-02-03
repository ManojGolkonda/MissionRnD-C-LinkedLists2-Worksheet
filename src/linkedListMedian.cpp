/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head == NULL)
		return -1;
	struct node *slow_ptr1 = head;
	struct node *slow_ptr2 = head;
	struct node *fast_ptr = head;

	if (head != NULL)
	{
		while (fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr1 = slow_ptr2;
			slow_ptr2 = slow_ptr2->next;
		}
	//	printf("The middle element is [%d]\n\n", slow_ptr->num);
		if (fast_ptr == NULL)
			return (slow_ptr1->num + slow_ptr2->num) / 2;
		else
			return slow_ptr2->num;
	}
}
