/* TODO:
 * 	* number processing can't handle trailing zeros (10, 20, 200)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


int flip_num(int number)
{
	int flipped = 0;
	int sig_figs = 0;
	int num = number;
	int digit = 0;

	/* get amount of significant digits */
	for (int i = number; i != 0; i = i/10)
	{
		sig_figs++;
	}

	/* flip */
	for (int s = sig_figs; s > 0; s--)
	{
		digit = num - ((num/10)*10);

		int magnitude = 1;
		for (int i = 1; i < s; i++)
		{
			magnitude = magnitude * 10;
		}

		flipped += digit * magnitude;

		num = num/10;
	}

	return flipped;
}


int main(int argc, char** argv)
{
	srand(time(NULL)); /* initiate random number generator once at very beginning */

	for(int a = 1; a < argc; a++)
	{
		if(argv[a] == NULL) exit(1); /* can't be empty for now */

		char *input = argv[a];
		int min = 1; /* 0 is not an acceptable roll */
		int dice = 1;
		int sides = 20;

		char current_char = argv[a][0];
		bool did_see_d = false;
		int magnitude = 1;
		int num = 0;

		for (int i = 1; current_char != '\0'; i++) /**/
		{
			if ((current_char - '0') <= 9)
			{
				num += (current_char-'0')*magnitude;
				magnitude = magnitude * 10;
			}
			else if (current_char == 'd')
			{
				if (did_see_d) /* can't have multiple 'd' in input */
				{
					printf("error\n");
				} else {
					did_see_d = true;
					if (num > 0)
					{
						dice = flip_num(num);
					} else {
						dice = 1;
					}
					num = 0;
				}
			} else { /* no negatives, floats, or random letters */
				printf("error (input)\n");
			}
			current_char = argv[a][i];
		}

		sides = flip_num(num);

		/* roll for each die */
		printf("%dd%d: %d", dice, sides, (rand() % sides) + min);
		for (int d = 1; d < dice; d++)
		{
			printf(", %d", (rand() % sides) + min);
		}
		printf("\n");
	}
}
