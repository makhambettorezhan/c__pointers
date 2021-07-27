#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char name[] = "Harry Potter";

	char* ptr = name;
	*(ptr+3) = 'X';
	printf("%c\n", *(ptr+6));
	printf("%s\n", name);
	return 0;
}