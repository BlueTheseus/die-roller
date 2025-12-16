#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define VERSION "0.3.0"


void help(char *program_name)
{
	fprintf(stdout, "usage: %s [SIDES]\n       %s [DICE]d[SIDES]\n", program_name, program_name);
	return;
}


int get_substring(char *string, int num_chars, char *substring)
{
	if (num_chars < 1) return 0;

	for (int i = 0; i <= num_chars; i++)
	{
		substring[i] = string[i];
	}
	substring[num_chars] = '\0';

	return 1;
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
					fprintf(stderr, "error: input too many 'd'\n");
				} else {
					saw_d = 1;
					if (num_char > 0)
					{
						char number[num_char+1];
						if (!get_substring(first_char, num_char, number))
							exit(1);

						dice = atoi(number);

						if (dice == 0) dice = 1;
					} else {
						dice = 1;
					}
					num_char = 0;
					first_char = &argv[a][i];
				}
			}
			else
			{ /* no negatives, floats, or random letters */
				fprintf(stderr, "error: input invalid character\n");
			}
			current_char = &argv[a][i];
		}

		char number[num_char+1];
		get_substring(first_char, num_char, number);
		sides = atoi(number);
		if (sides == 0)
		{
			fprintf(stderr, "error\n");
		}

		/* roll for each die */
		fprintf(stdout, "%dd%d:\t%d", dice, sides, (rand() % sides) + min);
		for (int d = 1; d < dice; d++)
		{
			fprintf(stdout, "\t%d", (rand() % sides) + min);
		}
		fprintf(stdout, "\n");
	}
}
