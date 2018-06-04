#include <stdio.h>

float Sum(int a)
{
	int i=0;
	float sum=0;
	float m;
	for (i=1; i <= a; i++)
	{
		m = 1.0*(1/(1.0*i));
		sum = sum + m;
	}
	return (sum);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("Sum = %f", Sum(n));
	return 0;
}
