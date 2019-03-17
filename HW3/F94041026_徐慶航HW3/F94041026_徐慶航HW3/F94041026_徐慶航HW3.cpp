// ConsoleApplication1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "string.h"
#include "math.h"
#include "time.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

typedef struct deque {
	int value[101];
	int front = 51;
	int back = 50;
};

void show(deque &deque1) {
	using namespace std;
	for (int i = deque1.front; i <= deque1.back; i++) {
		cout << deque1.value[i] << " ";
	}
}

void push_front(deque &deque1, int item) {
	deque1.front -= 1;
	deque1.value[deque1.front] = item;
}

void push_back(deque &deque1, int item) {
	deque1.back += 1;
	deque1.value[deque1.back] = item;
}

void pop_front(deque &deque1) {
	deque1.value[deque1.front] = NULL;
	deque1.front += 1;
}

void pop_back(deque &deque1) {
	deque1.value[deque1.back] = NULL;
	deque1.back -= 1;
}

int main()
{

	char move1[] = "push_front";
	char move2[] = "push_back";
	char move3[] = "pop_front";
	char move4[] = "pop_back";
	char move5[] = "show";
	int item;
	int order = 0;
	int terminal;
	char word[15];
	char input[15];
	int position;
	deque deque1;

	for (int m = 0; m < 50;m++)
	{
		terminal = 0;
		position = 0;
		fgets(input, 15, stdin);



		for (int i = 1;i < strlen(input);i++) {
			if (input[i] == ' ')
				position = i; //從前面屬過來第幾個是空白鍵(從0開始)
		}
		if (position != 0) {
			for (int i = position + 1;i < strlen(input) - 1;i++) {
				int testing = input[i] - '0'; //轉成int
				if (testing < 10 && testing >= 0) { //確保為數字
					item = testing;
				}
				order++;
			}

			for (int i = 0;i < position;i++) {
				word[i] = input[i];
				terminal = i + 1;
			}
			word[terminal] = '\0';
		}

		if (position == 0)
		{
			for (int i = 0;i <strlen(input);i++) {
				word[i] = input[i];
				terminal = i + 1;
			}
			char shit1 = word[terminal];
			char shit2 = word[terminal - 1];
			word[terminal - 1] = '\0';
		}
		int test1 = strcmp(word, move1);
		int test2 = strcmp(word, move2);
		int test3 = strcmp(word, move3);
		int test4 = strcmp(word, move4);
		int test5 = strcmp(word, move5);

		if (test1 == 0) {
			//printf("\n");
			//printf("%s\n", move1);
			push_front(deque1, item);
		}
		else if (test2 == 0) {
			//printf("%s\n", move2);
			push_back(deque1, item);
		}
		else if (test3 == 0) {
			//printf("%s\n", move3);
			pop_front(deque1);
		}
		else if (test4 == 0) {
			//printf("%s\n", move4);
			pop_back(deque1);
		}
		else if (test5 == 0) {
			//printf("%s\n", move5);
			show(deque1);
			break;
		}
		else {
			printf("What are you fucking typing?\n");
		}

	}

	system("pause");
	return 0;

}


