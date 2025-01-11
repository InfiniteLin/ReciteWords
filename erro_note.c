#include "main.h"
/* 实现错词本相关功能*/
extern char recite_lib[50];
extern void check_erro_note();
extern void recite_erro_note();
extern void edit_erro_note();

/* 错词本主函数 */
void erro_note()
{
	bool flag = true;
	while (flag)
	{
		//菜单
		printf("*****错词本*****\n");
		printf("***1.查看错词***\n");
		printf("***2.错词背诵***\n");
		printf("***3.编辑错词本*\n");
		printf("***4.退出******\n");
		printf("$请选择:\n");
		//选择
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: check_erro_note(); break;
		case 2: recite_erro_note(); break;
		case 3: edit_erro_note(); break;
		case 4: flag=false; break;
		default:
			printf("$请在1-4中选择\n");
		}
	}
	
}

/* 查看错题本 */
void check_erro_note()
{
	read_txt("./WordsLib/错词本.txt");
}

/* 错词背诵 */
void recite_erro_note()
{
	//保存当前背诵词库
	char temp[50];
	strcpy(temp, recite_lib);
	//将背诵词库修改为错词本
	strcpy(recite_lib, "错词本");
	//调用背诵函数
	cite();
	//将背诵词库改回原来的
	strcpy(recite_lib, temp);
}

/* 编辑错词本 */
void edit_erro_note()
{
	bool flag = true;
	char filename[] = "./WordsLib/错词本.txt";
	FILE* file = fopen(filename, "a+");
	while (flag)
	{
		printf("*****************\n");
		printf("***1.增加新单词***\n");
		printf("***2.删除单词*****\n");
		printf("***3.退出*********\n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: add_word(file); break;
		case 2: delete_word(file, filename); break;
		case 3: flag = false; break;
		default:
			printf("$请输入1-3的数字\n");
		}
	}
	fclose(file);
}

void add_to_note(word* new_word)
{
	printf("$输入1将当前单词加入错词本,输入其他数字继续\n");
	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		char filename[] = "./WordsLib/错词本.txt";
		FILE* file = fopen(filename, "a+");
		fprintf(file, "%s-%s-%s\n", new_word->english, new_word->pos, new_word->chinese);
		fclose(file);
	}
}