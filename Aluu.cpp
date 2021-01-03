
//À„ ı‘ÀÀ„
#include"error_inf.h"
#include "memory.h"
#include "glob.h"
#include<cmath>

float Aluu(float a, float b, char op)
{
	int c;
	float d;
	int i;
	if (op == '+')
	{
		return a + b;
	}

	if (op == '-')
	{
		return a - b;
	}

	if (op == '*')
	{
		return a*b;
	}

	if (op == '/')
	{
		if (b == 0)
		{
			Error(Temp[start].row, 1014);
		}

		else
		{
			return a / b;
		}
	}

	if (op == '%')
	{
		if ((int)a != a || (int)b != b)
		{
			Error(Temp[start].row, 1015);
		}
		else
		{
			c = (int)a % (int)b;
			return (float)c;
		}
	}

	if (op == '^')
	{
		
		return pow(a, b);
	}
}
