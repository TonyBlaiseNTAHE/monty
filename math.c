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

	if (*head == NULL || (*head)->next == NULL)
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

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*(head) = (*head)->next;
	if (tmp->n == 0)
	{
		fprintf(stderr, "division by zero\n");
		exit(EXIT_FAILURE);
	}
	(*head)->n /= tmp->n;
	free(tmp);
}
/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * @head: head pointer.
 * @line_number: line readed.
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack to short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	(*head)->n *= temp->n;
	free(temp);
}
/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: head pointer.
 * @line_number: line readed.
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d:can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	if (temp->n != 0)
		(*head)->n %= temp->n;
	else
	{
		fprintf(stderr, "L%d:division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	free(temp);
}
