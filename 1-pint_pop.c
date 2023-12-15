#include "monty.h"

/**
 * pint - Prints value at the top of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "pint" instruction
 * in the bytecode file.
 */
void pint(stack_t *stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack->n);
}

/**
 * pop - Removes the top element of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "pop" instruction
 * in the bytecode file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = temp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}
