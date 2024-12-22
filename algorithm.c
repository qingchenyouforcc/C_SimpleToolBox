#include "algorithm.h"

static void show_array(int array[], int n) {
	for (int i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

static void swap(int *px, int *py) {
	int t;
	t = *px;
	*px = *py;
	*py =t;
}

static void bubble(int a[], int n) {
	int i, j;
	int swapped;
	
	for(i=0; i<n-1; i++) { 
		swapped = 0;
		for(j=0; j<n-1-i; j++) {
			system("cls");
			if (a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
				swapped = 1;
			}
			printf("过程如下:\n");
			printf("i: %d\n", i);
			printf("j: %d\n", j);
			printf("a[j]: %d\n", a[j]);
			printf("a[j+1]: %d\n", a[j+1]);
			show_array(a, n);
			Sleep(300);
		}
		if(!swapped) {
			printf("提前完成排序!\n");
			break;
		}
	}
}

static void array_generate(int *array, int size) {
	int a = 0;
	for(int i=1;i<=size;i++) {
		array[a++] = i; 
	}
}

void selection_sort() {
	int i, index, k, n, temp;
	int a[MAXN];
	
	printf("输入n: ");
	scanf("%d", &n);
	printf("输入%d个整数: ", n);
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	printf("\n");
	//选择排序
	for(k=0; k<n-1; k++) {
		system("cls");
		printf("过程如下:\n");
		index = k;printf("index: %d\n", index);	
		//寻找最小值所在下标
		for(i=k+1; i<n; i++) {
			printf("i: %d\n", i);
			if(a[i] < a[index]) {
				index = i;
			} else system("cls");
			printf("过程如下:\n");
		}
		//将最小元素与下标为k的元素交换
		printf("index: %d\n", index);	
		temp = a[index];printf("temp: %d\n", temp);
		a[index] = a[k];printf("a[index]: %d\n", a[index]);
		a[k] = temp;printf("a[k]: %d\n", a[k]);
		show_array(a, n);
		Sleep(700);
	}
	printf("排序后：");
	show_array(a, n);
	
	printf("\n");
	Sleep(5000);
}

void Dichotomy_lookup() {
	int low, high, mid, n, size, x;
	int a[MAXN] = {0};
	
	printf("输入数组大小: ");
	scanf("%d", &size);
	array_generate(a, size);
	n = size;
	
	printf("输入要查找的数: ");
	scanf("%d", &x);
	
	low = 0; high = n-1;
	while(low <= high) {
		system("cls");
		mid = (high+low)/2; printf("mid: %d\n", mid);
		if(x == a[mid]) {
			break;
		} else if(x < a[mid]) {
			high = mid - 1; printf("high: %d\n", high);
		} else {
			low = mid + 1; printf("low: %d\n", low);
		}
		Sleep(1000);
	}
	if(low <= high) {
		printf("内容位于数组下标: %d\n", mid);
	} else {
		printf("没有找到内容\n");
	}
	
	Sleep(5000);
}

void bubble_sort() {
	int i, n, a[MAXN];
	
	printf("输入n:");
	scanf("%d", &n);
	printf("输入%d个整数:", n);
	
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	bubble(a, n);
	printf("排序后:");
	show_array(a, n);
	
	Sleep(5000);
}
