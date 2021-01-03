#include "memory.h"
#include "glob.h"
#include"error_inf.h"

void Fundeal()
{
	int i = 0, num, j, n = 0, f = 0;
	int NUM;//记录参数个数 
	num = Temp.size();
	for (i = 0; i < num; i++)
	{
		if ((Temp[i].sy == 1 || Temp[i].sy == 2 || Temp[i].sy == 3) && (Temp[i + 1].sy == 13 || Temp[i + 1].sy == 4) && Temp[i + 2].sy == 28)//变量类型+变量+（
		{
			strcpy(ftp.fname, Temp[i + 1].name);
			ftp.ROW = Temp[i].row;
			ftp.type = Temp[i].sy;

			j = 0;
			NUM = 0;
			while (Temp[i + 3 + j].sy != 29)   //跑到后括号 
			{
				if (Temp[i + 3 + j].sy == 1 || Temp[i + 3 + j].sy == 2 || Temp[i + 3 + j].sy == 3)
				{
					ftp.vartype.push_back(Temp[i + 3 + j].sy);                   //记录形参类型 
					vtp.vtype = Temp[i + 3 + j].sy;                          //形参进入变量表 
					strcpy(vtp.vname, Temp[i + 3 + j + 1].name);
					ftp.var.push_back(vtp);
					NUM++;                                           //形参个数+1
				}

				j++;
			}
			ftp.stanum = i + 3 + j + 4;                          //函数的第一格为后括号后第四格（\n  {  \n  内容）
			ftp.varnum = NUM;
			for (int q = 0; q < FTemp.size(); q++)
			{
				if (strcmp(ftp.fname, FTemp[q].fname) == 0 && ftp.varnum == FTemp[q].varnum)     //名字和形参个数相同
				{
					for (int p = 0; p < ftp.varnum; p++)                               //逐一匹配形参类型
					{
						if (ftp.vartype[p] != FTemp[q].vartype[p])
							goto aa;

					}
					Error(ftp.ROW, 1027);                                            //函数重定义 
				aa:;
				}
			}
			FTemp.push_back(ftp);                                //存入函数表 
			i = i + 3 + j + 1;//下一个Temp格子 
			n = 0;
			f = 0;
			while (1)                                                 //跳过函数体 
			{
				if (Temp[i].sy == 30)
				{
					n++;
				}

				else if (Temp[i].sy == 31)
				{
					n--;
				}

				if (n != 0)                //标记读到过{ 
				{
					f = 1;
				}

				if (n == 0 && f == 1)          //读到过{且花括号都对应了 
				{
					break;
				}

				i++;
			}
			i++; 		 //跳过 }后的; 
		}
		ftp.var.clear();
		ftp.vartype.clear();
	}
}