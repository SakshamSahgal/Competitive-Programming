#include <stdio.h>
int main()
{
	int Var = 10;
	int *ptr = &Var;
	printf("Value of Var = %d\n", *ptr);
	printf("Address of Var = %p\n", ptr);
	*ptr = 20;
	printf("After doing *ptr = 20, *ptr is %d\n", *ptr);
	return 0;
}
