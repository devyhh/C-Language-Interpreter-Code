
#include <stack>
extern stack  <int> fg;
extern stack  <int> so;
extern vector <function> FTemp;           //函数表
extern function ftp;//临时储存
extern int f_flag;//  语句在执行函数位置
extern vector <pro> Temp;
extern v vtp;
extern pro tp;//临时储存
extern char newname[80];//串操作结果

//词法分析
extern int SUMM;// {}的计数器
extern int summ;// ()的计数器
extern int sunn;//  ""的计数器
extern int p;
extern char prog[80];
extern int line;
extern int nummun;            //nummun记录return后执行的位置 
extern int start, finish;  //每行开始与结束位置 
extern int mode;
extern void Inputt(pro *tmp, int i);  //inputt
extern void Outputt(int , int i); //Outputt
extern float Factorization(int, int); //Factorization
extern int Equall(int,int); //Equall
extern int Scaner(); // Scaner
extern void Fundeal(); //Fundeal
extern float Relatee(float, float, char);// Relatee
extern float Logicc(float, float, char); //Logicc
extern float Aluu(float, float, char); //Aluu
extern v  Fun(int, int); //Fun
extern char* Stropee(int, int);//stringop
extern void Def(int, int); //define
extern int funif(); //funif
extern int funwhile(); //
extern int Judgee(int, int); //funif
extern v Ret(int, int);//
extern int fundountil();