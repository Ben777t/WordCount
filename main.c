#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<io.h>

void Run(char Type, char Type2, char *Path);

int CodeCount(char *Path) {	//计算字符个数
	
	FILE *file = fopen(Path, "r");
	assert(file != NULL);	//若文件不存在则报错

	char code;
	int count = 0;

	while ((code = fgetc(file)) != EOF) 	//读取字符直到结束
			count+= ((code != ' ') && (code != '\n') && (code != '\t'));	//判断是否是字符	

	fclose(file);

	return count;
}

int WordCount(char *Path) {	//计算单词个数

	FILE *file = fopen(Path, "r");
	assert(file != NULL);

	char word;
	int is_word = 0;	//用于记录字符是否处于单词中
	int count = 0;

	while ((word = fgetc(file)) != EOF) {
		if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {	//判断是否是字母			
			count += (is_word == 0);
			is_word = 1;	//记录单词状态
		}
		else 
			is_word = 0;	//记录不处于单词状态
	}
	fclose(file);

	return count;
}

void Run(char Type, char Type2, char *Path) {
	
	switch (Type) {
	case 'c': printf("字符数: %d\n", CodeCount(Path)); break;
	case 'w': printf("单词数: %d\n", WordCount(Path)); break;
	default: printf("输入错误"); break;
	}
}

int main(int argc, char *argv[]) {
	
	char Path[100] = "*.c";	//默认参数
	char Type = 's';
	char Type2 = 'c';

	if (argv[1]) {	//有输入参数则以输入为准
		Type = *(argv[1] + 1);
		if (Type == 's') {
			Type2 = *(argv[2] + 1);
			strcpy(Path, argv[3]);
		}
		else
			strcpy(Path, argv[2]);
	}

	Run(Type, Type2, Path);	//调用启动函数

	return 0;
}
