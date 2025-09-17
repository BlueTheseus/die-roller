#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	srand(time(NULL)); /* initiate random number generator once at very beginning */

	for(int a = 1; a < argc; a++)
	{
		if(argv[a] == NULL) exit(1);

		int min = 1; /* 0 is not an acceptable roll */
		
		/* extract number of die and number of sides */
		int sides = atoi(argv[a]);
		printf("d%s: ", argv[a]);

		/* roll for each die */
		int roll = (rand() % sides) + min;
		printf("%d\t", roll);
	}
		printf("\n");
}
