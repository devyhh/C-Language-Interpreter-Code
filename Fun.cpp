
//函数处理
#include"error_inf.h"
#include "memory.h"
#include "glob.h"

v Fun(int s, int len)
{
	int n, i, j, m;
	int f = 1;
	v te,ta;
	int FLAG = -1,F=0;
	vector <v> a;
	int nm[10], mm = 0;//函数变量个数及种类，1为int，2为real，3为string 
	f = s + len;

	n = FTemp.size();
	m = FTemp[f_flag].var.size();
	memset(nm, 0, sizeof(nm));

	i = s + 2;
	while (Temp[i].sy != 29)              //处理并记录待传递的值及其个数，为接下来的函数匹配做准备
	{
		if (Temp[i].sy == 11)
		{
			nm[mm++] = 1;
			ta.vival = Temp[i].ival;
			ta.vtype = 1;
			a.push_back(ta);
		}
		else if (Temp[i].sy == 12)
		{
			nm[mm++] = 2;
			ta.vfval = Temp[i].fval;
			ta.vtype = 2;
			a.push_back(ta);
		}
		else if (Temp[i].sy == 13)
		{
			for (j = 0; j<m; j++)
			{
				if (strcmp(FTemp[f_flag].var[j].vname, Temp[i].name) == 0)
				{
					nm[mm++] = FTemp[f_flag].var[j].vtype;
					a.push_back(FTemp[f_flag].var[j]);
					break;
				}
			}
			if (j == m)
			{
				strcpy(vtp.vname , Temp[i].name);
			    vtp.vtype = 1;
				vtp.vival = 0;
				FTemp[f_flag].var.push_back(vtp);
				a.push_back(vtp);
			}
		}
		else if (Temp[i].sy == 42)
		{
			nm[mm++] = 3;
			strcpy(ta.vsval , Temp[i].name);
			ta.vtype = 3;
			a.push_back(ta);
		}
		i++;
	}

	for (i = 0; i<n; i++)
	{
		j = 0;
		if (strcmp(FTemp[i].fname, Temp[s].name) == 0)
		{
			if (FTemp[i].var.size() == mm)
			{
				while (j<mm)
				{
					if (FTemp[i].var[j].vtype == nm[j])
						j++;
					else
						break;
				}
				if (j == mm)
					break;
			}
		}
		
	}
	if (i == n)
	{
		Error(Temp[start].row, 1012);
	}
	for (j = 0; j<mm; j++)
	{
		if (FTemp[i].var[j].vtype == 1)
		{
			FTemp[i].var[j].vival = a[j].vival;
		}

		if (FTemp[i].var[j].vtype == 2)
		{
			FTemp[i].var[j].vfval = a[j].vfval;
		}

		if (FTemp[i].var[j].vtype == 3)
		{
			strcpy(FTemp[i].var[j].vsval, a[j].vsval);
		}
	}
	a.clear();
	fg.push(f_flag);
	f_flag = i;
	so.push(finish);
	finish = FTemp[i].stanum;
	start = finish;
	f = 1;
	while (f != 0)
	{
		finish = start;
		while (Temp[finish].sy != -2)     //finish找到\n 
		{
			if (Temp[finish].sy == 30)
				f++;

			if (Temp[finish].sy == 31)
				f--;
			finish++;
		}
		int num;
		if (mode == 1)
		{
			num = FTemp[f_flag].var.size();
			cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
			cout << "第" << Temp[start].row << "行" << endl;
			cout << "参数表：" << endl;
			for (int i = 0; i<num; i++)
			{
				if (FTemp[f_flag].var[i].vtype == 1)
					cout << FTemp[f_flag].var[i].vname << "=" << FTemp[f_flag].var[i].vival << endl;
				else if (FTemp[f_flag].var[i].vtype == 2)
					cout << FTemp[f_flag].var[i].vname << "=" << FTemp[f_flag].var[i].vfval << endl;
				else
					cout << FTemp[f_flag].var[i].vname << "=  '" << FTemp[f_flag].var[i].vsval << "'" << endl;
			}
			cout << "****************************************" << endl;
			system("pause");
			cout << endl;
		}
		nummun = finish + 1;                  //记录下一行 
		if (Temp[start].sy == 1 || Temp[start].sy == 2 || Temp[start].sy == 3)   //int\real\string，找定义函数 
		{
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			Def(start, finish - start - 1);                  //传；

		}

		else if (Temp[start].sy == 13)                                  //开始为变量 
		{
			if (Temp[start + 1].sy == 14)                                 //变量=    找赋值     
			{
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Equall(start, finish - start - 1);    //不传; 

			}

			if (Temp[start + 1].sy == 28)                                 //变量(     找函数 
			{
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Fun(start, finish - start);       //传)

			}
		}

		else if (Temp[start].sy == 5)                                   //return     
		{
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			te = Ret(start, finish - start - 1);                 //不传; 
			finish = so.top();
			so.pop();
			if (te.vtype != FTemp[f_flag].type&&(((te.vtype==1||te.vtype==2)&& FTemp[f_flag].type==3)||te.vtype==3&&(FTemp[f_flag].type==1|| FTemp[f_flag].type==2)))
			{

				Error(Temp[start].row, 1011);
			}
			f_flag = fg.top();
			fg.pop();
			
			return te;

		}

		else if (Temp[start].sy == 9)                                     //in
		{
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			Inputt(&Temp[start], finish - start);     //传; 

		}

		else if (Temp[start].sy == 10)                                //out
		{
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			Outputt(start, finish - start);           //传; 

		}

		else if (Temp[start].sy == 6)                                //if
		{

			FLAG=funif();
			if (FLAG != -1)
			{
				start = FLAG;
				F = 1;
			}

		}
		else if (Temp[start].sy == 8)                                //while
		{

			FLAG=funwhile();
			if (FLAG != -1)
			{
				start = FLAG;
				F = 1;
			}
		}
		else if (Temp[start].sy == 43)                                     //do
		{
			FLAG = fundountil();
			if (FLAG != -1)
			{
				start = FLAG;
				F = 1;
			}
				
		}

		/*else
		{
		printf("ERROR IN ROW %d\n", Temp[start].row);
		exit(0);
		}*/
		if (F == 0)
		{
           finish++;
		   start = finish;
		}
		


	}
	Error(Temp[start].row, 1010);
}