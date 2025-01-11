/* 编辑词库 */
#include "main.h"
extern void add_word(FILE*);
extern void delete_word(FILE*,char*);
extern void check_word(char*);

void edit_lib()
{
    //打印词库列表
	check_lib();

	printf("$请选择要编辑的词库：\n");
	char libname[64];
	char filename[128] = "./WordsLib/";
	scanf("%s", libname);
	strcat(filename, libname);
	strcat(filename, ".txt");
	FILE* file = fopen(filename, "a+");
	if (file == NULL) {
		perror("无法打开文件或文件名错误");
		return;
	}
	// 选择操作
	bool flag = true;
	while (flag)
	{
		printf("*****************\n");
		printf("***1.增加新单词***\n");
		printf("***2.删除单词*****\n");
		printf("***3.查看当前词库单词\n");
		printf("***4.退出*********\n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: add_word(file); break;
		case 2: delete_word(file,filename); break;
		case 3: check_word(filename); break;
		case 4: flag = false; break;
		default:
			printf("请输入1-4的数字\n");
		}
	}
	fclose(file);
}


/* 添加单词 */
void add_word(FILE* file)
{
	word* new_word = (word*)malloc(sizeof(word));
	printf("请输入新单词英文: \n");
	scanf("%s", new_word->english);
	printf("请输入新单词词性(英文简称): \n");
	scanf("%s", new_word->pos);
	printf("请输入新单词中文: \n");
	scanf("%s", new_word->chinese);
	//去除换行符
	new_word->english[strcspn(new_word->english, "\n")] = 0;
	new_word->chinese[strcspn(new_word->chinese, "\n")] = 0;
	new_word->pos[strcspn(new_word->pos, "\n")] = 0;
    //写入词库的txt文件
	fprintf(file, "%s-%s-%s\n",new_word->english,new_word->pos,new_word->chinese);
	printf("添加成功！\n");
}
/* 删除单词 */
void delete_word(FILE* file,char* filename)
{
	char target_word[40];
	printf("请输入要删除的单词英文: \n");
	scanf("%s", target_word);
	// 创建临时文件
	char temp_filename[] = "./WordsLib/temp.txt";
	FILE* temp_file = fopen(temp_filename, "w");
	if (temp_file == NULL) {
		perror("无法创建临时文件");
		return;
	}
	// 重置文件指针到文件开头
	rewind(file);

	char line[128];
	int deleted = 0;

	// 逐行读取原文件内容
	while (fgets(line, sizeof(line), file)) {
		// 去除换行符
		line[strcspn(line, "\n")] = 0;

		char word_english[32];
		//%[^-]表示匹配所有字符，直到遇到第一个破折号（-）为止。
		sscanf(line, "%[^-]", word_english); // 仅提取单词部分

		// 如果当前行不是目标单词，则将其写入临时文件
		if (strcmp(word_english, target_word) != 0) {
			fprintf(temp_file, "%s\n", line);
		}
		else {
			deleted = 1; // 标记已找到并跳过此单词
		}
	}
	fclose(temp_file);
	fclose(file);
	// 移动临时文件覆盖原文件
	if (deleted) {
		remove(filename); // 删除原文件
		rename(temp_filename, filename); // 将临时文件重命名为原文件名
		printf("删除成功！\n");
	}
	else {
		printf("无此单词，删除失败！\n");
		remove(temp_filename); // 清理临时文件
	}
	// 重新打开文件为追加模式，以便后续操作
	file = fopen(filename, "a+");
	if (file == NULL) {
		perror("无法重新打开文件");
	}
}


/* 列出词库单词 */
void check_word(char* filename)
{
	read_txt(filename);
	printf("\n");
}