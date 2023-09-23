#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @head: head pointer.
 * @line_number: line readed
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next->n += temp->n;
	free(temp);
}
/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @head: head pointer.
 * @line_number: line readed.
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next->n -= temp->n;
	free(temp);
}
/**
 * divd - divides the second top element of
 * the stack by the top element of the stack.
 * @head: head pointer.
 * @line_number: line readed.
 */
void divd(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*(head) = (*head)->next;
	if (tmp->n != 0)
	{
		tmp->next->n /= tmp->n;
	}
	else
	{
		fprintf(stderr, "division by zero\n");
		exit(EXIT_FAILURE);
	}
	free(tmp);
}
