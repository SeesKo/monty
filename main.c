#include "monty.h"

/**
 * tokenize_line - Tokenizes a line of Monty bytecode
 * and executes the corresponding opcode.
 * @line: The line containing Monty bytecode instructions.
 * @stack: A pointer to the top of the stack.
 */
void tokenize_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *token = strtok(line, " \t\n");

	if (token)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n");

			if (token)
				push(stack, line_number, token);
			else
				fprintf(stderr, "Error: Missing argument for push\n");
		}
		else if (strcmp(token, "pall") == 0)
			pall(stack, line_number);
		else if (strcmp(token, "pint") == 0)
			pint(stack, line_number);
		else if (strcmp(token, "pop") == 0)
			pop(stack, line_number);
		else if (strcmp(token, "swap") == 0)
			swap(stack, line_number);
		else
			fprintf(stderr, "Error: Unknown opcode %s\n", token);
	}
}

/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;
	FILE *monty_file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		tokenize_line(line, &stack, line_number);
		line_number++;
	}

	fclose(monty_file);
	if (line)
		free(line);

	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}

	return (EXIT_SUCCESS);
}
