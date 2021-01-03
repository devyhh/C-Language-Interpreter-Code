
//赋值函数
#include"error_inf.h"
#include "memory.h"
#include "glob.h"

int Equall(int first,int Long)
{
	if (Long <= 2)
	{
		Error(Temp[first].row, 1018);
		system("pause");
	}
	int i,l,key;
	int re = 0;//返回值
	v KEY;
	int a = 0, b = 0, c;
    c = first + Long - 1;
	while (c != first)
	{
		key = -1;
		l = FTemp[f_flag].var.size();
		for (a = c; a >= first; a--)
		{
			if (Temp[a].sy == 14)
			{
				b = c - a;
				c = a - 1;
				a++;
				break;
			}
		}
		for (i = 0; i < l;)
		{
			if (strcmp(Temp[c].name, FTemp[f_flag].var[i].vname))
			{
				i++;
			}
			else
			{
				key = i;
				break;
			}
		}
		if (key == -1)
		{
			strcpy(vtp.vname, Temp[c].name);
			vtp.vtype = 1;
			vtp.vival = 0;
			key = i;
			FTemp[f_flag].var.push_back(vtp);
		}
		if (Temp[a].sy == 13 && Temp[a+1].sy == 28)
		{
			KEY = Fun(a, b);  ///////
		}
		else if (FTemp[f_flag].var[key].vtype == 3)
		{
			strcpy(FTemp[f_flag].var[key].vsval, Stropee(a, b));
			re = 1;
			continue;
		}
		else
		{
			KEY.vfval = Factorization(a, b);
			KEY.vtype = 2;
		}
		
		if (FTemp[f_flag].var[key].vtype == 1 && KEY.vtype == 1)
		{
			FTemp[f_flag].var[key].vival = KEY.vival;
			re = KEY.vival;
		}
		else if (FTemp[f_flag].var[key].vtype == 1 && KEY.vtype == 2)
		{
			FTemp[f_flag].var[key].vival = KEY.vfval;
			re = KEY.vfval;
		}
		else if (FTemp[f_flag].var[key].vtype == 2 && KEY.vtype == 1)
		{
			FTemp[f_flag].var[key].vfval = KEY.vival;
			re = KEY.vival;
		}
		else if (FTemp[f_flag].var[key].vtype == 2 && KEY.vtype == 2)
		{
			FTemp[f_flag].var[key].vfval = KEY.vfval;
			re = KEY.vfval;
		}
		else if (FTemp[f_flag].var[key].vtype == 3 && KEY.vtype == 3)
		{
			strcpy(FTemp[f_flag].var[key].vsval, KEY.vsval);
			re = 1;
		}
		else
		{
			Error(Temp[first].row, 1017);
			system("pause");
		}
	}
	return re;
}