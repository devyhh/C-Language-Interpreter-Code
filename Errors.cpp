#include<iostream>
using namespace std;
void Error(int row, int x)//行数+编码
{
	switch(x)
	{
	case 1000:  cout << "E" << x << ":" << "输入语句格式错误! 错误位于第" << row << "行" << endl; break;
	case 1001:  cout << "E" << x << ":" << "变量类型错误! 错误位于第" << row << "行" << endl; break;
	case 1002:  cout << "E" << x << ":" << "缺少引号! 错误位于第" << row << "行" << endl; break;
	case 1003:  cout << "E" << x << ":" << "引号内容错误! 错误位于第" << row << "行" << endl; break;
	case 1004:  cout << "E" << x << ":" << "缺少逗号! 错误位于第" << row << "行" << endl; break;
	case 1005:  cout << "E" << x << ":" << "输出语句格式错误! 错误位于第" << row << "行" << endl; break;
	case 1006:  cout << "E" << x << ":" << "请使用逗号或分号! 错误位于第" << row << "行" << endl; break;
	case 1007:  cout << "E" << x << ":" << "未识别的变量名! 错误位于第" << row << "行" << endl; break;
	case 1008:  cout << "E" << x << ":" << "变量已经存在! 错误位于第" << row << "行" << endl; break;
	case 1009:  cout << "E" << x << ":" << "出现因式无法处理的字符! 错误位于第" << row << "行" << endl; break;
	case 1010:  cout << "E" << x << ":" << "函数无返回值! 错误位于第" << row << "行" << endl; break;
	case 1011:  cout << "E" << x << ":" << "函数返回值类型错误! 错误位于第" << row << "行" << endl; break;
	case 1012:  cout << "E" << x << ":" << "未定义的函数! 错误位于第" << row << "行" << endl; break;
	case 1013:  cout << "E" << x << ":" << "缺少分号! 错误位于第" << row << "行" << endl; break;
	case 1014:  cout << "E" << x << ":" << "0做分母! 错误位于第" << row << "行" << endl; break;
	case 1015:  cout << "E" << x << ":" << "非int型求余! 错误位于第" << row << "行" << endl; break;
	case 1016:  cout << "E" << x << ":" << "因式错误! 错误位于第" << row << "行" << endl; break;
	case 1017:  cout << "E" << x << ":" << "赋值类型不匹配! 错误位于第" << row << "行" << endl; break;
	case 1018:  cout << "E" << x << ":" << "等式错误! 错误位于第" << row << "行" << endl; break;
	case 1019:  cout << "E" << x << ":" << "未识别的字符! 错误位于第" << row << "行" << endl; break;
	case 1020:  cout << "E" << x << ":" << "()数量不匹配! 错误位于第" << row << "行" << endl; break;
	case 1021:  cout << "E" << x << ":" << "{}数量不匹配! 错误位于第" << row << "行" << endl; break;
	case 1022:  cout << "E" << x << ":" << "引号数量不匹配! 错误位于第" << row << "行" << endl; break;
	case 1023:  cout << "E" << x << ":" << "未定义的运算符! 错误位于第" << row << "行" << endl; break;
	case 1024:  cout << "E" << x << ":" << "不符合min-c串运算要求！错误位于第" << row << "行" << endl; break;
	case 1025:  cout << "E" << x << ":" << "未找到函数！错误位于第" << row << "行" << endl; break;
	case 1026:  cout << "E" << x << ":" << "最后一个函数非main函数！错误位于第" << row << "行" << endl; break;
	case 1027:  cout << "E" << x << ":" << "函数重定义！错误位于第" << row << "行" << endl; break;
	default: cout << "未知错误！" << endl; break;
	}
	system("pause");
	exit(0);

}