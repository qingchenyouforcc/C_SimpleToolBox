#include "C_libs.h"
#include "utils.h"
#include "function.h"
#include "tool.h"
#include "algorithm.h"
#define MAXN 999
#define COLOR_ALGORITHM "02"
#define COLOR_TOOL "70"
#define COLOR_DEFAULT "07"
#define COLOR_ERROR "04"
#define COLOR_WARNING "06"

void display_main_menu() {
	printf("主菜单\n");
	printf("[0] 退出\n");
	printf("[1] 算法演示\n");
	printf("[2] 实用工具\n");
}

void handle_algorithm_menu() {
	int choice;
	system("cls");
	system("color 02");
	display_file_content("algorithm.txt", "Can't find file algorithm.txt!!! Initialization failed!");
	scanf("%d", &choice);
	
	system("cls");
	initialize_locale();
	switch (choice) {
	case 0:
		break;
	case 1:
		selection_sort();
		break;
	case 2:
		Dichotomy_lookup();
		break;
	case 3:
		bubble_sort();
		break;
	default:
		system("cls");
		logger(1, "Can't find this item!\n");
		break;
	}
}

void handle_tool_menu() {
	int choice;
	system("cls");
	system("color 70");
	display_file_content("smalltool.txt", "Can't find file smalltool.txt!!! Initialization failed!");
	scanf("%d", &choice);
	
	system("cls");
	initialize_locale();
	switch (choice) {
	case 0:
		break;
	case 1:
		de_head_poem();
		break;
	case 2:
		pw_gen();
		break;
	default:
		system("cls");
		logger(1, "Can't find this item!\n");
		Sleep(1500);
		break;
	}
}

int main(int argc, char *argv[]) {
	int is_exit, choice=0;
	boolean main_menu=true;
	
	// 初始化语言环境
	initialize_locale();
	
	show_welcome();
	scanf("%d", &is_exit);
	if (is_exit == 0) show_exit();
	
	while (main_menu) {
		fflush(stdin);
		system("color 07");
		system("cls");
		
		SetConsoleOutputCP(936);
		
		display_main_menu();
		scanf("%d", &choice);
		
		switch (choice) {
		case 0:
			show_exit();
		case 1:
			handle_algorithm_menu();
			break;
		case 2:
			handle_tool_menu();
			break;
		default:
			system("cls");
			logger(2, "Can't find this item!\n");
			main_menu = true;
			break;
		}
		
		main_menu = (choice != 0);
	}
	
	return 0;
}
