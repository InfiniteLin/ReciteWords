#include "main.h"
bool flag = true;  
char recite_lib[50] = "英语四级"; //标识当前背诵词库的名称，默认是英语四级
int main()
{
	//flag = false退出循环
	while (flag)
	{
		menu();
		choose();
	}
}



