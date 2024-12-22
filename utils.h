#ifndef UTILS_H
#define UTILS_H

#include "C_libs.h"

#define MAXN 999

void initialize_locale() {
	setlocale(LC_ALL, "zh_CN.UTF-8");
	SetConsoleOutputCP(936);
}

void input_int(const char *prompt, int *value) {
	printf("%s\n", prompt);
	scanf("%d", value);
}

void input(const char *prompt, char *value) {
	printf("%s\n", prompt);
	*value = getchar();
	while (getchar() != '\n');
}

void input_float(const char *prompt, float *value) {
	printf("%s\n", prompt);
	scanf("%f", value);
	while (getchar() != '\n');
}

void logger(int type, const char* message) {
	switch (type) {
	case 1:
		system("color 06");
		printf("[Warning] %s\n", message);
		Sleep(1500);
		break;
	case 2:
		system("color 04");
		printf("[Error] %s\n", message);
		Sleep(3000);
		break;
	default:
		break;
	}
}

void display_file_content(const char *filename, const char *error_message) {
	FILE *file = fopen(filename, "r");
	char buffer[MAXN];
	
	if (file == NULL) {
		logger(2, error_message);
		Sleep(2500);
		exit(0);
	}
	
	setlocale(LC_ALL, "zh_CN.UTF-8");
	SetConsoleOutputCP(65001);
	
	while (fgets(buffer, sizeof(buffer), file) != NULL) printf("%s", buffer);
	
	fclose(file);
}

#endif
