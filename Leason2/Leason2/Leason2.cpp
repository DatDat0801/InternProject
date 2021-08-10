// Leason2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int Factorial(int n)
{
	if (n == 1)
		return 1;
	return n * Factorial(n - 1);
}

void EnterInput_CalFactorial()
{
	int input = 0;
	do {
		printf("Nhap so nguyen duong <20: \n");
		scanf("%d", &input);
		if (input <= 0 || input>=20)
		{
			printf("==============Nhap Lai============== \n");
		}
		else
		{
			printf("Ket qua cua tinh %d! = %d",input, Factorial(input));
		}
	} while (input<=0 || input >=20);
}

int main()
{
	EnterInput_CalFactorial();
	return 0;
}
