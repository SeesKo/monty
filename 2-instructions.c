#include "monty.h"

/**
 * handle_more - Processes additional Monty bytecode instructions.
 *
 * @instruction: The instruction string.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction in the bytecode file.
 */
void handle_more(char *instruction, stack_t **stack,
		unsigned int line_number)
{
	char *opcode = strtok(instruction, " \t\n");

	if (opcode)
	{
		if (strcmp(opcode, "pchar") == 0)
			pchar(stack, line_number);
		else if (strcmp(opcode, "pstr") == 0)
			pstr(stack, line_number);
		else if (strcmp(opcode, "rotl") == 0)
			rotl(stack, line_number);
		else if (strcmp(opcode, "rotr") == 0)
			rotr(stack, line_number);
		else if (strcmp(opcode, "stack") == 0)
			op_stack(stack, line_number);
		else if (strcmp(opcode, "queue") == 0)
			op_queue(stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
