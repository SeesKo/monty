#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty file
 * @args: argument passed to the 'push' opcode
 */
void push(stack_t **stack, int line_number, char *args)
{
	stack_t *new_node;
	int value;

	/* Check if there is an argument after push */
	if (!args || (!isdigit(args[0]) && args[0] != '-' && args[0] != '+'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer */
	value = atoi(args);

	/* Create a new node for the stack */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer and assign to the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/* Print all values on the stack */
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
