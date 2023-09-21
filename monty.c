#include "monty.h"
/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0.
*/
int main(int argc, char **argv)
{
	FILE *file;
	char buffer[M];
	char *token;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file))
	{
		token = strtok(buffer, " \n\t\r");
		if (token == NULL)
		{
			line_number++;
			continue;
		}
		get_op(token, &stack, line_number);
		line_number++;
	}
	freedlist(stack);
	fclose(file);
	return (0);
}
