#include "memory.h"
#include "glob.h"
#include "error_inf.h"
int Precedence(char sign) {
	switch (sign) {
	case '^':
		return 11;
	case '!':
		return 10;
	case '+':
	case '-':
		return 8;
	case '*':
	case '/':
	case '%':
		return 9;
	case '>':
	case '<':
	case '~'://>=
	case '@'://<=
		return 7;
	case '?'://==
	case '_'://<>
		return 6;
	case '&':
		return 5;
	case '|':
		return 4;
	case '(':return 0;
	case ')':return -2;
	}
	return -3;
}

float Factorization(int first, int Long)
{
	int n, l, i = 0, m, j = 0, k;
	char a[40], b[40][2], f[40], c[40];
	float  d[40];//d中按顺序存每个变量的值
	float num[40];
	float nm = 0;
	n = 0;
	l = FTemp[f_flag].var.size();
	memset(a, 0, sizeof(a));
	memset(d, 0, sizeof(d));
	m = 0; p = 0;
	while (n < Long)
	{

		if (Temp[first + n].sy == 13)
		{
			for (i = 0; i < l;)
			{
				if (strcmp(Temp[first + n].name, FTemp[f_flag].var[i].vname))
					i++;
				else
				{
					if (FTemp[f_flag].var[i].vtype == 1)

					{
						d[p++] = FTemp[f_flag].var[i].vival;
					}
					else if (FTemp[f_flag].var[i].vtype == 2)
					{
						d[p++] = FTemp[f_flag].var[i].vfval;
					}
					break;


				}
			}
			if (i == l)
			{
				d[p] = 0;
				strcpy(vtp.vname, Temp[first + n].name);
				vtp.vtype = 1;
				vtp.vival = 0;
				FTemp[f_flag].var.push_back(vtp);
			}
			a[n++] = 'a' + m;
			m++;
		}
		else if (Temp[first + n].sy == 11)
		{
			d[p++] = Temp[first + n].ival;
			a[n++] = 'a' + m;
			m++;
		}
		else if (Temp[first + n].sy == 12)
		{
			d[p++] = Temp[first + n].fval;
			a[n++] = 'a' + m;
			m++;
		}
		else
		{
			a[n++] = Temp[first + n].name[0];
		}
	}
	p = 0;
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(num, 0, sizeof(num));
	l = strlen(a);
	for (i = 0, j = 0; i<l; i++)
	{
		k = -1;
		if ((a[i] >= 'a'&&a[i] <= 'z'))
		{
			c[p++] = a[i];
			continue;
		}
		k = Precedence(a[i]);
		if (k == -1)
		{
			Error(Temp[first].row, 1009);
			system("pause");
		}
		if (k == 0)
		{
			j++;
			b[j][0] = k;
			b[j][1] = a[i];
			continue;
		}
		if (k == -2)
		{
			j++;
			while (b[j - 1][1] != '(')
			{
				c[p++] = b[j - 1][1];
				b[j - 1][0] = 0;
				b[j - 1][1] = 0;
				j--;
			}
			if (b[j - 1][1] == '(')
			{
				b[j - 1][0] = 0;
				b[j - 1][1] = 0;
				j--;
			}
			j--;
			continue;
		}
		for (; j >= 0;)
		{
			if ((k>b[j][0]) || (k == 11 && k == b[j][0]))
			{
				j++;
				b[j][0] = k;
				b[j][1] = a[i];
				break;
			}
			else
			{
				if (b[j][1] == 0)
				{
					j--;
					continue;
				}
				c[p++] = b[j][1];
				b[j][0] = 0;
				b[j][1] = 0;
				j--;
			}
		}
	}
	for (; j >= 0;)
	{
		c[p++] = b[j][1];
		b[j][0] = 0;
		b[j][1] = 1;
		j--;
	}

	for (i = 0, j = 0; i < p; i++)
	{
		if (c[i] >= 'a'&&c[i] <= 'z')
		{
			num[j++] = d[c[i] - 'a'];
		}
		else if (c[i] == '!'&&j >= 1)
		{
			nm = Logicc(num[j - 1], 0, c[i]);
			num[j - 1] = nm;
		}
		else if ((c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/' || c[i] == '%' || c[i] == '^') && j >= 2)
		{
			nm = Aluu(num[j - 2], num[j - 1], c[i]);
			j--;
			num[j - 1] = nm;
			num[j] = 0;
		}
		else if (c[i] == '>' || c[i] == '<' || c[i] == '~' || c[i] == '@' || c[i] == '?' || c[i] == '_')
		{
			nm = Relatee(num[j - 2], num[j - 1], c[i]);
			j--;
			num[j - 1] = nm;
			num[j] = 0;
		}
		else if (c[i] == '&' || c[i] == '|')
		{
			nm = Logicc(num[j - 2], num[j - 1], c[i]);
			j--;
			num[j - 1] = nm;
			num[j] = 0;
		}
	}
	if (num[1] != 0)
	{
		Error(Temp[first].row, 1016);
		system("pause");
	}

	return num[0];
}