#include"memory.h"
#include"glob.h"
#include"error_inf.h"
void Outputt(int start, int clong)
{
	int i, j, t, k, num;
	num = FTemp[f_flag].var.size();//main函数的参数数量 


	if (Temp[start + 1].sy == 40)	//out后是引号
	{
		if (Temp[start + 2].sy != 42)
			Error(Temp[start].row, 1003);
		if (Temp[start + 3].sy != 40)
			Error(Temp[start].row, 1002);
		if (Temp[start + 4].sy == 37)
		{
			for (t = 0; t < strlen(Temp[start + 2].name); t++)
			{
				if (Temp[start + 2].name[t] == '\\'&&Temp[start + 2].name[t + 1] == 'n')
				{
					cout << endl;
					t = t + 1;
				}
				else

					cout << Temp[start + 2].name[t];

			}


		}
		// out "Start\n"; 
		else if (Temp[start + 4].sy == 36)
		{  
			if(Temp[start+5].sy!=13)
			Error(Temp[start].row, 1001);
			for (t = 0; t < strlen(Temp[start + 2].name); t++)
			{
				if (Temp[start + 2].name[t] == '\\'&&Temp[start + 2].name[t + 1] == 'n')
				{
					cout << endl;
					t = t + 1;
				}
				else
					cout << Temp[start + 2].name[t];
			}
			for (j = 0; j < num; j++)
				if (strcmp(FTemp[f_flag].var[j].vname, Temp[start + 5].name) == 0)
				{
					if (FTemp[f_flag].var[j].vtype == 1) cout << FTemp[f_flag].var[j].vival;  // out "n=",n;
					if (FTemp[f_flag].var[j].vtype == 2) cout << FTemp[f_flag].var[j].vfval;
					if (FTemp[f_flag].var[j].vtype == 3) cout << FTemp[f_flag].var[j].vsval;
					break;
				}
			if(j==num)
			{
				Error(Temp[start].row, 1007);
			}
		}
		else
			Error(Temp[start].row, 1006);
	}



	else if (Temp[start + 1].sy == 11)     //out后是int数 
	{
		if (Temp[start + 3].sy == 40)
		{
			for (i = 0; i < Temp[start + 1].ival; i++)

				for (t = 0; t < strlen(Temp[start + 4].name); t++)
				{
					if (Temp[start + 4].name[t] == '\\'&&Temp[start + 4].name[t + 1] == 'n')
					{
						cout << endl;
						t = t + 1;
					}
					else
						cout << Temp[start + 4].name[t];

				}                                         //out  10, "Start\n";	

			if (Temp[start + 6].sy == 36 && Temp[start + 7].sy == 40)
				for (t = 0; t < strlen(Temp[start + 8].name); t++)
				{
					if (Temp[start + 8].name[t] == '\\'&&Temp[start + 8].name[t + 1] == 'n')
					{
						cout << endl;
						t = t + 1;
					}
					else
						cout << Temp[start + 8].name[t];

				}                                   //out  10, "Start\n","hello";

			else if (Temp[start + 6].sy == 36 && Temp[start + 7].sy == 13)
			{
				for (j = 0; j < num; j++)
					if (strcmp(FTemp[f_flag].var[j].vname, Temp[start + 7].name) == 0)
					{
						if (FTemp[f_flag].var[j].vtype == 1) cout << FTemp[f_flag].var[j].vival;  //out  10, "Start\n",n;
						if (FTemp[f_flag].var[j].vtype == 2) cout << FTemp[f_flag].var[j].vfval;
						if (FTemp[f_flag].var[j].vtype == 3) cout << FTemp[f_flag].var[j].vsval;
						break;
					}
				if (j == num)
					Error(Temp[start].row, 1007);
			}
		}
		else if (Temp[start + 3].sy == 13)
		{

			for (j = 0; j < num; j++)
				if (strcmp(FTemp[f_flag].var[j].vname, Temp[start + 3].name) == 0)
					for (i = 0; i < Temp[start + 1].ival; i++)
					{
						if (FTemp[f_flag].var[j].vtype == 1)cout << FTemp[f_flag].var[j].vival;  //out  10, n;
						if (FTemp[f_flag].var[j].vtype == 2) cout << FTemp[f_flag].var[j].vfval;
						if (FTemp[f_flag].var[j].vtype == 3) cout << FTemp[f_flag].var[j].vsval;
					
					}
			if(i==num)
				Error(Temp[start].row, 1007);
		}
		else
			Error(Temp[start].row, 1001);
	}



	else	if (Temp[start + 1].sy == 13) //out后是变量
	{
		for (j = 0; j<num; j++)
			if (strcmp(FTemp[f_flag].var[j].vname, Temp[start + 1].name) == 0) break;

		if (Temp[start + 2].sy == 37)
		{
			if (FTemp[f_flag].var[j].vtype == 1) cout << FTemp[f_flag].var[j].vival;  //out n;
			if (FTemp[f_flag].var[j].vtype == 2) cout << FTemp[f_flag].var[j].vfval;
			if (FTemp[f_flag].var[j].vtype == 3) cout << FTemp[f_flag].var[j].vsval;
		}

		if (Temp[start + 2].sy == 36)
		{
			if (Temp[start + 3].sy == 40)
			{
				for (i = 0; i<FTemp[f_flag].var[j].vival; i++)
					for (t = 0; t < strlen(Temp[start + 4].name); t++)
					{
						if (Temp[start + 4].name[t] == '\\'&&Temp[start + 4].name[t + 1] == 'n')
						{
							cout << endl;
							t = t + 1;
						}
						else
							cout << Temp[start + 4].name[t];

					}                                            // out n,"Start\n";

				if (Temp[start + 6].sy == 36 && Temp[start + 7].sy == 40)
					for (t = 0; t < strlen(Temp[start + 8].name); t++)
					{
						if (Temp[start + 8].name[t] == '\\'&&Temp[start + 8].name[t + 1] == 'n')
						{
							cout << endl;
							t = t + 1;
						}
						else
							cout << Temp[start + 8].name[t];  // out n,"Start\n","hello";

					}

				if (Temp[start + 6].sy == 36 && Temp[start + 7].sy == 13)
					for (j = 0; j<num; j++)
						if (strcmp(FTemp[f_flag].var[j].vname, Temp[start + 7].name) == 0)
							for (i = 0; i<Temp[start + 1].ival; i++)
							{
								if (FTemp[f_flag].var[j].vtype == 1)cout << FTemp[f_flag].var[j].vival;  // out n,"Start\n",n;
								if (FTemp[f_flag].var[j].vtype == 2) cout << FTemp[f_flag].var[j].vfval;
								if (FTemp[f_flag].var[j].vtype == 3) cout << FTemp[f_flag].var[j].vsval;
						
							}

			}


			if (Temp[start + 3].sy == 13)
			{
				for (k = 0; k<num; k++)
					if (strcmp(FTemp[f_flag].var[k].vname, Temp[start + 3].name) == 0)
						for (i = 0; i<FTemp[f_flag].var[j].vival; i++)
						{
							if (FTemp[f_flag].var[k].vtype == 1) cout << FTemp[f_flag].var[k].vival;  //out n,n;
							if (FTemp[f_flag].var[k].vtype == 2) cout << FTemp[f_flag].var[k].vfval;
							if (FTemp[f_flag].var[k].vtype == 3) cout << FTemp[f_flag].var[k].vsval;
						}
			}
		}
	}

	else 
		Error(Temp[start].row, 1005);

}