#include "monty.h"

/**
 * handle_instruction - Processes Monty bytecode instructions.
 *
 * @instruction: The instruction string.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction in the bytecode file.
 */
void handle_instruction(char *instruction, stack_t **stack,
		unsigned int line_number)
{
	char *opcode;

	if (!instruction || !stack)
	{
		fprintf(stderr, "Error: Null pointer detected\n");
		exit(EXIT_FAILURE);
	}

	opcode = strtok(instruction, " \t\n");

	if (opcode)
	{
		if (strcmp(opcode, "push") == 0)
			push(stack, line_number);
		else if (strcmp(opcode, "pall") == 0)
			pall(*stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(*stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(stack, line_number);
		else if (strcmp(opcode, "swap") == 0)
			swap(stack, line_number);
		else if (strcmp(opcode, "add") == 0)
			add(stack, line_number);
		else if (strcmp(opcode, "nop") == 0)
			nop(stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
