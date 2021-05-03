#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<io.h>

void Run(char Type, char Type2, char *Path);

int CodeCount(char *Path) {	//�����ַ�����
	
	FILE *file = fopen(Path, "r");
	assert(file != NULL);	//���ļ��������򱨴�

	char code;
	int count = 0;

	while ((code = fgetc(file)) != EOF) 	//��ȡ�ַ�ֱ������
			count+= ((code != ' ') && (code != '\n') && (code != '\t'));	//�ж��Ƿ����ַ�	

	fclose(file);

	return count;
}

int WordCount(char *Path) {	//���㵥�ʸ���

	FILE *file = fopen(Path, "r");
	assert(file != NULL);

	char word;
	int is_word = 0;	//���ڼ�¼�ַ��Ƿ��ڵ�����
	int count = 0;

	while ((word = fgetc(file)) != EOF) {
		if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {	//�ж��Ƿ�����ĸ			
			count += (is_word == 0);
			is_word = 1;	//��¼����״̬
		}
		else 
			is_word = 0;	//��¼�����ڵ���״̬
	}
	fclose(file);

	return count;
}

void Run(char Type, char Type2, char *Path) {
	
	switch (Type) {
	case 'c': printf("�ַ���: %d\n", CodeCount(Path)); break;
	case 'w': printf("������: %d\n", WordCount(Path)); break;
	default: printf("�������"); break;
	}
}

int main(int argc, char *argv[]) {
	
	char Path[100] = "*.c";	//Ĭ�ϲ���
	char Type = 's';
	char Type2 = 'c';

	if (argv[1]) {	//�����������������Ϊ׼
		Type = *(argv[1] + 1);
		if (Type == 's') {
			Type2 = *(argv[2] + 1);
			strcpy(Path, argv[3]);
		}
		else
			strcpy(Path, argv[2]);
	}

	Run(Type, Type2, Path);	//������������

	return 0;
}
