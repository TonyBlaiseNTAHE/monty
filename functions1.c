#include "monty.h"

/**
 * is_number - checks if the argument is a number or not.
 * @s: the argument to check
 * Return: 1 if it is a number or digit otherwise 0.
 */
int is_number(char *s)
{
	if (*s == '-')
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
/**
 * push - insert item in the stack
 * @head: head pointer.
 * @line_number: the line number read.
 */
void push(stack_t **head,  unsigned int line_number)
{
	int n;
	char *token;
	stack_t *temp = *head;
	stack_t *new_node;

	if (head == NULL)
	{
		fprintf(stderr, "Stack is not present\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \n\r\t");
	if (token == NULL || is_number(token) == 0)
	{
		fprintf(stderr, "L%d:usage:push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		temp->prev = new_node;
	*head = new_node;
}
/**
 * pall - prints all elements present in the stack
 * @head: pointer to the head node pointer
 * @line_number: line number read
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints the value at the top of a stck,
 * followed by a new line.
 * @head: head pointer.
 * @line_number: line number readed
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if ((*head) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
