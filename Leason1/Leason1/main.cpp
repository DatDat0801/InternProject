#include<stdio.h>

/// <summary>
/// truyen tham chieu
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Swap1(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y=tmp;
}

/// <summary>
/// truyen tham tri
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Swap2(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a=0;
	int b = 0;

	printf("Nhap a: ");
	scanf("%d", &a);
	printf("Nhap b: ");
	scanf("%d", &b);

	Swap1(&a, &b);
	printf("After Swap1: \n");
	printf("a: %d \n", a);
	printf("b: %d \n", b);

	Swap2(a, b);
	printf("After Swap2: \n");
	printf("a: %d \n", a);
	printf("b: %d \n", b);

	return 0;
}