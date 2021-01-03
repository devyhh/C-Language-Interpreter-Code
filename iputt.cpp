#include<cstring>
#include<ctype.h>
#include"error_inf.h"
#include"memory.h"
#include"glob.h"
#include"error_inf.h"
//in a;

void Inputt(pro *tmp, int i)
{
	int m = 0, n = 0, l, k;
	char printl[80] = { '\0' };
	if (i == 3)
	{
		if (tmp[1].sy != 13)
			Error(tmp[1].row,1001);
		k = FTemp[f_flag].var.size();
		while (k != n)
		{
			if (strcmp(FTemp[f_flag].var[n].vname, tmp[1].name) == 0)
			{
				if (FTemp[f_flag].var[n].vtype == 1)
					cin >> FTemp[f_flag].var[n].vival;
				else if (FTemp[f_flag].var[n].vtype == 2)
					cin >> FTemp[f_flag].var[n].vfval;
				else
					cin >> FTemp[f_flag].var[n].vsval;
				break;
			}
			n++;
		}

		if (n == k)
		{
			strcpy(vtp.vname, tmp[1].name);
			cin >> vtp.vival;
			vtp.vtype = 1;
			FTemp[f_flag].var.push_back(vtp);
		}


	}

 //in " " a;
	else if (i == 7)
	{
		if (tmp[1].sy != 40)
			Error(tmp[0].row, 1002);
		if (tmp[2].sy != 42)
			Error(tmp[0].row, 1003);
		if (tmp[3].sy != 40)
			Error(tmp[0].row, 1002);
		if (tmp[4].sy != 36)
			Error(tmp[0].row, 1004);
		if (tmp[5].sy != 13)
			Error(tmp[1].row, 1001);
		strcpy(printl, tmp[2].name);

		do
		{
			if (printl[m] == '\\'&&printl[m + 1] == 'n')
			{
				m++;
				cout << endl;
			}
			else
				cout << printl[m];
			m++;
		} while (printl[m] != '\0');

		k = FTemp[f_flag].var.size();
		while (k != n)
		{
			if (strcmp(FTemp[f_flag].var[n].vname, tmp[5].name) == 0)
			{
				if (FTemp[f_flag].var[n].vtype == 1)
					cin >> FTemp[f_flag].var[n].vival;
				else if (FTemp[f_flag].var[n].vtype == 2)
					cin >> FTemp[f_flag].var[n].vfval;
				else
					cin >> FTemp[f_flag].var[n].vsval;
				break;
			}
			n++;
		}

		if (n == k)
		{
			strcpy(vtp.vname, tmp[5].name);
			cin >> vtp.vival;
			vtp.vtype = 1;
			FTemp[f_flag].var.push_back(vtp);
		}

	}
	else	{
		Error(tmp[0].row,1000);
	}
	
}
