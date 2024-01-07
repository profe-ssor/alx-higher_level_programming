#include <stdio.h>
#include <stdlib.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 *
 * Return: 1 if it's a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return (1);
	listint_t *slow = *head, *fast = *head, *prev_slow = *head, *second_half = NULL;
	/* Move fast and slow pointers to find the middle of the list */
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	/* For odd number of elements, skip the middle element */
	if (fast != NULL)
		slow = slow->next;

	/* Reverse the second half of the list */
	second_half = reverse_list(slow);

	/* Compare the first and reversed second half of the list */
	if (!compare_lists(*head, second_half))
	{
		/* Restore the original order of the second half before returning */
		prev_slow->next = reverse_list(second_half);
		return (0); /* Not a palindrome */
	}

	/* Restore the original order of the second half */
	prev_slow->next = reverse_list(second_half);

	return (1); /* Palindrome */
}

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the linked list
 *
 * Return: pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

/**
 * compare_lists - compares two linked lists
 * @list1: pointer to the first linked list
 * @list2: pointer to the second linked list
 *
 * Return: 1 if the lists are equal, 0 otherwise
 */
int compare_lists(listint_t *list1, listint_t *list2)
{
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->data != list2->data)
			return (0); /* Not a palindrome */
		list1 = list1->next;
		list2 = list2->next;
	}

	return (1); /* Palindrome */
}

/**
 * main - example usage of is_palindrome function
 * Return: always 0
 */
int main(void)
{
	/* Create a palindrome list: 1 -> 2 -> 3 -> 3 -> 2 -> 1 */
	listint_t *head = malloc(sizeof(listint_t));

	head->data = 1;

	head->next = malloc(sizeof(listint_t));
	head->next->data = 2;

	head->next->next = malloc(sizeof(listint_t));
	head->next->next->data = 3;

	head->next->next->next = malloc(sizeof(listint_t));

	head->next->next->next->data = 3;

	head->next->next->next->next = malloc(sizeof(listint_t));
	head->next->next->next->next->data = 2;

	head->next->next->next->next->next = malloc(sizeof(listint_t));
	head->next->next->next->next->next->data = 1;

	head->next->next->next->next->next->next = NULL;

	int result = is_palindrome(&head);

	if (result)
	{
		printf("The linked list is a palindrome.\n");
	}
	else
	{
		printf("The linked list is not a palindrome.\n");
	}

	/* Free allocated memory */
	listint_t *current = head;

	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	return (0);
}
