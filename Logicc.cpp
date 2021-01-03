
//Âß¼­ÔËËã
#include"error_inf.h"
#include "memory.h"
#include "glob.h"

float Logicc(float x, float y, char op)
{

	switch (op)
	{
	case '|':
		if (x || y)return 1.0;
		else return 0;
		break;
	case '&':
		if (x && y)return 1.0;
		else return 0;
		break;
	case '!':
		if (x)return 0;
		else return 1.0;
		break;
	}
}