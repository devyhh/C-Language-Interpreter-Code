
//¹ØÏµº¯Êı
#include"error_inf.h"
#include "memory.h"
#include "glob.h"

float Relatee(float a, float b,char c)
{
	float key;
	if (c == '>'&&a > b)
		return 1;
	else if (c == '<'&&a < b)
		return 1;
	else if (c == '~'&&a >= b)
		return 1;
	else if (c == '@'&&a <= b)
		return 1;
	else if (c == '?'&&a == b)
		return 1;
	else if (c == '_'&&a != b)
		return 1;
	else
		return 0;

}