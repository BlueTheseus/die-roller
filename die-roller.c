/* TODO:
 * - proper error handling
 * - help & version flags
 * - flag to print labels (DICEdSIDES: ...)
 * - flag to print rolls in an orderly table
 * - accept from stdin
 * - print to stdout
 * - print error to stderr
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define VERSION "0.2.2"


void help(char *program_name)
{
	printf("usage: %s [SIDES]\n       %s [DICE]d[SIDES]\n", program_name, program_name);
	return;
}

int get_substring(char *string, int num_chars, char *substring)
{
	if (num_chars < 1) return -1;

	for (int i = 0; i <= num_chars; i++)
	{
		substring[i] = string[i];
	}
	substring[num_chars] = '\0';

	return 0;
}


int main(int argc, char** argv)
{
	if (argc == 1)
	{
		help(argv[0]);
		exit(0);
	}

	srand(time(NULL)); // initiate random number generator once at very beginning

	for(int a = 1; a < argc; a++)
	{
		if(argv[a] == NULL)
		{
			help(argv[0]);
			exit(1);
		}

		int min = 1; // 0 is not an acceptable roll
		int dice = 1;
		int sides = 20;

		char *first_char = &argv[a][0];
		char *current_char = first_char;
		int num_char = 0;
		int saw_d = 0;

		for (int i = 1; *current_char != '\0'; i++)
		{
			if ((*current_char - '0') <= 9)
			{
				num_char++;
			}
			else if (*current_char == 'd')
			{
				if (saw_d)
				{
					printf("error: input too many 'd'\n");
				} else {
					saw_d = 1;
					if (num_char > 0)
					{
						char number[num_char+1];
						if (get_substring(first_char, num_char, number) == -1)
							exit(1);

						dice = atoi(number);
					} else {
						dice = 1;
					}
					num_char = 0;
					first_char = &argv[a][i];
				}
			}
			else
			{ /* no negatives, floats, or random letters */
				printf("error: input invalid character\n");
			}
			current_char = &argv[a][i];
		}

		char number[num_char+1];
		get_substring(first_char, num_char, number);
		sides = atoi(number);

		/* roll for each die */
		printf("%dd%d:\t%d", dice, sides, (rand() % sides) + min);
		for (int d = 1; d < dice; d++)
		{
			printf("\t%d", (rand() % sides) + min);
		}
		printf("\n");
	}
}
