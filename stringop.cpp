#include <cstring>
#include"memory.h"
#include "glob.h"
#include"error_inf.h"


char* Stropee(int startt, int longg)
{

	memset(newname, 0, sizeof(newname));
	if (Temp[startt].sy == 39)
	{
		if (longg == 2)     //     #a   删除变量a的name的第一个字符； 
		{
			int sum = 0;
			sum = FTemp[f_flag].var.size();
			for (int i = 0; i<sum; i++)
			{
				if (!(strcmp(Temp[startt + 1].name, FTemp[f_flag].var[i].vname)))
				{
					if (strlen(FTemp[f_flag].var[i].vsval) == 0)
						Error(Temp[start].row, 1024);
					for (int j = 1; j<strlen(FTemp[f_flag].var[i].vsval); j++)
					{
						newname[j - 1] = FTemp[f_flag].var[i].vsval[j];
					}
					break;
				}
			}
		}
		else if (longg == 4) //  # " abc " 删除内容的第一个字符 
		{
			if(strlen(Temp[startt + 2].name)==0)
				Error(Temp[start].row, 1024);
			for (int i = 1; i<strlen(Temp[startt + 2].name); i++)
			{
				newname[i - 1] = Temp[startt + 2].name[i];
			}
		}
		else
		{
			Error(Temp[start].row, 1024);
		}
	}
	else if ((Temp[startt + 1].sy == 38 && Temp[startt].sy != 40) || Temp[startt + 3].sy == 38)
	{
		if (longg == 3)  //a$b  变量相连 
		{
			int numm = 0, sum = 0;
			sum = FTemp[f_flag].var.size();
			for (int i = 0; i<sum; i++)
			{
				if (!(strcmp(Temp[startt].name, FTemp[f_flag].var[i].vname)))
				{
					for (int j = 0; j<strlen(FTemp[f_flag].var[i].vsval); j++)
					{
						newname[numm] = FTemp[f_flag].var[i].vsval[j];
						numm++;
					}
					break;
				}
			}
			for (int i = 0; i<sum; i++)
			{
				if (!(strcmp(Temp[startt + 2].name, FTemp[f_flag].var[i].vname)))
				{
					for (int j = 0; j<strlen(FTemp[f_flag].var[i].vsval); j++)
					{
						newname[numm] = FTemp[f_flag].var[i].vsval[j];
						numm++;
					}
					break;
				}
			}
		}
		else if (longg == 7)  // " a " $ " b "  字符串相连； 
		{
			int numm = 0;
			for (int i = 0; i<strlen(Temp[startt + 1].name); i++)
			{
				newname[numm] = Temp[startt + 1].name[i];
				numm++;
			}
			for (int i = 0; i<strlen(Temp[startt + 5].name); i++)
			{
				newname[numm] = Temp[startt + 5].name[i];
				numm++;
			}
		}
		else if(longg==5)
		{
			if (Temp[startt].sy == 40)       //  " "$A 
			{
				int numm = 0, sum = 0;
				sum = FTemp[f_flag].var.size();
				for (int i = 0; i<strlen(Temp[startt + 1].name); i++)
				{
					newname[numm] = Temp[startt + 1].name[i];
					numm++;
				}
				for (int i = 0; i<sum; i++)
				{
					if (!(strcmp(Temp[startt + 4].name, FTemp[f_flag].var[i].vname)))
					{
						for (int j = 0; j<strlen(FTemp[f_flag].var[i].vsval); j++)
						{
							newname[numm] = FTemp[f_flag].var[i].vsval[j];
							numm++;
						}
						break;
					}
				}
			}
			else                 //A$" "
			{
				int numm = 0, sum = 0;
				sum = FTemp[f_flag].var.size();
				for (int i = 0; i<sum; i++)
				{
					if (!(strcmp(Temp[startt].name, FTemp[f_flag].var[i].vname)))
					{
						for (int j = 0; j<strlen(FTemp[f_flag].var[i].vsval); j++)
						{
							newname[numm] = FTemp[f_flag].var[i].vsval[j];
							numm++;
						}
						break;
					}
				}
				for (int i = 0; i<strlen(Temp[startt + 3].name); i++)
				{
					newname[numm] = Temp[startt + 3].name[i];
					numm++;
				}
			}
		}
		else
		{
			Error(Temp[start].row, 1024);
		}
	}
	else
	{
		if (longg == 1)
		{
			int numm = 0, sum = 0;
			sum = FTemp[f_flag].var.size();
			for (int i = 0; i<sum; i++)
			{
				if (!(strcmp(Temp[startt].name, FTemp[f_flag].var[i].vname)))
				{
					for (int j = 0; j<strlen(FTemp[f_flag].var[i].vsval); j++)
					{
						newname[numm] = FTemp[f_flag].var[i].vsval[j];
						numm++;
					}
					break;
				}
			}
		}
		else if (longg == 3)
		{
			int numm = 0;
			for (int i = 0; i<strlen(Temp[startt + 1].name); i++)
			{
				newname[numm] = Temp[startt + 1].name[i];
				numm++;
			}
		}
		else
		{
			Error(Temp[start].row, 1024);
		}
	}
	return newname;
}