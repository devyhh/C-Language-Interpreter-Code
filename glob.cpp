#include"memory.h"
#include "glob.h"
#include"error_inf.h"

vector <function> FTemp;           //函数表
function ftp;//临时储存
int f_flag;//  语句在执行函数位置
vector <pro> Temp;
v vtp;
pro tp;//临时储存
char newname[80];//串操作结果
int mode;
//词法分析
int SUMM;// {}的计数器
int summ;// ()的计数器
int sunn;//  ""的计数器
int p = 0;
int line = 0;//行号
char prog[80];
stack  <int> fg;
stack  <int> so;

int nummun;            //nummun记录return后执行的位置 
int start, finish;  //每行开始与结束位置 

float Factorization(int, int);
int Equall(int ,int);
int Scaner();
void Fundeal();
float Relatee(float, float, char);
float Logicc(float, float, char);
float Aluu(float, float, char);
v  Fun(int, int);
char* Stropee(int, int);
void Def(int, int);
int funif();
int funwhile();
v Ret(int, int);
int Judgee(int, int);
int fundountil();