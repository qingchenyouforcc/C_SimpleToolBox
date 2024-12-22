#ifndef FUNCTION_H
#define FUNCTION_H

#include "C_libs.h"
#include "utils.h"
#define MAXN 999

void show_welcome() {
	printf("(qingchenyou Demo)\n");
	display_file_content("welcome.txt", "Can't find file welcome.txt!!! Initialization failed!");
}

void show_exit() {system("cls");printf("Bye bye~");Sleep(1000);exit(0);}

#endif
