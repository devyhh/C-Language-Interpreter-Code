
#include <stack>
extern stack  <int> fg;
extern stack  <int> so;
extern vector <function> FTemp;           //������
extern function ftp;//��ʱ����
extern int f_flag;//  �����ִ�к���λ��
extern vector <pro> Temp;
extern v vtp;
extern pro tp;//��ʱ����
extern char newname[80];//���������

//�ʷ�����
extern int SUMM;// {}�ļ�����
extern int summ;// ()�ļ�����
extern int sunn;//  ""�ļ�����
extern int p;
extern char prog[80];
extern int line;
extern int nummun;            //nummun��¼return��ִ�е�λ�� 
extern int start, finish;  //ÿ�п�ʼ�����λ�� 
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