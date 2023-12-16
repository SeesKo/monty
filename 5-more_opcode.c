#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where
 * the instruction appears.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * pstr - Prints the string starting from the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where the
 * instruction appears.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file where the
 * instruction appears.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	/* Check if stack has at least 2 elements */
	if (*stack && (*stack)->next)
	{
		stack_t *last = *stack;

		while (last->next)
			last = last->next;

		last->next = *stack;
		(*stack)->prev = last;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next->next = NULL;
	}
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file
 * where the instruction appears.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	/* Checking if stack has at least 2 elements */
	if (*stack && (*stack)->next)
	{
		stack_t *last = *stack;
		stack_t *second_last = NULL;

		while (last->next)
		{
			second_last = last;
			last = last->next;
		}

		second_last->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
