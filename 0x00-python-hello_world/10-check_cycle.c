#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - A function to check if a linked list has a cycle
 * @list : A singly linked list
 *
 * Return : 0  if there is no cycle  OR 1  if there is  cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;

	while (slow!= NULL && fast!= NULL && fast->!next = NULL)
	{
		if(slow == fast)
		{
			return (1);
		}
		slow = slow->next;
		fast = fast->next->next;
	
	}
	return (0);
}
