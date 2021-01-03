
//函数返回的处理
#include"error_inf.h"
#include "memory.h"
#include "glob.h"

v  Ret(int a, int b)
{
	int l, i, op = 0, tp;
	if (b == 2)
	{

		if (Temp[start + 1].sy == 13)  //return a;
		{
			l = FTemp[f_flag].var.size();
			for (i = 0; i < l; i++)
				if (!(strcmp(FTemp[f_flag].var[i].vname, Temp[start + 1].name)))  //参数不存在
				{
					op = 1;
					return FTemp[f_flag].var[i];
				}
			if (!op)
				Error(Temp[start].row, 1001);
		}
		else if (Temp[start + 1].sy == 11 || Temp[start + 1].sy == 12)//return 1; 
		{
			vtp.vtype = Temp[start + 1].sy - 10;
			if (vtp.vtype == 1)
				vtp.vival = Temp[start + 1].ival;
			else if (vtp.vtype == 2)
				vtp.vfval = Temp[start + 1].fval;
			return vtp;
		}
		else
			Error(Temp[start].row, 1007);

	}

	else
	{
		if (Temp[start + 1].sy == 13 && Temp[start + 2].sy == 28 ) //return function(); 
			return Fun(start + 1, b - 1);
		else if ((Temp[start + 1].sy == 40) && (Temp[start + 3].sy == 40))//return "a";
		{
			vtp.vtype = 3;
			strcpy(vtp.vsval, Temp[start + 2].name);
			return vtp;
		}
		else if (Temp[start + 1].sy == 39 || Temp[start + 2].sy == 38 || Temp[start + 4].sy == 38)//return #a; return a$b;return "a"$b;return a$b;return "a"$"b";
		{
			Stropee(start + 1, b - 1);
			strcpy(vtp.vsval, newname);
			vtp.vtype = 3;
			return vtp;

		}
		else //return a+b;
		{

			vtp.vtype = 2;
			vtp.vfval = Factorization(start + 1, b - 1);
			return vtp;
		}



	}
}