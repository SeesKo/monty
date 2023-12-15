#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where the instruction
 * appears.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;

	/* Removing the top element */
	pop(stack, line_number);
}

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where the instruction
 * appears.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;

	/* Removing the top element */
	pop(stack, line_number);
}

/**
 * mul - Multiplies the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where the instruction
 * appears.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;

	/* Removing the top element */
	pop(stack, line_number);
}

/**
 * mod - Computes the remainder of the division of the second top element
 * of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where the instruction
 * appears.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;

	/* Removing the top element */
	pop(stack, line_number);
}
