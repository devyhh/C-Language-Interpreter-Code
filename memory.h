#include<vector>
#include<iostream>
#include <cstdlib>
using namespace std;

typedef class pro
{
public:
	int sy;
	int row;
	union 
	{
		char name[80];
		int ival;
		float fval;
	};
};


typedef class v
{
public:
	char vname[20];            //变量名
	int vtype;                 //记录变量类型（1是int，2是real，3是string）
	union                      //记录变量的值
	{
		char vsval[80];         //字符串储存
		int  vival;             //int型的值
		float vfval;            //flaot型的值
	};

};

typedef class function
{
public:
	char fname[20];                   //函数名
	int ROW;                      //开始的行数
	int varnum;                   //形参个数
	vector <int> vartype;         //依次记录每个形参类型（1是int，2是real，3是string）
	int type;                     //记录函数返回值类型（1是int，2是real，3是string）
	int stanum;                    //函数开始的格子
	vector <v>  var;               //记录该函数参数表
};

