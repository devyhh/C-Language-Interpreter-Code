#include "memory.h"
#include "glob.h"
#include"error_inf.h"

void Fundeal()
{
	int i = 0, num, j, n = 0, f = 0;
	int NUM;//��¼�������� 
	num = Temp.size();
	for (i = 0; i < num; i++)
	{
		if ((Temp[i].sy == 1 || Temp[i].sy == 2 || Temp[i].sy == 3) && (Temp[i + 1].sy == 13 || Temp[i + 1].sy == 4) && Temp[i + 2].sy == 28)//��������+����+��
		{
			strcpy(ftp.fname, Temp[i + 1].name);
			ftp.ROW = Temp[i].row;
			ftp.type = Temp[i].sy;

			j = 0;
			NUM = 0;
			while (Temp[i + 3 + j].sy != 29)   //�ܵ������� 
			{
				if (Temp[i + 3 + j].sy == 1 || Temp[i + 3 + j].sy == 2 || Temp[i + 3 + j].sy == 3)
				{
					ftp.vartype.push_back(Temp[i + 3 + j].sy);                   //��¼�β����� 
					vtp.vtype = Temp[i + 3 + j].sy;                          //�βν�������� 
					strcpy(vtp.vname, Temp[i + 3 + j + 1].name);
					ftp.var.push_back(vtp);
					NUM++;                                           //�βθ���+1
				}

				j++;
			}
			ftp.stanum = i + 3 + j + 4;                          //�����ĵ�һ��Ϊ�����ź���ĸ�\n  {  \n  ���ݣ�
			ftp.varnum = NUM;
			for (int q = 0; q < FTemp.size(); q++)
			{
				if (strcmp(ftp.fname, FTemp[q].fname) == 0 && ftp.varnum == FTemp[q].varnum)     //���ֺ��βθ�����ͬ
				{
					for (int p = 0; p < ftp.varnum; p++)                               //��һƥ���β�����
					{
						if (ftp.vartype[p] != FTemp[q].vartype[p])
							goto aa;

					}
					Error(ftp.ROW, 1027);                                            //�����ض��� 
				aa:;
				}
			}
			FTemp.push_back(ftp);                                //���뺯���� 
			i = i + 3 + j + 1;//��һ��Temp���� 
			n = 0;
			f = 0;
			while (1)                                                 //���������� 
			{
				if (Temp[i].sy == 30)
				{
					n++;
				}

				else if (Temp[i].sy == 31)
				{
					n--;
				}

				if (n != 0)                //��Ƕ�����{ 
				{
					f = 1;
				}

				if (n == 0 && f == 1)          //������{�һ����Ŷ���Ӧ�� 
				{
					break;
				}

				i++;
			}
			i++; 		 //���� }���; 
		}
		ftp.var.clear();
		ftp.vartype.clear();
	}
}