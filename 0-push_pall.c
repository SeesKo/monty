#include "monty.h"

/**
 * is_number - Checks if a string represents a valid integer.
 * @str: The input string to be checked.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int is_number(const char *str)
{
	if (!str)
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-' && *str != '+')
			return (0);
		str++;
	}

	return (1);
}

/**
 * push - Pushes an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "push" instruction in the bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all the integers in the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "pall" instruction in the bytecode file.
 */
void pall(stack_t *stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack)
		return;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
