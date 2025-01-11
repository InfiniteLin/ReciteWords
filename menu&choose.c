#include "main.h"
extern bool flag;
/* 打印菜单 */
void menu()
{
	printf("                  快乐背单词                \n");
	printf("*******************************************************\n ");
	printf("                  0：退出程序     \n ");
	printf("                  1：词库设置     \n ");
	printf("                  2：背诵模式     \n ");
	printf("                  3：错词本       \n ");
	printf("********************************************************\n");
	printf("请输入您要选择的内容：\n");
}
/* 选择 */
void choose()
{
	int choice;
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 0:flag = false; break;
	case 1:wordlib(); break;
	case 2:cite(); break;
	case 3:erro_note(); break;
	default:
		printf("$请在0--3之间选择\n");
	}
}




