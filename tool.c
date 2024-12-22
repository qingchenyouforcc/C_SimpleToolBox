#include "tool.h"

void de_head_poem() {
	int n=0, i;
	char *poem[20], str[80], mean[20];
	
	fflush(stdin);
	printf("请输入英文诗(小于20句,输入#号结束):\n");
	gets(str);
	while (str[0] != '#') {
		poem[n] = (char *)malloc(sizeof(char)*(strlen(str)+1));
		strcpy(poem[n], str);
		n++;
		gets(str);
	}
	
	for (i=0; i<n; i++) {
		mean[i] = *poem[i];
		free(poem[i]);
	}
	mean[i] = '\0';
	printf("藏头意思为: %s", mean);
	
	Sleep(5000);
}

void pw_gen() {
	char pw[20] = {0};
	int num, need_char=1, r, wi=0, list[20] = {0};
	FILE *fp = fopen("pw.txt", "a");
	
	srand(time(NULL));
	
	printf("请输入要生成的密码位数(最小6，最大20):\n");
	scanf("%d", &num);
	fflush(stdin);
	printf("是否含有符号？(yes) [1]yes [0]no\n");
	scanf("%d", &need_char);
	if (need_char == 1) {
		for (int i=0; i<num; i++, wi++) {
			while (wi<num/4) {
				r = rand()%num;
				if (list[r] == 0) break;
			}
			list[r] = 2;
		}
		wi = 0;
		for (int i=0; i<num; i++, wi++) {
			while (wi<num - num/4) {
				r = rand()%num;
				if (list[r] == 0) break;
			}
			list[r] = 1;
		}
	} else {
		for (int i=0, wi=0; i<num; i++, wi++) {
			while (wi<num) {
				r = rand()%num;
				if (list[r] == 0) break;
			}
			list[r] = 1;
		}
	}
	
	
	for (int i=0; i<num; i++) {
		if (list[i] == 1) {
			if (rand()%3 == 0) {
				pw[i] = 48 + rand()%10;
			} else if (rand()%3 == 1) {
				pw[i] = 65 + rand()%26;				
			} else {
				pw[i] = 97 + rand()%26;
			}
		} else if (list[i] == 2) {
			pw[i] = 33 + rand()%10;
		}
	}
	
	printf("生成的密码为: %s\n密码已经保存到目录的pw.txt中了", pw);
	pw[num] = '\n';
	fputs(pw, fp);
	fclose(fp);
	
	Sleep(5*1000);
}
