#include "memory.h"
#include "glob.h"
#include"error_inf.h"

int main()
{
	FILE *cfile;
	int FLAG = -1;
	char filename[80], sh[80];
	int num;

	int flag = 1, Syn = 0;//SynΪ��ĸ��ֵ
	cout << "����Ҫ�򿪵��ļ���" << endl;
	cin >> filename;
	cout << "ѡ��ģʽ�� 0.���� 1.����� 2.�����" << endl;
	while (1)
	{
  
	  cin >> mode;
	  if (mode >= 0 && mode <= 2)
		  break;
	  else
		  cout << "�������ִ��󣨽���Ϊ0��1��2����������ѡ��ģʽ��\n";
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
		start = FTemp[f_flag].stanum;   //start��¼������ÿ�еĿ�ʼλ��
		finish = start;

		while (finish < Temp.size())       //û����β 
		{

			while (Temp[finish].sy != -2)     //finish�ҵ�\n 
			{
				finish++;
			}
			if (mode)
			{
				num = FTemp[f_flag].var.size();
				cout << endl <<"****************************************"<<endl<< "��ǰ����" << FTemp[f_flag].fname << endl;
				cout << "��" << Temp[finish].row << "��" << endl;
				cout << "������" << endl;
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
			nummun = finish + 1;                  //��¼��һ�� 
			if (Temp[start].sy == 1 || Temp[start].sy == 2 || Temp[start].sy == 3)   //int\real\string���Ҷ��庯�� 
			{
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Def(start, finish - start - 1);                  //���� 
			}

			else if (Temp[start].sy == 13)                                  //��ʼΪ���� 
			{
				if (Temp[start + 1].sy == 14)                                 //����=    �Ҹ�ֵ     
				{
					if (Temp[finish - 1].sy != 37)
					{
						Error(Temp[start].row, 1013);
					}
					Equall(start, finish - start - 1);    //����; 
				}

				if (Temp[start + 1].sy == 28)                                 //����(     �Һ��� 
				{
					if (Temp[finish - 1].sy != 37)
					{
						Error(Temp[start].row, 1013);
					}
					Fun(start, finish - start);       //��)

				}
			}

			else if (Temp[start].sy == 5)                                   //return     
			{
				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Ret(start, finish - start - 1);                 //����;

				system("pause");

				return 0;

			}

			else if (Temp[start].sy == 9)                                     //in
			{

				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Inputt(&Temp[start], finish - start);     //��; 

			}

			else if (Temp[start].sy == 10)                                //out
			{

				if (Temp[finish - 1].sy != 37)
				{
					Error(Temp[start].row, 1013);
				}
				Outputt(start, finish - start);           //��; 
				

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