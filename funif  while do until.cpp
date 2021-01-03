#include "memory.h"
#include "glob.h"
#include "error_inf.h"
v te;
int Judgee(int sta, int len)
{
	int re = 0;
	v r;
	int Num;
	if (Temp[sta].sy == 28)                          //第一个是(
	{
		int i = sta + 1, num = 0, flaa = 0;                         //去掉第一个（，判断到最后一个是否（）匹配得上
		while (i < sta + len - 1)
		{
			if (Temp[i].sy == 29)
				num--;
			else if (Temp[i].sy == 28)
				num++;

			if (num < 0)
			{
				flaa = 1;
				break;
			}
			i++;
		}
		if (flaa == 0)          //最后如果是if的)，长度减一 
		{
			len = len - 2;
			sta++;
		}
	}


	//while (Temp[sta].sy != 13 && Temp[sta].sy != 42 && Temp[sta].sy != 11 && Temp[sta].sy != 12&& Temp[sta].sy != 27&& Temp[sta].sy != 39)       //找变量或 双引号里面的东西 或数字 或! 或#
	//{
	//	sta++;
	//	len--;
	//}

	if (Temp[sta].sy == 13)
	{
		if (Temp[sta + 1].sy == 14)              //变量=   赋值
		{
			re = Equall(sta, len);
		}

		else if (Temp[sta + 1].sy == 28)              //变量(   函数 
		{
			r = Fun(sta, len);
			if (r.vtype == 3)
				re = 1;
			else if (r.vtype == 1)
				re = r.vival;
			else if (r.vtype == 2 && r.vfval != 0)
				re = 1;
			else if (r.vtype == 2 && r.vfval == 0)
				re = 0;
		}

		else if (Temp[sta + 1].sy >= 15 && Temp[sta + 1].sy <= 27 || Temp[sta + 1].sy == 45)   //变量+算数、逻辑、关系符    因式
		{
			re = Factorization(sta, len);
		}

		else if (Temp[sta + 1].sy == 38)     //变量$               串
		{
			re = 1;
		}
		else if (len == 1)                                      //单变量
		{
			Num = FTemp[f_flag].var.size();
			for (int j = 0; j < Num; j++)
			{
				if (strcmp(FTemp[f_flag].var[j].vname, Temp[sta].name) == 0)
				{
					if (FTemp[f_flag].var[j].vtype == 1 || FTemp[f_flag].var[j].vtype == 2)
					{
						re = Factorization(sta, len);
						break;
					}
					else if (FTemp[f_flag].var[j].vtype == 3)
					{
						re = 1;
						break;
					}
				}
			}

		}
	}

	else if (Temp[sta].sy == 42 || Temp[sta].sy == 39)                     //串操作一定是1  #
	{
		re = 1;
	}

	else if (Temp[sta].sy == 11 || Temp[sta].sy == 12 || Temp[sta].sy == 27 || Temp[sta].sy == 28)   //数字 !  (  交给因式
	{
		re = Factorization(sta, len);
	}

	if (re != 0)
	{
		return 1;
	}

	else return 0;
}
int main_f;
int funif()
{
	main_f = FTemp.size();
	int num;
	int flagif = 0;
	int k = 0;
	int FLAG = -1;
	k = Judgee(start + 1, finish - start - 1);
	
	if (k == 1)
	{
		flagif++;
		start =finish+3;
		finish = start;

		while (Temp[finish].sy != -2)     //finish找到\n 
		{
			finish++;
		}
		while (start == finish)
		{
			start++;
			finish = start;
			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
		}
		nummun = finish + 1;
		if (Temp[start].sy == 31)
			flagif--;
		while (finish<Temp.size() && flagif != 0)       //没到结尾 
		{

			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
			while (start == finish)
			{
				start++;
				finish = start;
				while (Temp[finish].sy != -2)     //finish找到\n 
				{
					finish++;
				}
			}
			nummun = finish + 1;                  //记录下一行 

			if (Temp[start].sy == 30)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				flagif++;
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 31)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				flagif--;

				if (flagif != 0)
				{
					finish++;
					start = finish;
				}
				else
				{
					start = finish;
				}
			}
			else if (Temp[start].sy == 6)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG=funif();
				if (FLAG != -1)
				{
					return FLAG;
				}
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 8)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG = funwhile();
				if (FLAG != -1)
				{
					return FLAG;
				}
			}
			else if (Temp[start].sy == 43)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG=fundountil();
				if (FLAG != -1)
				{
					return FLAG;
				}
			}
			else if (Temp[start].sy == 1 || Temp[start].sy == 2 || Temp[start].sy == 3)   //int\real\string，找定义函数 
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Def(start, finish - start);                  //传； 
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 13)                                  //开始为变量 
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				finish++;
				start = finish;
			}

			else if (Temp[start].sy == 5)                                   //return   
			{
				
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				return start;
			}

			else if (Temp[start].sy == 9)                                     //in
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Inputt(&Temp[start], finish - start);     //传; 
				finish++;
				start = finish;

			}

			else if (Temp[start].sy == 10)                                //out
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Outputt(start, finish - start);           //传; 
				finish++;
				start = finish;

			}
			/*else
			{
			printf("ERROR IN ROW %d\n", Temp[start].row);
			system("pause");
			}*/
			
			

		}
		if (Temp[finish + 1].sy == 7)
		{
			start = finish + 5;
			int flagelse = 0;
			flagelse++;
			while (flagelse != 0)
			{
				if (Temp[start].sy == 30)
					flagelse++;
				else if (Temp[start].sy == 31)
					flagelse--;
				start++;
			}
			finish = start;
		}

	}
	else if (k == 0)
	{

		finish = finish + 3;
		start = finish;
		flagif = 1;
		while (Temp[finish].sy != -2)     //finish找到\n 
		{
			finish++;
		}
		while (start == finish)
		{
			start++;
			finish = start;
			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
		}
		nummun = finish + 1;

		while (flagif != 0)
		{
			if (Temp[start].sy == 30)
				flagif++;
			else if (Temp[start].sy == 31)
				flagif--;
			start++;
		}

		int now;
		now = start + 1;
		if (Temp[now].sy == 7)
		{
			start = start + 5;
			finish = start;
			flagif++;
		}
		else
		{
			finish = start;
		}
		while (finish<Temp.size() && flagif != 0 && Temp[now].sy == 7)      //没到结尾 
		{

			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
			while (start == finish)
			{
				start++;
				finish = start;
				while (Temp[finish].sy != -2)     //finish找到\n 
				{
					finish++;
				}
			}
			nummun = finish + 1;                  //记录下一行 
			if (Temp[start].sy == 30)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				flagif++;
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 31)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				flagif--;
				if (flagif != 0)
				{
					finish++;
					start = finish;
				}
				else
				{
					start=finish;
				}
			}
			else if (Temp[start].sy == 6)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG = funif();
				if (FLAG != -1)
					return FLAG;
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 8)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG = funwhile();
				if (FLAG != -1)
					return FLAG;
			}
			else if (Temp[start].sy == 43)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG = fundountil();
				if (FLAG != -1)
					return FLAG;
			}
			else if (Temp[start].sy == 1 || Temp[start].sy == 2 || Temp[start].sy == 3)   //int\real\string，找定义函数 
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Def(start, finish - start);                  //传； 
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 13)                                  //开始为变量 
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				finish++;
				start = finish;
			}

			else if (Temp[start].sy == 5)                                   //return   
			{
				
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				return start;
			}

			else if (Temp[start].sy == 9)                                     //in
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Inputt(&Temp[start], finish - start);     //传; 
				finish++;
				start = finish;

			}

			else if (Temp[start].sy == 10)                                //out
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Outputt(start, finish - start);           //传; 
				finish++;
				start = finish;

			}
			/*else
			{
			printf("ERROR IN ROW %d\n", Temp[start].row);
			system("pause");
			}*/
		}
	}
	return FLAG;
}

int funwhile()
{
	main_f = FTemp.size();
	int flagwhile = 0;
	int newstart, newfinish;
	int FLAG = -1;
	newstart = start;
	newfinish = finish;
	int k,num;
	k = Judgee(start + 1, finish - start - 1);
	if (k == 1)
	{
		flagwhile++;
		start = finish+3;
		finish = start;
		while (Temp[finish].sy != -2)     //finish找到\n 
		{
			finish++;
		}
		while (start == finish)
		{
			start++;
			finish = start;
			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
		}
		nummun = finish + 1;
		if (Temp[start].sy == 31)
			flagwhile--;
		while (finish<Temp.size() && flagwhile != 0)       //没到结尾 
		{

			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
			while (start == finish)
			{
				start++;
				finish = start;
				while (Temp[finish].sy != -2)     //finish找到\n 
				{
					finish++;
				}
			}
			nummun = finish + 1;                  //记录下一行 

			if (Temp[start].sy == 30)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				flagwhile++;
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 31)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				flagwhile--;
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 6)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG = funif();

				if (FLAG != -1)
					return FLAG;
			}
			else if (Temp[start].sy == 8)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG=funwhile();
				if (FLAG != -1)
					return FLAG;
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 43)
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				FLAG=fundountil();
				if (FLAG != -1)
					return FLAG;
			}
			else if (Temp[start].sy == 1 || Temp[start].sy == 2 || Temp[start].sy == 3)   //int\real\string，找定义函数 
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Def(start, finish - start);                  //传； 
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 13)                                  //开始为变量 
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				finish++;
				start = finish;
			}
			else if (Temp[start].sy == 5)                                   //return   
			{
				
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				return start;

			}

			else if (Temp[start].sy == 9)                                     //in
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Inputt(&Temp[start], finish - start);     //传; 
				finish++;
				start = finish;

			}

			else if (Temp[start].sy == 10)                                //out
			{
				if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
				{
					num = FTemp[f_flag].var.size();
					cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
					cout << "第" << Temp[finish].row << "行" << endl;
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
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Outputt(start, finish - start);           //传;
				finish++;
				start = finish;

			}

		}
		start = newstart;
		finish = newfinish;
		nummun = finish + 1;
		FLAG=funwhile();
	}
	else
	{
		finish = finish + 3;
		start = finish;
		flagwhile = 1;
		while (flagwhile != 0)
		{
			if (Temp[start].sy == 30)
				flagwhile++;
			else if (Temp[start].sy == 31)
				flagwhile--;
			start++;
		}
		finish = start;
	}

	return FLAG;
}

int fundountil()
{
	main_f = FTemp.size();
	int flagdountil = 0;
	int newstart, newfinish;
	int kflag = 0;
	int FLAG=-1,num;
	newstart = start;
	newfinish = finish;
	finish++;
	start = finish;
	while (Temp[finish].sy != -2)     //finish找到\n 
	{
		finish++;
	}
	flagdountil++;

	while (finish < Temp.size() && flagdountil != 0)
	{
		if(kflag==0)
		{
			flagdountil--;
			kflag = 1;
         }
		while (Temp[finish].sy != -2)     //finish找到\n 
		{
			finish++;
		}
		while (start == finish)
		{
			start++;
			finish = start;
			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
		}
		nummun = finish + 1;                  //记录下一行 
		if (Temp[start].sy == 30)
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			flagdountil++;
			finish++;
			start = finish;
		}
		else if (Temp[start].sy == 31)
		{

			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			flagdountil--;
			if (Temp[start + 2].sy == 44)
			{
				finish = start + 2;
				while (Temp[finish].sy != -2)     //finish找到\n 
				{
					finish++;
				}
				int k;
				k = Judgee(start + 3, finish - start - 3);
				if (k==0)
				{
					start = newstart;
					finish = newfinish;
					nummun = finish + 1;
					FLAG=fundountil();
				}
				else
				{

					return FLAG;
				}
			}
			else
			{
			finish++;
			start = finish; 
			}
		}
		else if (Temp[start].sy == 6)
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			FLAG = funif();
			if (FLAG != -1)
				return FLAG;
		}
		else if (Temp[start].sy == 8)
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			FLAG = funwhile();
			if (FLAG != -1)
				return FLAG;
		}
		else if (Temp[start].sy == 43)
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			FLAG=fundountil();
			if (FLAG != -1)
				return FLAG;
			finish++;
			start = finish;

		}
		else if (Temp[start].sy == 1 || Temp[start].sy == 2 || Temp[start].sy == 3)   //int\real\string，找定义函数 
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			Def(start, finish - start);                  //传； 
			finish++;
			start = finish;
		}
		else if (Temp[start].sy == 13)                                  //开始为变量 
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			finish++;
			start = finish;
		}
		else if (Temp[start].sy == 5)                                   //return   
		{
			
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			return start;


		}

		else if (Temp[start].sy == 9)                                     //in
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			Inputt(&Temp[start], finish - start);     //传; 
			finish++;
			start = finish;

		}

		else if (Temp[start].sy == 10)                                //out
		{
			if ((mode == 1) || (mode == 2 && (f_flag == main_f - 1)))
			{
				num = FTemp[f_flag].var.size();
				cout << endl << "****************************************" << endl << "当前函数" << FTemp[f_flag].fname << endl;
				cout << "第" << Temp[finish].row << "行" << endl;
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
			if (Temp[finish - 1].sy != 37)
			{
				Error(Temp[start].row, 1013);
			}
			Outputt(start, finish - start);           //传;
			finish++;
			start = finish;
		}
	}
	return FLAG;

}