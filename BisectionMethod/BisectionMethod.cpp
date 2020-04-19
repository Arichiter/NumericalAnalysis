#include <stdio.h>
#include <math.h>
#define LEVEL 1e-7

double fx(double x);
double BisectionMethod(double x1, double x2);
int Sgn(double x);
int main()
{
	double a, b;
	printf("Please input the [a, b]: ");
	scanf("%lf%lf", &a, &b);
	while (Sgn(fx(a)) * Sgn(fx(b)) >= 0)
	{
		printf("\nPlease input the [a,b] again: ");
		scanf("%lf%lf", &a, &b);
	}
	
	printf("\n The answer is %lf.", BisectionMethod(a,b));
	return 0;
}

/*f(x)*/
double fx(double x)
{
	return x * x * x - 7.7 * x * x + 19.2 * x - 15.3;
}

/*判断函数的正负，防止函数值溢出*/
int Sgn(double x)
{
	return x < 0 ? -1 : 1;
}

/*二分法*/
double BisectionMethod(double x1, double x2)
{
	double x;
	int i = 0;
	while (fabs(x1 - x2) > LEVEL)
	{
		x = (x1 + x2) / 2;
		if (fabs(fx(x)) < LEVEL)
		{
			return x;
		}
		else if (Sgn(fx(x1)) * Sgn(fx(x)) < 0)
		{
			x2 = x;
		}
		else if (Sgn(fx(x)) * Sgn(fx(x2)) < 0)
		{
			x1 = x;
		}
		printf("%4d %6lf    %8lf   [%6lf, %6lf]  %6lf\n", i++, x, fx(x), x1, x2, x2 - x1);
	}
}