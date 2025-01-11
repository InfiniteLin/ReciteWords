#include "main.h"
extern char recite_lib[50];
extern void init_word_lib(word_lib* lib);
extern void add_word_to_lib(word_lib* lib, word* w);
extern void free_word_array(word_lib* array);
/* 加载词库到内存 */
word_lib* load_words()
{
    word_lib* lib = (word_lib*)malloc(sizeof(word_lib));
    init_word_lib(lib);
    FILE* file;
    // 用于存储每一行的缓冲区
    char line[256];
    // 打开文件，指定为只读模式
    char filepath[50] = "./WordsLib/";
    strcat(filepath, recite_lib);
    strcat(filepath, ".txt");
    file = fopen(filepath, "r");
    // 异常处理
    if (file == NULL) {
        perror("无法打开文件");
        return 0;
    }
    // 循环读取文件，向Wordlib添加元素
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^-]-%[^-]-%[^\n]", lib->data[i].english, lib->data[i].pos, lib->data[i].chinese);
        i++;
        lib->size = i;
        if (lib->size >= 50)
        {
            lib->data = (word*)realloc(lib->data, (50 + lib->size) * sizeof(word));
        }
    }
    fclose(file);
    return lib;
}

// 初始化wordlib
void init_word_lib(word_lib* lib) {
    lib->data = (word*)malloc(sizeof(word)*50);
    lib->size = 0;
}

// 释放资源
void free_word_array(word_lib* array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
}
