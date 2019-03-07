// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main_menu(void);                                         //菜单函数
void stu_info_input(void);                                    //信息输入函数
void stu_info_show(void);                                     //信息显示函数
void stu_info_sort(void);                                     //平均分排序             
void stu_info_search_name(void);                              //根据姓名查找
void stu_info_search_number(void);                            //根据学号查找
void stu_info_save(void);                                     //信息保存
void stu_info_input_ordered(void);                            //顺序表插入 
void input_done(void);

//主函数
int main()
{
	printf("Welcome!\n");
	main_menu();
	return 0;
}

//结构体定义
typedef struct
{
	char id[20];
	char name[2000];
	int score[3];
	double ave;
}STUDENT;
STUDENT stu[5000];

int count = 0;

//菜单函数
void main_menu()
{
	printf("Please input your choose:\n");
	printf("1\ Add stu_info.\n");
	printf("2\ Search stu_info by stu_number.\n");
	printf("3\ Search stu_info by stu_name.\n");
	printf("4\ Show all stu_info.\n");
	printf("5\ Save all stu_info.\n");
	printf("6\ Sort stu_info.\n");
	printf("7\ Input stu_info by order.\n");
	printf("Input your choose:\n");
	int chs;
	scanf_s("%d", &chs);
	switch (chs)
	{
	case 1:stu_info_input(); main_menu(); break;
	case 2:stu_info_search_number(); main_menu(); break;
	case 3:stu_info_search_name(); main_menu(); break;
	case 4:stu_info_show(); printf("\n"); main_menu(); break;
	case 5:stu_info_save(); main_menu(); break;
	case 6:stu_info_sort(); main_menu(); break;
	case 7:stu_info_input_ordered(); main_menu(); break;
	default:printf("Please input the correct number!"); main_menu();
	}
}

void input_done()
{
	stu_info_sort();
}

//学生信息输入函数
void stu_info_input(void)
{
	printf("Please input stu_ID:");
	scanf_s("%s", &stu[count].id, sizeof(&stu[count].id));
	printf("Please input stu_name:");
	scanf_s("%s", &stu[count].name, sizeof(stu[count].name));
	printf("Please input stu_C++ score:");
	scanf_s("%d", &stu[count].score[0]);
	printf("Please input stu_PYTHON score:");
	scanf_s("%d", &stu[count].score[1]);
	printf("Please input stu_JAVA score:");
	scanf_s("%d", &stu[count].score[2]);
	stu[count].ave = (stu[count].score[0] + stu[count].score[1] + stu[count].score[2])/3;
	count++;
	printf("Sucessfully input!");
	printf("\n");
}

//学生信息打印
void stu_info_show(void)
{
	printf("ID\tName\t\tScore_CPP\tScore_PYTHON\tScore_JAVA\t\n");
	for (int m = 0; m < count; m++)
	{
		printf("%s\t%s\t\t%d\t%d\t\t%d\t%f\n", stu[m].id, stu[m].name, stu[m].score[0], stu[m].score[1], stu[m].score[2],stu[m].ave);
	}
	printf("Successfully display!");
	printf("\n");
}

//学生平均分排序
void stu_info_sort(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j < count - 1; j++)
		for (i = j + 1; i < count; i++)
			if (stu[i].ave < stu[j].ave)
			{
				t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
			}
}

//按姓名查找
void stu_info_search_name(void)
{
	printf("Please input the name you want:");
	char name_want[20];
	scanf_s("%s", &name_want,sizeof(name_want));
	int match = 0;
	for (int i = 0; i <= count; i++)
	{
		if (strcmp(stu[i].name, name_want)==0)
		{
			match++;
			printf("ID\tName\t\tScore_CPP\tScore_PYTHON\tScore_JAVA\t\n");
			printf("%s\t%s\t\t%d\t%d\t\t%d\t%f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].ave);
		}
	}
	if (match == 0)
	{
		printf("Not found!");
	}
	printf("\n");
}

//按学号查找
void stu_info_search_number(void)
{
	printf("Please input the number you want:");
	char number_want[20];
	scanf_s("%s", &number_want, sizeof(number_want));
	int match = 0;
	for (int i = 0; i <= count; i++)
	{
		if (strcmp(stu[i].id, number_want) == 0)
		{
			match++;
			printf("ID\tName\t\tScore_CPP\tScore_PYTHON\tScore_JAVA\t\n");
			printf("%s\t%s\t\t%d\t%d\t\t%d\t%f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].ave);
		}
	}
	if (match == 0)
	{
		printf("Not found!");
	}
	printf("\n");
}

//文件保存
void stu_info_save(void)
{
	FILE* fp;
	int i, d;
	fp = fopen ("D://test.txt", "w");
	if (fp == NULL)
	{
		printf("File cannot open!");
		exit(0);
	}
	else
	{
		for (i = 0; i <= count; i++)
		{
			fprintf_s(fp, "%s\t%s\t\t%d\t%d\t\t%d\t%f\n", stu[i].id, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].ave);
		}
		printf("Successfully saved!");
		printf("\n");
	}
}

//顺序表插入学生信息
	void stu_info_input_ordered(void)
	{
		stu_info_sort();
		printf("Please input stu_ID:");
		scanf_s("%s", &stu[count].id, sizeof(&stu[count].id));
		printf("Please input stu_name:");
		scanf_s("%s", &stu[count].name, sizeof(stu[count].name));
		printf("Please input stu_C++ score:");
		scanf_s("%d", &stu[count].score[0]);
		printf("Please input stu_PYTHON score:");
		scanf_s("%d", &stu[count].score[1]);
		printf("Please input stu_JAVA score:");
		scanf_s("%d", &stu[count].score[2]);
		stu[count].ave = (stu[count].score[0] + stu[count].score[1] + stu[count].score[2]) / 3;
		count++;
		STUDENT temp;
		temp = stu[count-1];
		//printf("%s\t%s\t\t%d\t%d\t\t%d\t%f\n", stu[count-1].id, stu[count-1].name, stu[count-1].score[0], stu[count-1].score[1], stu[count-1].score[2], stu[count-1].ave);
		int m;
		for (m = 1; m <= count - 2; m++)
		{
			if (stu[count-1].ave >= stu[m - 1].ave && stu[count-1].ave < stu[m].ave)
			{
				break;
			}
		}
		int n;
		for (n = count-1; n >=m+1; n--)
		{
			stu[n] = stu[n - 1];
		}
		stu[m] = temp;
	}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
