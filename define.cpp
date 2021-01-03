#include"memory.h"
#include"glob.h"
#include"error_inf.h"

void Def(int start, int clong)
{
	int i, m = 1, x=0, l,inf;
	if (Temp[start].sy == 1)
	{

		while (m < clong)
		{
			if (Temp[start + m].sy != 13)   // 不是参数
				Error(Temp[start].row, 1001);
			l = FTemp[f_flag].var.size();
			for (i = 0; i < l; i++)
			{
				if (!(strcmp(FTemp[f_flag].var[i].vname, Temp[start + m].name)))  //参数已经存在
					Error(Temp[start].row, 1008);
			}
			strcpy(vtp.vname, Temp[start + m].name);
			vtp.vtype = 1;
			m++;
			if (Temp[start + m].sy == 14)   // int a=1;
			{
				FTemp[f_flag].var.push_back(vtp);
				x = m - 1;
				while ((Temp[start + m].sy != 36 || inf) && m<clong)
				{
					if (Temp[start + m].sy == 28)
						inf = 1;
					if (Temp[start + m].sy == 29)
						inf = 0;
					m++;
				}
				Equall(start + x, m - x);
			}
			else if (Temp[start + m].sy == 36 || m == clong) // int a;
			{
				vtp.vival = 0;
				vtp.vtype = 1;
				FTemp[f_flag].var.push_back(vtp);
			}
			else
				Error(Temp[start].row, 1006);
			if (Temp[start + m].sy == 36)
				m++;
		}
	}
	else if (Temp[start].sy == 2)
	{

		while (m < clong)
		{
			if (Temp[start + m].sy != 13)   // 不是参数
				Error(Temp[start].row, 1001);
			l = FTemp[f_flag].var.size();
			for (i = 0; i < l; i++)
				if (!(strcmp(FTemp[f_flag].var[i].vname, Temp[start + m].name)))  //参数已经存在
					Error(Temp[start].row, 1008);
			strcpy(vtp.vname, Temp[start + m].name);
			vtp.vtype = 2;
			m++;
			if (Temp[start + m].sy == 14)   // real a=1;
			{
				FTemp[f_flag].var.push_back(vtp);
				x = m - 1;
				while ((Temp[start + m].sy != 36 || inf) && m<clong)
				{
					if (Temp[start + m].sy == 28)
						inf = 1;
					if (Temp[start + m].sy == 29)
						inf = 0;
					m++;
				}
				Equall(start + x, m - x);
			}
			else if (Temp[start + m].sy == 36 || m == clong) // real a;
			{
				vtp.vfval = 0;
				vtp.vtype = 2;
				FTemp[f_flag].var.push_back(vtp);
			}
			else
				Error(Temp[start].row, 1006);
			if (Temp[start + m].sy == 36)
				m++;
		}
	}
	else if (Temp[start].sy == 3)
	{
		while (m<clong)
		{
			if (Temp[start + m].sy != 13)   // 不是参数
				Error(Temp[start].row, 1001);
			l = FTemp[f_flag].var.size();
			for (i = 0; i<l; i++)
				if (!(strcmp(FTemp[f_flag].var[i].vname, Temp[start + m].name)))  //参数已经存在
					Error(Temp[start].row, 1008);
			strcpy(vtp.vname, Temp[start + m].name);
			m++;
			if (Temp[start + m].sy == 14)   // str a="s";
			{
				m++;
				x = m;
				while ((Temp[start + m].sy != 36 || inf) && m<clong)
				{
					if (Temp[start + m].sy == 28)
						inf = 1;
					if (Temp[start + m].sy == 29)
						inf = 0;
					m++;
				}
				Stropee(start + x, m - x);
				strcpy(vtp.vsval, newname);
				vtp.vtype = 3;
				m++;
			}
			else if (Temp[start + m].sy == 36 || m == clong) // str a;
			{
				vtp.vtype = 3;
			}
			else
				Error(Temp[start].row, 1006);
			FTemp[f_flag].var.push_back(vtp);
			if (Temp[start + m].sy == 36)
				m++;
		}
	}
}