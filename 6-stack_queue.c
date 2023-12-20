#include "monty.h"

/**
 * op_stack - Sets the mode to STACK.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file
 * where the instruction appears.
 */
void op_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Setting the mode to STACK */
	mode = STACK;
}

/**
 * op_queue - Sets the mode to QUEUE.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file
 * where the instruction appears.
 */
void op_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Setting the mode to QUEUE */
	mode = QUEUE;
}
