#include "main.h"
extern char recite_lib[50];
extern void e2c(word_lib* lib);
extern void c2e(word_lib* lib);
/* 背诵功能主函数 */
void cite()
{
	word_lib* lib = load_words();
	printf("*****背诵模式*****\n");
	printf("**1.英文--->中文**\n");
	printf("**2.中文--->英文**\n");
	printf("******3.退出******\n");
	printf("$请选择背诵模式:\n");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1: e2c(lib); break;
	case 2: c2e(lib); break;
	case 3: break;
	default:
		printf("$请在1-3中选择");
	}
}

/* 英->中背诵 e2c 是english to chinese的简写*/
void e2c(word_lib* lib)
{
	int count_all = 0;
	int count_erro = 0;
	bool flag1 = true;
	while (flag1)
	{
		srand((unsigned)time(NULL));
		int i = (rand() % lib->size) + 1;
		printf("$%s 的中文意思是:\n", lib->data[i].english);
		char ans[32];
		scanf("%s", ans);
		//对于中文答案的判定比较宽松，只要答案包含在中文意思中就判断正确
		if (strstr(lib->data[i].chinese,ans))
		{
			printf("$答案正确！\n");
		}
		else
		{
			printf("$答案错误！\n");
			add_to_note(&(lib->data[i]));
			count_erro++;
		}
		count_all++;
		printf("$输入1继续背诵,-1退出\n");
		int choice;
		scanf("%d", &choice);
		if (choice == -1)
		{
			double temp = (double)(count_all - count_erro) / count_all;
			printf("$此次共背诵 %d 个单词\n", count_all);
			printf("$正确率为：%.2f%%\n", temp * 100);
			flag1 = false;
		}

	}

}

void c2e(word_lib* lib)
{
	int count_all = 0;
	int count_erro = 0;
	bool flag = true;
	while (flag)
	{
		srand((unsigned)time(NULL));
		int i = (rand() % lib->size) + 1;
		printf("$%s 的英文是:\n", lib->data[i].chinese);
		char ans[32];
		scanf("%s", ans);
		if (strcmp(ans, lib->data[i].english) == 0)
		{
			printf("$答案正确！\n");
		}
		else
		{
			printf("$答案错误！\n");
			add_to_note(&(lib->data[i]));
			count_erro++;
		}
		count_all++;
		printf("$输入1继续背诵,-1退出\n");
		int choice;
		scanf("%d", &choice);
		if (choice == -1)
		{
			double temp = (double)(count_all - count_erro) / count_all;
			printf("$此次共背诵 %d 个单词\n",count_all);
			printf("$正确率为：%.2f%%\n", temp*100);
			flag = false;
		}

	}
} 