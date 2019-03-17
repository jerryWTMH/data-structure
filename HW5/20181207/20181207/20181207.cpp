// 20181206.cpp : ﹚竡北莱ノ祘Α秈翴
//
#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct stack {
	int	v[30];
};

int combine(char a, char b) {
	int a2 = a - '0';
	int b2 = b - '0';
	int result = 10 * a2 + b2;
	return result;
}
int main()
{
	stack st1;
	char input[30];
	fgets(input, 30, stdin);
	int a = strlen(input);
	input[a - 1] = ' ';

	int counter = 0;
	int stack_counter = 1;
	for (int i = 0;i <= a;i++) {
		if (input[i] != ' ') {
			counter++;
		}
		else {
			if (counter >= 2) {
				st1.v[stack_counter] = combine(input[i - 2], input[i - 1]);
				counter = 0;
				stack_counter++;
			}
			else {
				st1.v[stack_counter] = input[i - 1] - '0';
				counter = 0;
				stack_counter++;
			}
		}
	}


	char input2[30];
	fgets(input2, 30, stdin);
	int a2 = strlen(input2);
	input2[a2 - 1] = ' ';

	int change1;
	int change2;
	for (int j = 0;j <a2;j++) {//眔计
		if (input2[j] == ' ') {
			if (j>= 2) {
				change1 = combine(input2[j - 2], input2[j - 1]);
			}
			else 
				change1 = input2[j - 1] - '0';
		}
	}

	int change_position;
	int change_position2;
	for (int i = 1;i < stack_counter;i++) {//传计
		if (st1.v[i] == change1) {
			if (st1.v[i * 2] > st1.v[i * 2 + 1]) {
				st1.v[i] = st1.v[i * 2];
				st1.v[i * 2] = 0;
				change_position = i;
				change_position2 = i * 2;
			}
			else {
				st1.v[i] = st1.v[i * 2 + 1];
				st1.v[i * 2 + 1] = 0;
				change_position = i;
				change_position2 = i * 2 + 1;
			}
		}
	}

	if (st1.v[(change_position+1)*2+1] < st1.v[change_position]) {//传抖
		st1.v[change_position2] = st1.v[(change_position+1)*2+1];
		st1.v[(change_position + 1) * 2 + 1] = ' ';
	}
	else if (st1.v[(change_position+1)*2] > st1.v[change_position]) {
		st1.v[change_position2] = st1.v[(change_position + 1) * 2 ];
		st1.v[(change_position + 1) * 2] = st1.v[(change_position + 1) * 2 + 1];
		st1.v[(change_position + 1) * 2 + 1] = ' ';
	}



	for (int i = 1;st1.v[i]!=' ';i++) {
		cout << st1.v[i];
		cout << ' ';
	}


	system("pause");
	return 0;
}

