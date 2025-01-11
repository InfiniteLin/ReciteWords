#pragma once
#define _CRT_SECURE_NO_WARNINGS
/* 存放所有的声明 */

/* 库引用 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h> 


/* 结构体定义 */

//单词结构体
struct word {
	char english[30];
	char chinese[40];
	char pos[10]; //词性
};
typedef struct word word;

//词库结构体
struct wordlib {
	word* data;
	int size;
};
typedef struct wordlib word_lib;

/* 函数声明 */
void menu();
void choose();

void read_txt(char*);
void write_txt(char* filename,char* content);

void cite();
struct wordlib* load_words();

void wordlib();
void edit_lib();
void check_lib();
void add_word(FILE* file);
void delete_word(FILE* file, char* filename);

void erro_note();
void add_to_note(word* new_word);


