#include "main.h"
/* 定义读取和写入文本文件的函数 */

void read_txt(char* filepath)
{
    FILE* file;
    // 用于存储每一行的缓冲区
    char line[256];
    // 打开文件，指定为只读模式
    file = fopen(filepath, "r");
    // 异常处理
    if (file == NULL) {
        perror("无法打开文件");
        return ;
    }
    // 循环读取文件，直到遇到文件末尾
    while (fgets(line, sizeof(line), file)) {
        // 输出读取到的每一行
        printf("%s", line);
    }
    // 关闭文件
    fclose(file);
}

void write_txt(char* filename, char* content)
{
    FILE* file;
    // 打开文件，指定为只读模式
    file = fopen(filename, "a");
    // 异常处理
    if (file == NULL) {
        perror("无法打开文件");
        return ;
    }
    fprintf(file,"%s\n", content);
    fclose(file);

}









