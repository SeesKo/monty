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

	if (instruction[0] == '#')
		return;

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
		else if (strcmp(opcode, "sub") == 0)
			sub(stack, line_number);
		else if (strcmp(opcode, "div") == 0)
			_div(stack, line_number);
		else if (strcmp(opcode, "mul") == 0)
			mul(stack, line_number);
		else if (strcmp(opcode, "mod") == 0)
			mod(stack, line_number);
		else if (strcmp(opcode, "nop") == 0)
			nop(stack, line_number);
		else
			handle_more(instruction, stack, line_number);
	}
}
