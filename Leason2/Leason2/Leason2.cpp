// Leason2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

unsigned long long int Factorial(int n)
{
	unsigned long long int tmp = 1;
	for (int i = 1; i <= n; i++)
		tmp *= i;
	return tmp;
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
			printf("Ket qua cua tinh %d! = %lld",input, Factorial(input));
		}
	} while (input<=0 || input >=20);
}

int main()
{
	EnterInput_CalFactorial();
	return 0;
}
