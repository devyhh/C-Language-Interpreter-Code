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
	char vname[20];            //������
	int vtype;                 //��¼�������ͣ�1��int��2��real��3��string��
	union                      //��¼������ֵ
	{
		char vsval[80];         //�ַ�������
		int  vival;             //int�͵�ֵ
		float vfval;            //flaot�͵�ֵ
	};

};

typedef class function
{
public:
	char fname[20];                   //������
	int ROW;                      //��ʼ������
	int varnum;                   //�βθ���
	vector <int> vartype;         //���μ�¼ÿ���β����ͣ�1��int��2��real��3��string��
	int type;                     //��¼��������ֵ���ͣ�1��int��2��real��3��string��
	int stanum;                    //������ʼ�ĸ���
	vector <v>  var;               //��¼�ú���������
};

