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
		char current_char[2] = { argv[a][0], '\0' };
		int num_char = 0;
		int processed_amount_of_die = 0;

		for (int i = 1; *current_char != '\0'; i++)
		{
			if ( (*current_char - '0') <= 9 ) // Character is a digit
			{
				num_char++;
			}
			else if (*current_char == 'd') // Character is a 'd'
			{
				if (processed_amount_of_die)
				{
					fprintf(stderr, "error: input too many 'd'\n");
					break;
				} else {
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

					// Check all subsequent characters
					for (int j = i; argv[a][j] != '\0'; j++)
					{
						if ( (argv[a][j] - '0') <= 9 ) // Next character is a digit
						{
							first_char = &argv[a][j];
							i = j;
							break;
						}
						else if (argv[a][j] == 'd') // Next character is another 'd'
						{
							continue;
						}
						else // Next character is invalid
						{
							fprintf(stderr, "error: invalid character '%s'\n", &argv[a][j]);
						}
					}
					processed_amount_of_die = 1;
				}
			}
			else // Character is invalid
			{ /* no negatives, floats, or random letters */
				fprintf(stderr, "error: input invalid character '%s'\n", current_char);
			}
			current_char[0] = argv[a][i];
		}

		if (*first_char == '\0')
		{
			fprintf(stderr, "error: didn't provide amount of sides\n");
		}
		else
		{
			char number[num_char+1];
			get_substring(first_char, num_char, number);
			sides = atoi(number);
		}

		if (sides == 0)
		{
			fprintf(stderr, "error: number of sides cannot be zero\n");
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
