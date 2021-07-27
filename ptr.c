#include <stdio.h>
#include <stdlib.h> 

#define N 5

int main(int argc, char const *argv[])
{
	int *num = (int*) malloc(sizeof(int) * N);
	//int num[N];
	printf("Enter numbers:");
	int i;
	int sum = 0;
	for(i = 0; i < N; i++) {
		scanf("%d", num+i);

		sum += *(num+i);
	}

	printf("Sum = %d\n", sum);

	for(i = 0; i < N; i++) {
		printf("%p = %d\n", num+i, *(num+i));
	}


	return 0;
}