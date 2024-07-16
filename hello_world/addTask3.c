#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *num;

	num = (int*)malloc(sizeof(int) * 2);

	num[0] = 1;
	num[1] = 2;
	printf("%d + %d = %d\n",num[0], num[1], num[0] + num[1]);
	return 0;
}
