#include"memory.h"
#include "glob.h"
#include"error_inf.h"

vector <function> FTemp;           //������
function ftp;//��ʱ����
int f_flag;//  �����ִ�к���λ��
vector <pro> Temp;
v vtp;
pro tp;//��ʱ����
char newname[80];//���������
int mode;
//�ʷ�����
int SUMM;// {}�ļ�����
int summ;// ()�ļ�����
int sunn;//  ""�ļ�����
int p = 0;
int line = 0;//�к�
char prog[80];
stack  <int> fg;
stack  <int> so;

int nummun;            //nummun��¼return��ִ�е�λ�� 
int start, finish;  //ÿ�п�ʼ�����λ�� 

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