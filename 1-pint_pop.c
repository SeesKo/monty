#include "monty.h"

/**
 * pint - Prints value at the top of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number where the pint opcode appears.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
