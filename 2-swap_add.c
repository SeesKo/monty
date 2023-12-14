#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
