#include<iostream>
using namespace std;
void Error(int row, int x)//����+����
{
	switch(x)
	{
	case 1000:  cout << "E" << x << ":" << "��������ʽ����! ����λ�ڵ�" << row << "��" << endl; break;
	case 1001:  cout << "E" << x << ":" << "�������ʹ���! ����λ�ڵ�" << row << "��" << endl; break;
	case 1002:  cout << "E" << x << ":" << "ȱ������! ����λ�ڵ�" << row << "��" << endl; break;
	case 1003:  cout << "E" << x << ":" << "�������ݴ���! ����λ�ڵ�" << row << "��" << endl; break;
	case 1004:  cout << "E" << x << ":" << "ȱ�ٶ���! ����λ�ڵ�" << row << "��" << endl; break;
	case 1005:  cout << "E" << x << ":" << "�������ʽ����! ����λ�ڵ�" << row << "��" << endl; break;
	case 1006:  cout << "E" << x << ":" << "��ʹ�ö��Ż�ֺ�! ����λ�ڵ�" << row << "��" << endl; break;
	case 1007:  cout << "E" << x << ":" << "δʶ��ı�����! ����λ�ڵ�" << row << "��" << endl; break;
	case 1008:  cout << "E" << x << ":" << "�����Ѿ�����! ����λ�ڵ�" << row << "��" << endl; break;
	case 1009:  cout << "E" << x << ":" << "������ʽ�޷�������ַ�! ����λ�ڵ�" << row << "��" << endl; break;
	case 1010:  cout << "E" << x << ":" << "�����޷���ֵ! ����λ�ڵ�" << row << "��" << endl; break;
	case 1011:  cout << "E" << x << ":" << "��������ֵ���ʹ���! ����λ�ڵ�" << row << "��" << endl; break;
	case 1012:  cout << "E" << x << ":" << "δ����ĺ���! ����λ�ڵ�" << row << "��" << endl; break;
	case 1013:  cout << "E" << x << ":" << "ȱ�ٷֺ�! ����λ�ڵ�" << row << "��" << endl; break;
	case 1014:  cout << "E" << x << ":" << "0����ĸ! ����λ�ڵ�" << row << "��" << endl; break;
	case 1015:  cout << "E" << x << ":" << "��int������! ����λ�ڵ�" << row << "��" << endl; break;
	case 1016:  cout << "E" << x << ":" << "��ʽ����! ����λ�ڵ�" << row << "��" << endl; break;
	case 1017:  cout << "E" << x << ":" << "��ֵ���Ͳ�ƥ��! ����λ�ڵ�" << row << "��" << endl; break;
	case 1018:  cout << "E" << x << ":" << "��ʽ����! ����λ�ڵ�" << row << "��" << endl; break;
	case 1019:  cout << "E" << x << ":" << "δʶ����ַ�! ����λ�ڵ�" << row << "��" << endl; break;
	case 1020:  cout << "E" << x << ":" << "()������ƥ��! ����λ�ڵ�" << row << "��" << endl; break;
	case 1021:  cout << "E" << x << ":" << "{}������ƥ��! ����λ�ڵ�" << row << "��" << endl; break;
	case 1022:  cout << "E" << x << ":" << "����������ƥ��! ����λ�ڵ�" << row << "��" << endl; break;
	case 1023:  cout << "E" << x << ":" << "δ����������! ����λ�ڵ�" << row << "��" << endl; break;
	case 1024:  cout << "E" << x << ":" << "������min-c������Ҫ�󣡴���λ�ڵ�" << row << "��" << endl; break;
	case 1025:  cout << "E" << x << ":" << "δ�ҵ�����������λ�ڵ�" << row << "��" << endl; break;
	case 1026:  cout << "E" << x << ":" << "���һ��������main����������λ�ڵ�" << row << "��" << endl; break;
	case 1027:  cout << "E" << x << ":" << "�����ض��壡����λ�ڵ�" << row << "��" << endl; break;
	default: cout << "δ֪����" << endl; break;
	}
	system("pause");
	exit(0);

}