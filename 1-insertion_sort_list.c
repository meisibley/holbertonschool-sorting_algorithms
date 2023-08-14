#include "sort.h"

/**
 * insertion_sort_list - insertion sort a doubly linked list
 * @list: the doubly linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *pnode = NULL, *node = NULL, *nnode = NULL;

	if (list == NULL)
		return;
	head = *list, node = head;
	while (node) /*loop forward(go right)*/
	{
		pnode = node->prev;
		while (pnode && pnode->n > node->n) /*loop back(go left)*/
		{
			nnode = node->next;
			if (pnode->prev)
				pnode->prev->next = node;
			node->prev = pnode->prev;
			pnode->next = nnode;
			pnode->prev = node;
			if (nnode)
				nnode->prev = pnode;
			node->next = pnode;

			pnode = node->prev;
			if (head->prev)
			head = head->prev;
			print_list(head);
		}
		node = node->next;
	}
	*list = head;
}
