// F94041026_徐慶航_HW1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct stack {
	char v1[100][6]; //儲存edge
	int  v2[100];//儲存是否有被使用過 初始化為0
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
	int change;
	int counter; //判斷空白鍵的
	int counter2; //記錄現在input2的位置
	stack st1;
	scanf("%d", &time);
	if (time > 100) {
		time = 0;
		printf("N>100了!請重新輸入\n");
		scanf("%d\n", &time);
	}
	char input[10]; //儲存使用者的輸入
	fgets(input, 10, stdin);
	//fgets(input, 10, stdin);
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
		st1.v2[i] = 0;
	}//收取資料結束
	 //////////////////////////////////////////////////////////////////////////////////////////////////////
	int counter3 = 0; //vertex值
	int row1;
	int row2;
	int value1;
	int value2;
	int total_times = 0; //while執行多少次
	int record1;
	int record2;
	int record3[100] = { 0 }; //記錄vertex被使用的次數
	int edge_counter = 0;
	int round = 0;//記錄第幾輪
	int record4[100][2];
	int num_vertex = 0;
	int ending = 1;//while loop的結束條件

	while (ending) {//這邊需要再改
		value1 = 0;
		value2 = 1000;
		record1 = 0;
		record2 = 0;
		if (total_times < time) {

			if (round == 0) {
				for (int i = 0;i < 100;i++) {
					if (st1.v1[i][0] == counter3 || st1.v1[i][1] == counter3) {
						if (st1.v2[i] == 0 && record3[total_times] == 0) {
							row1 = i;
							value1 = int(st1.v1[i][2]);
							if (value1 < value2) {
								row2 = row1;
								value2 = value1;
								record1 = st1.v1[i][0];
								record2 = st1.v1[i][1];
							}
						}
					}
				}
			}
			else if (round != 0) {//第二輪以後
				for (int i = 0;i < time;i++) {
					if (st1.v1[i][0] == record4[counter3][0] || st1.v1[i][1] == record4[counter3][0] || st1.v1[i][0] == record4[counter3][1] || st1.v1[i][1] == record4[counter3][1])
						//if(record3[st1.v1[i][0]] != 2 || record3[st1.v1[i][1]] != 2)
						if (st1.v2[i] == 0) {
							row1 = i;
							value1 = int(st1.v1[i][2]);
							if (value1 <= value2) {
								row2 = row1;
								value2 = value1;
								record1 = st1.v1[i][0];
								record2 = st1.v1[i][1];
							}
						}
				}
			}
			if (value2 != 1000) {
				st1.v2[row2] = 1;

				if ((record3[record1] + 1) == 2) {//確定record1是已經出現過的vertex
					record3[record1]++;//record1出現過兩次了

					if (record3[record2] + 1 == 2) {//兩個都變成中間點的時候
						int var1;
						int var2;
						int position1;
						int position2;
						for (int k = 0;k < edge_counter;k++) {
							if (record4[k][0] == record1) {
								var1 = record4[k][1];
								position1 = k;
							}
							if (record4[k][1] == record1) {
								var1 = record4[k][0];
								position1 = k;
							}
							if (record4[k][0] == record2) {
								var2 = record4[k][1];
								position2 = k;
							}
							if (record4[k][1] == record2) {
								var2 = record4[k][0];
								position2 = k;
							}
						}
						if (position1 < position2) {//comparison
							record4[position1][0] = var1;
							record4[position1][1] = var2;
							record4[position2][0] = -52;
							record4[position2][1] = -52;
						}
						else {
							record4[position2][0] = var1;
							record4[position2][1] = var2;
							record4[position1][0] = -52;
							record4[position1][1] = -52;
						}
						record3[record2]++;
					}
					else {
						for (int j = 0;j < time;j++) {//填入record4
							if (record4[j][0] == record1)
								record4[j][0] = record2;
							else if (record4[j][1] == record1)
								record4[j][1] = record2;
						}
						record3[record2]++;
					}
				}
				else if ((record3[record2] + 1) == 2) {//確定record2是已經出現過的vertex
					record3[record2]++;//record2出現過兩次了

					if (record3[record1] + 1 == 2) {//兩個都變成中間點的時候
						int var1;
						int var2;
						int position1;
						int position2;
						for (int k = 0;k < edge_counter;k++) {
							if (record4[k][0] == record1) {
								var1 = record4[k][1];
								position1 = k;
							}
							if (record4[k][1] == record1) {
								var1 = record4[k][0];
								position1 = k;
							}
							if (record4[k][0] == record2) {
								var2 = record4[k][1];
								position2 = k;
							}
							if (record4[k][1] == record2) {
								var2 = record4[k][0];
								position2 = k;
							}
						}
						if (position1 < position2) {//comparison
							record4[position1][0] = var1;
							record4[position1][1] = var2;
							record4[position2][0] = -52;
							record4[position2][1] = -52;
						}
						else {
							record4[position2][0] = var1;
							record4[position2][1] = var2;
							record4[position1][0] = -52;
							record4[position1][1] = -52;
						}
						record3[record1]++;
					}
					else {
						for (int j = 0;j < time;j++) {
							if (record4[j][0] == record2)
								record4[j][0] = record1;
							else if (record4[j][1] == record2)
								record4[j][1] = record1;
						}
						record3[record1]++;
					}

				}
				else { //第一輪適用
					record3[record1]++;
					record3[record2]++;
					record4[edge_counter][0] = record1;
					record4[edge_counter][1] = record2;
				}
				edge_counter++;

			}
			total_times++;
			counter3++;
		}

		else {
			total_times = 0;
			counter3 = 0;//一輪結束
			if (round == 0) {
				for (int k = 0;k < 100;k++) {
					if (record3[k] != 0) {
						num_vertex++;
					}
				}
			}

			round++;
		}
		if (edge_counter + 1 == num_vertex) {
			ending = 0;
		}
	}//while的尾巴

	printf("Sollin's Output:\n");

	for (int i = 0;i < time;i++) {
		if (st1.v2[i] == 1) {
			for (int j = 0;j < 6;j++) {
				if (st1.v1[i][j] >= 0) {
					printf("%d ", st1.v1[i][j]);
				}
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}

