// F94041026_�}�y��_HW1.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "iostream"
using namespace std;
typedef struct stack {
	char v1[100][6]; //�x�sedge
	int  v2[100];//�x�s�O�_���Q�ϥιL ��l�Ƭ�0
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
	int counter; //�P�_�ť��䪺
	int counter2; //�O���{�binput2����m
	stack st1;
	scanf("%d", &time);
	if (time > 100) {
		time = 0;
		printf("N>100�F!�Э��s��J\n");
		scanf("%d\n", &time);
	}
	char input[10]; //�x�s�ϥΪ̪���J
	fgets(input, 10, stdin);
	//fgets(input, 10, stdin);
	for (int i = 0;i <time;i++) {
		fgets(input, 10, stdin); //�C�@������J
		int a = strlen(input);
		input[a - 1] = ' '; //���ݥ[�W' '
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
	}//������Ƶ���
	 //////////////////////////////////////////////////////////////////////////////////////////////////////
	int counter3 = 0; //vertex��
	int row1;
	int row2;
	int value1;
	int value2;
	int total_times = 0; //while����h�֦�
	int record1;
	int record2;
	int record3[100] = { 0 }; //�O��vertex�Q�ϥΪ�����
	int edge_counter = 0;
	int round = 0;//�O���ĴX��
	int record4[100][2];
	int num_vertex = 0;
	int ending = 1;//while loop����������

	while (ending) {//�o��ݭn�A��
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
			else if (round != 0) {//�ĤG���H��
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

				if ((record3[record1] + 1) == 2) {//�T�wrecord1�O�w�g�X�{�L��vertex
					record3[record1]++;//record1�X�{�L�⦸�F

					if (record3[record2] + 1 == 2) {//��ӳ��ܦ������I���ɭ�
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
						for (int j = 0;j < time;j++) {//��Jrecord4
							if (record4[j][0] == record1)
								record4[j][0] = record2;
							else if (record4[j][1] == record1)
								record4[j][1] = record2;
						}
						record3[record2]++;
					}
				}
				else if ((record3[record2] + 1) == 2) {//�T�wrecord2�O�w�g�X�{�L��vertex
					record3[record2]++;//record2�X�{�L�⦸�F

					if (record3[record1] + 1 == 2) {//��ӳ��ܦ������I���ɭ�
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
				else { //�Ĥ@���A��
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
			counter3 = 0;//�@������
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
	}//while������

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

