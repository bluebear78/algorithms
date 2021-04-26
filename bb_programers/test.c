#include <stdio.h>
int main()
{
	int i = 1;
	int j = 1;
	

	while (i < 10)
	{
		int k = 1;
		while (k <= i)
		{
			printf("%d", k);
			j++;
			k++;
		}
		printf("\n");
		i = i + 2;
	}
	return 0;
}