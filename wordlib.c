#include "main.h"
/* 提前声明维护词库相关的函数 */
extern void libmenu();
extern void bulid_new_lib();
extern void edit_lib();
extern void check_lib();
extern void change_lib();
// 引入全局变量
extern char recite_lib[50];
/* 选择功能 维护词库功能的主函数 */
void wordlib()
{
	bool flag = true;
	while (flag)
	{
		libmenu();
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: bulid_new_lib(); break;
		case 2: edit_lib(); break;
		case 3: check_lib(); break;
		case 4: change_lib(); break;
		case 0: flag = false; break;
		default:
			printf("$请在0-4中选择");
		}
	}
}
/* 打印菜单 */
void libmenu()
{
	printf("******************************\n");
	printf("*********1.新建词库************\n");
	printf("*********2.编辑词库************\n");
	printf("*********3.列出本地词库************\n");
	printf("*********4.更改当前背诵词库*****\n");
	printf("*********0.退出****************\n");
	printf("$请输入你的选择:\n");
}

/* 新建词库 */
void bulid_new_lib()
{
	char libname[128];
	char path[256] = "./WordsLib/";
	printf("请输入词库名称：\n");
	scanf("%s", libname);
	strcat(path, libname);
	strcat(path, ".txt");
	//创建 txt文件
	FILE* file = fopen(path, "w");
	fclose(file);
	//将词库名写入liblist文件
	write_txt("./WordsLib/Wordliblist.txt",libname);
	printf("建立成功！\n");
}
/* 编辑词库 */
// 在editlib.c文件中实现

/* 列出本地词库 */
void check_lib()
{
	char filepath[] = "./WordsLib/WordlibList.txt";
	printf("$所有词库如下：\n");
	read_txt(filepath);

}
/* 改变当前背诵词库 */
void change_lib()
{
	check_lib();
	printf("$当前背诵词库：%s\n", recite_lib);
	printf("$请输入想要背诵的词库：\n");
	scanf("%s", recite_lib);
	printf("$修改成功!\n$当前背诵词库：%s\n", recite_lib);
}


