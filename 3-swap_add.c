#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "swap" instruction
 * in the bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}


/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "add" instruction
 * in the bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;

	/* Removing the top element */
	pop(stack, line_number);
}


/**
 * nop - Does not do anything.
 *
 * @stack: Pointer to the stack.
 * @line_number: Line number of the "nop" instruction
 * in the bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
