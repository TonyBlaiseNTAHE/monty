#include "monty.h"
#include <stdlib.h>

/**
 * get_op - finds the opcode that matches with the command.
 * @cmd: the command
 * @head: head pointer
 * @line_number: number of lines read/executed.
 */
void get_op(char *cmd, stack_t **head, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nope", nope},
		{"add", add},
		{"sub", sub},
		{"divd", divd},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, cmd) == 0)
		{
			opcodes[i].f(head, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}
/**
 * freedlist - frees a list.
 * @head: head pointer.
 */
void freedlist(stack_t *head)
{
	stack_t *current =  NULL, *next = NULL;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
/**
 * pop - removes the top element of the stack.
 * @head: head pointer.
 * @line_number: line readed
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*head = (*head)->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(temp);
}
/**
 * swap - swaps the top two elements of the stack.
 * @head: head pointer.
 * @line_number: the line need.
 */
void swap(stack_t **head, unsigned int line_number)
{
	int data;
	stack_t *temp = *head;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = temp->next->n;
	temp->next->n = temp->n;
	temp->n = data;
}
/**
 * nop - doesn't do anything.
 * @head: head pointer.
 * @line_number: line readed.
 */
void nope(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
