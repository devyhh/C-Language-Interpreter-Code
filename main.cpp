#include "memory.h"
#include "glob.h"
#include"error_inf.h"

int main()
{
	FILE *cfile;
	int FLAG = -1;
	char filename[80], sh[80];
	int num;

	int flag = 1, Syn = 0;//Syn为字母数值
	cout << "输入要打开的文件：" << endl;
	cin >> filename;
	cout << "选择模式： 0.运行 1.逐语句 2.逐过程" << endl;
	while (1)
	{
  
	  cin >> mode;
	  if (mode >= 0 && mode <= 2)
		  break;
	  else
		  cout << "输入数字错误（仅可为0、1、2），请重新选择模式：\n";
	}
		
	
		if ((cfile = fopen(filename, "r")) == NULL)
		{
			printf("Cannot open the file.\n");
			exit(0);
		}
		SUMM = 0;//{}
		while (fgets(sh, 80, cfile) != NULL)
		{
			p = 0;
			sunn = 0;//""
			summ = 0;//()
			if (flag)
				printf("%4d:%s", ++line, sh);
			else printf("%s", sh);
			if (sh[strlen(sh) - 1] == '\n')
				flag = 1;
			else flag = 0;
			strcpy(prog, sh);
			do
			{
				Syn = Scaner();
			} while (Syn != -2);
			if (summ != 0)
			{
				Error(line, 1020);
			}
			if (sunn != 0)
			{
				Error(line, 1022);
			}
		}
		if (SUMM != 0)
		{
			Error(line, 1021);
		}
		Fundeal();
		if (FTemp.size() == 0)
		{
			Error(0, 1025);
		}
		f_flag = FTemp.size() - 1;

		if (strcmp(FTemp[f_flag].fname, "main") != 0)
		{
			Error(FTemp[f_flag].ROW, 1026);
		}
		start = FTemp[f_flag].stanum;   //start记录主函数每行的开始位置
		finish = start;

		while (finish < Temp.size())       //没到结尾 
		{

			while (Temp[finish].sy != -2)     //finish找到\n 
			{
				finish++;
			}
			if (mode)
			{
				num = FTemp[f_flag].var.size();
				cout << endl <<"****************************************"<<endl<< "当前函数" << FTemp[f_flag].fname << endl;
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
				Ret(start, finish - start - 1);                 //不传;

				system("pause");

				return 0;

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

				FLAG = funif();
				if (FLAG != -1)
				{
					system("pause");
					return 0;
				}
			}
			else if (Temp[start].sy == 8)                                //while
			{

				FLAG = funwhile();
				if (FLAG != -1)
				{
					system("pause");
					return 0;
				}
			}
			else if (Temp[start].sy == 43)
			{
				FLAG = fundountil();
				if (FLAG != -1)
				{
					system("pause");
					return 0;
				}
			}

			/*else
			{
			printf("ERROR IN ROW %d\n", Temp[start].row);
			exit(0);
			}*/

			finish++;
			start = finish;
			
		}

		system("pause");
	
	
}
//D:\\001.txt