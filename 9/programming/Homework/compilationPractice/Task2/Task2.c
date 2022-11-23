#include <stdio.h>
int main()
{
	int x = 12, y = 18;
	// the least common multiple is atleast the same as the bigger number so we start from there
	int biggest = (x > y) ? x : y;

	// we inciment it until we find a LCM
	while (1)
	{
		if (biggest % x == 0 && biggest % y == 0)
		{
			printf("The LCM for %d and %d is %d.", x, y, biggest);
			break;
		}
		biggest++;
	}

	return 0;
}