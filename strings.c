#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * followed by a new line.
 * @head: head pointer.
 * @line_number: the line readed.
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("\n");
	}
	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->n == 0)
			break;
		if (!(tmp->n >= 0 && tmp->n <= 127))
			break;
		if (tmp->n > 0 && tmp->n < 127)
		{
			printf("%c", tmp->n);
		}
		tmp = tmp->next;
	}
	printf("\n");
}
