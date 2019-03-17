// ConsoleApplication3.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct stack {
	char v1[100][8];//儲存每個row
};
typedef struct earlist {
	int r1[100];
};

int combine(char a, char b) {
	int a2 = a - '0';
	int b2 = b - '0';
	int result = 10 * a2 + b2;
	return result;
}

int main()
{
	int time;
	int counter;
	int counter2;
	stack st1;
	
	char input[8];//ex:12131415
	scanf("%d", &time);
    fgets(input, 8, stdin);

	for (int i = 0;i <time;i++) {
		fgets(input, 10, stdin); //每一次的輸入
		int a = strlen(input);
		input[a - 1] = ' '; //尾端加上' '
		counter = 0;
		counter2 = 0;
		for (int j = 0;j < a;j++) {

			if (input[j] == ' ') {
				if (j - counter >= 2) {
					st1.v1[i][counter2] = combine(input[j - 2], input[j - 1]);
					counter2++;
					counter = j + 1;
				}
				else {
					st1.v1[i][counter2] = input[j - 1] - '0';
					counter2++;
					counter = j + 1;
				}
			}
		}
	}//收取資料結束
	stack st2;
	for (int i = 0;i < time;i++) {
		for (int j = 0;j <= time;j++) {
			if (st1.v1[i][0] == j) {
				st2.v1[j][0] = st1.v1[i][0];
				st2.v1[j][1] = st1.v1[i][1];
				st2.v1[j][2] = st1.v1[i][2];
				st2.v1[j][3] = st1.v1[i][3];
			}
		}
		
	}
	////////////////////////////////////////////////////////////////////////////////////
	earlist ee;
	ee.r1[0] = 0;
	int jerry;//記錄是否有兩個輸入
	int compare[100][2];
	int temp;
	int choose;
	int counter3 = 0;
	for (int i = 0;i < time;i++) {
		jerry = 0;
		for (int j = 0;j <= time;j++) {
			if (i== st2.v1[j][2]) {
				jerry++;
				compare[jerry - 1][0] = st2.v1[j][3];
				compare[jerry - 1][1] = st2.v1[j][1];
			}
			
		}
		if (jerry == 1) {
			ee.r1[i] = compare[jerry - 1][0]+ee.r1[compare[jerry-1][1]];
			counter3++;
		}
		else if (jerry > 1) {
			temp = 0;
			choose = 0;
			for (int k = 0;k < jerry;k++) {
				temp = compare[k][0]+ee.r1[compare[k][1]];
				if (temp > choose) {
					choose = temp;
				}
			}
			ee.r1[i] = choose;
			counter3++;
		}
	}//ee完成
	////////////////////////////////////////////////////////////////////////////////////
	int le[100];
	le[counter3] = ee.r1[counter3];
	for (int i = counter3;i > 0;i--) {
		for (int j = (i - 1);j >= 0;j--) {
			for (int k =(time);k >= 0;k--){
				if (st2.v1[k][2] == i && st2.v1[k][1] == j) {//i是目的點  j是出發點
					le[j] = le[i] - st2.v1[k][3];
				}
			}
		}
	}

	int e[100];
	e[0] = 0;
	for (int i = 1;i <=time;i++) {
		e[i] = ee.r1[st2.v1[i][1]];
	}

	int l[100];
	l[time] = le[counter3];
	for (int i = time;i >= 0;i--) {
		l[i] = le[st2.v1[i][2]] - st2.v1[i][3];
	}
	int ln[100];
	for (int i = 0;i <= time;i++) {
		ln[i] = l[i] - e[i];
	}

	printf("act.      e      l      slack      critical\n");
	for (int i = 1;i <= time;i++) {
		printf("%d      ", i);
		printf("%d      ", e[i]);
		printf("%d      ", l[i]);
		printf("%d      ", ln[i]);
		if (ln[i] == 0)
			printf("Yes      \n");
		else
			printf("No       \n");
	}
	system("pause");
    return 0;
}


