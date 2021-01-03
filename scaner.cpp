
//词法分析
#include"error_inf.h"
#include<cstring>
#include<ctype.h>
#include "memory.h"
#include "glob.h"

char token[8];
int stringflag = 0, string_n = 0;
//F:\\min-c.txt
int Scaner()
{
	char ch;
	int str_flag=0;
	
	int kk;
	kk = Temp.size();

	int syn, m = 0, n, sum = 0;
	char *rwtab[12] = { "int","real","string","main","return","if","else","while","in","out","do","until" };
	float cont = 0, l = 1;//i记录行数
						  /*
						  共分为三大块，分别是标示符、数字、符号，对应下面的 if   else if  和 else
						  */
	for (n = 0; n < 8; n++) token[n] = NULL;
	ch = prog[p++];               //ch是第一个字符 
	if (stringflag == 1)  //处理引号内部的字符串
	{
		if (ch == 34)
		{
			stringflag = 0;
			sunn--;
			str_flag = 1;//标记该引号为后引号
			Temp.push_back(tp);
			//cout << tp.sy << " " << tp.row << " " << tp.name << endl;
			tp.fval = 0;
			tp.ival = 0;
			tp.row = 0;
			tp.sy = 0;
			memset(tp.name, 0, sizeof(tp.name));
		}
		else if (ch == '\n')
		{
			Error(line, 1022);
			system("pause");
		}
		else
		{
			syn = 42;
			tp.sy = syn;
			tp.row = line;
			tp.name[string_n++] = ch;
			return syn;
		}
	}
	while (ch == ' ' || ch == '\t' || ch == '\0')              //空格读下一个，标记后移 
	{
		ch = prog[p];
		p++;
	}
	if (isalpha(ch))  //可能是标示符或者变量名 
	{
		m = 0;
		while (isalnum(ch))      //读完这个变量名 
		{
			token[m++] = ch;
			ch = prog[p++];
		}
		token[m++] = '\0';         //变量尾定义为空格
		p--;                     //现在p回退一个，指向变量名后一个字符 
		syn = 13;
		for (n = 0; n < 12; n++)  //将识别出来的字符和已定义的标示符作比较
			if (strcmp(token, rwtab[n]) == 0)
			{
				if (n == 10)
					syn = 43;
				else if (n == 11)
					syn = 44;
				else
				    syn = n + 1;                  //保留字syn=对应的数字（1~6），变量名syn=13 
				break;
			}
	}
	else if (isdigit(ch))  //数字 
	{

		sum = 0;
		while (isdigit(ch))           //记录数字 
		{
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		if (ch == '.')
		{
			l = 1;
			ch = prog[p++];
			while (isdigit(ch))           //记录数字 
			{
				l *= 0.1;
				cont += (ch - '0')*l;
				ch = prog[p++];
			}
			cont += sum;
			syn = 12;   //浮点型syn=12； 
		}
		else
			syn = 11;
		p--;
		if (sum > 32767)                         //越界syn=-1 ，整型数字syn=11 
			syn = -1;
	}

	else switch (ch)   //其他字符 
	{
	case'<':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')                         //<=   syn=23
		{
			syn = 23;
			token[0] = '@';
		}
		else  if (ch == '>')                  //<>    syn=45
		{
			syn = 45;
			token[0] = '_';
		}
		else	                               //<   syn=21
		{
			syn = 21;
			p--;
		}
		break;
	case'>':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')                                 //>= syn=22
		{
			syn = 22;
			token[0] = '~';
		}
		else                                      //>   syn=20
		{
			syn = 20;
			p--;
		}
		break;
	case'&':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '&')                         //&&   syn=25
		{
			syn = 25;
			token[m++] = ch;
		}
		else
		{
			Error(line,1023);
			system("pause");
		}
		break;
	case'|':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '|')                         //||   syn=26
		{
			syn = 26;
			token[m++] = ch;
		}
		else
		{
			Error(line, 1023);
			system("pause");
		}
		break;
	case'!':syn = 27; token[0] = ch; break;
	case'%':syn = 19; token[0] = ch; break;                    //  %   syn =19
	case'*':syn = 17; token[0] = ch; break;                    //  *   syn =17
	case'/':  if (prog[p] == '/')syn = -2;
			  else { syn = 18; token[0] = ch; }break;                    //  /   syn =18
	case'+':syn = 15;
		if (kk >= 1&&Temp[kk - 1].sy != 11 && Temp[kk - 1].sy != 12 && Temp[kk - 1].sy != 13 && Temp[kk - 1].sy != 29 )
		{
			tp.sy = 11;
			tp.row = line;
			tp.ival = 0;
			Temp.push_back(tp);
		}
		token[0] = ch;
		break;                    //  +   syn =15
	case'-':syn = 16;
		if (kk >= 1 && Temp[kk - 1].sy != 11 && Temp[kk - 1].sy != 12 && Temp[kk - 1].sy != 13 && Temp[kk - 1].sy != 29 )
		{
			tp.sy = 11;
			tp.row = line;
			tp.ival = 0;
			Temp.push_back(tp);
		}
		token[0] = ch;
		break;                    //  -   syn =16
	case'=':m = 0; token[m++] = ch;
		ch = prog[p++];
		if (ch == '=')                         //==   syn=24
		{
			syn = 24;
			token[0] = '?';
		}
		else                                    //=   syn=14
		{
			syn = 14;
			p--;
		}
		break;
	case';':syn = 37; token[0] = ch; break;                    //  ;   syn =37
	case'(':syn = 28; 
		token[0] = ch;
		summ++;
		break;                    //  (   syn =28
	case')':syn = 29; 
		token[0] = ch; 
		summ--;
		if (summ < 0)
		{
			Error(line, 1020);
			system("pause");
		}
		break;                    //  )   syn =29
	case'{':syn = 30; 
		token[0] = ch; 
		SUMM++;
		break;
	case'}':syn = 31; 
		token[0] = ch;
		SUMM--;
		if (SUMM < 0)
		{
			Error(line, 1021);
			system("pause");
		}
		break;
	case'[':syn = 32; token[0] = ch; break;
	case']':syn = 33; token[0] = ch; break;
	case'^':syn = 35; token[0] = ch; break;
	case',':syn = 36; token[0] = ch; break;
	case'$':syn = 38; token[0] = ch; break;
	case'#':syn = 39; token[0] = ch; break;
	case'"':syn = 40;
		token[0] = ch;
		if (stringflag == 0&&str_flag!=1)
		{
			string_n = 0;
			stringflag = 1;
			sunn++;
		}
		break;
	case'\'':syn = 41; token[0] = ch; break;
	case'\n':syn = -2; break;                               //  \n   syn =-2
	default: syn = -1; break;                               //  其他   syn =-1
	}

	if (syn == -1)
	{
		Error(line,1019);
		system("pause");
	}
	if (kk >= 1 && (Temp[kk - 1].sy == 31 || Temp[kk - 1].sy == 30 || Temp[kk - 1].sy == 37) && syn != -2 )
	{
		tp.sy = -2;
		tp.row = line;
		tp.name[0] = '\n';
		Temp.push_back(tp);
	}
	if (kk >= 1 && Temp[kk - 1].sy != -2 && (syn == 30 || syn == 31) )
	{
		tp.sy = -2;
		tp.row = line;
		tp.name[0] = '\n';
		Temp.push_back(tp);
	}
	tp.sy = syn;
	tp.row = line;
	if (tp.sy == 11)
	{
		tp.ival = sum;
	}
	else if (tp.sy == 12)
	{
		tp.fval = cont;
	}
	else
	{
		strcpy(tp.name, token);
	}
	Temp.push_back(tp);
	tp.fval = 0;
	tp.ival = 0;
	tp.row = 0;
	tp.sy = 0;
	memset(tp.name, 0, sizeof(tp.name));

	return syn;
}

