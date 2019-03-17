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

int combine(char a,char b) {
	int a2 = a - '0';
	int b2 = b - '0';
	int result = 10 * a2 + b2;
	return result;
}
int main()
{
	stack st1;
	char input[30];
	fgets(input,30, stdin);
	int a=strlen(input);
	input[a - 1] = ' ';

	int counter = 0;
	int stack_counter = 1;
	for (int i = 0;i <= a;i++) {
		if (input[i] != ' ') {
			counter++;
		}
		else {
			if (counter >= 2) {
				st1.v[stack_counter]=combine(input[i - 2], input[i - 1]);				
				counter = 0;
				stack_counter++;
			}
			else{
				st1.v[stack_counter] =input[i - 1]-'0';
				counter = 0;
				stack_counter++;
			}
		}
	}
	

	char input2[30];
	fgets(input2, 30, stdin);
	int a2 = strlen(input2);
	input2[a2 - 1] = ' ';

	int counter2 = 0;
	int change1;
	int change2;
	counter = 0;
	for (int j = 0;j <a2;j++) {//眔计
		if (input2[j] == ' '&& counter2==0) {
			if (j - counter >= 2) {
				change1 = combine(input2[j - 2], input2[j - 1]);
				counter = j+1;
				counter2++;
			}
			else {
				change1 = input2[j - 1] - '0';
				counter = j+1;
				counter2++;
			}
				
		}
		else if (input2[j] == ' '&& counter2 == 1) {
			if (j - counter >= 2) {
				change2 = combine(input2[j - 2], input2[j - 1]);
			}
			else {
				change2 = int(input2[j - 1] - '0');
			}
		}
	}
	
	int change_position;
	for (int i = 1;i < stack_counter;i++) {//传计
		if (st1.v[i] == change1) {
			st1.v[i] = change2;
			change_position = i;
		}
	}

	if (st1.v[(change_position ) / 2] < st1.v[change_position]) {//传抖
			int store = st1.v[(change_position) / 2];
			st1.v[(change_position) / 2] = st1.v[change_position];
			st1.v[change_position] = store;
		}
	else if (st1.v[(change_position) / 2] > st1.v[change_position]) {
		if (st1.v[(change_position * 2)] > st1.v[change_position]) {
			int store = st1.v[(change_position)*2];
			st1.v[(change_position * 2)] = st1.v[change_position];
			st1.v[change_position] = store;
		}
		else if (st1.v[(change_position * 2) + 1] > st1.v[change_position]) {
			int store = st1.v[(change_position) * 2 + 1];
			st1.v[(change_position * 2 + 1)] = st1.v[change_position];
			st1.v[change_position] = store;
		}
	}

	
	
	for (int i = 1;i < stack_counter;i++) {
		cout << st1.v[i];
		cout << ' ';
	}
	

	system("pause");
    return 0;
}

