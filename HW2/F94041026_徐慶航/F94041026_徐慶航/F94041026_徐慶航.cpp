// F94041026_�}�y��.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <iomanip> 
#include <time.h>
using namespace std;

int result1[15][15]; //�Ĥ@�p�D��result�x�}
int result2[39][19]; //�ĤG�p�D��result�x�}
int k;int m;		 //k�Mm�����ѼƦr���ܼ�
int imove[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int jmove[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int position1[2] = { 10,10 }; //�Ĥ@�p�D����e(x,y)
int position2[2] = { 1,1 };   //�ĤG�p�D����e(x,y)
int check1(int result1[15][15])   //�P�_�Ĥ@�p�D�O�_����
{
	for (int i = 0;i < 15;i++)
	{
		for (int j = 0;j < 15;j++)
		{
			if (result1[i][j] == 0)
				return 1;
		}
	}
	return 0;
}
int check2(int result2[39][19])  //�P�_�ĤG�p�D�O�_����
{
	for (int i = 0;i < 39;i++)
	{
		for (int j = 0;j < 19;j++)
		{
			if (result2[i][j] == 0)
				return 1;
		}
	}
	return 0;
}
int main()
{
	srand(time(NULL));
	result1[15][15] = 1; //���l��m�����L���ƥ��]��1
	int count1 = 0; //�Ĥ@�p�D����B�ƪ�l��
	int position11[2] = {position1[0],position1[1]}; //�Ȧs��

			while (check1(result1) && count1<=50000)
			{
				

				position11[0] = position1[0]; position11[1] = position1[1]; //���U��(x,y)�s��Ȧs��
				k = rand() % 8;
				position1[0] = position1[0] + imove[k];
				position1[1] = position1[1] + jmove[k];
				if (position1[0] < 0 || position1[0]>15 || position1[1] < 0 || position1[1]>15) //�p�G�W�X�F�ɽu
				{
					position1[0] = position11[0]; position1[1] = position11[1]; //�Ȧs�Ȫ����ର��U��(x,y)�A����Ʊ����S���o��
				}
				else
				{
					result1[position1[0]][position1[1]]++; //�S�W�X�ɽu���ܴN�⨺�I(x,y)���B��+1
					count1++; //����B��+1
				}
			}

			printf("Experiment 1:\n");
			printf("Total moves: %d", count1);
			for (int i = 0;i < 15;i++)
			{
				cout << "\n";
				for (int j = 0;j < 15;j++)
				{
					cout << setw(3)<<result1[i][j] << " ";
				}
			}



///////////////////////////////////////////////////////////////////////////////////////�ĤG�p�D
			cout << "\n";
			result2[39][19] = 1;
			int count2 = 0;
			int position22[2] = { position2[0],position2[1] };

			while (check2(result2) && count2 <= 50000)
			{


				position22[0] = position2[0]; position22[1] = position2[1];
				k = rand() % 8;
				position2[0] = position2[0] + imove[k];
				position2[1] = position2[1] + jmove[k];
				if (position2[0] < 0 || position2[0]>39 || position2[1] < 0 || position2[1]>39)
				{
					position2[0] = position22[0]; position2[1] = position22[1];
				}
				else
				{
					result2[position2[0]][position2[1]]++;
					count2++;
				}
			}

			printf("Experiment 2:\n");
			printf("Total moves: %d", count2);
			for (int i = 0;i < 39;i++)
			{
				cout << "\n";
				for (int j = 0;j < 19;j++)
				{
					cout << setw(3) << result2[i][j] << " ";
				}
			}

			printf("\n");




			system("pause");
			return 0;
	}
	
	
/*
	if (position1[0] == 0 && position1[1] == 0) //�쥪�W��F
				{
					m = rand() % 3 + 3;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 0 && position1[1] == 15) //��k�W��F
				{
					m = rand() % 3 + 5;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 15 && position1[1] == 15) //��k�U��F
				{
					int n[3] = { 0,1,7 };
					m = rand() % 3;
					position1[0] = position1[0] + imove[n[m]];
					position1[1] = position1[1] + jmove[n[m]];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 15 && position1[1] == 0) //�쥪�U��F
				{
					m = rand() % 3 + 1;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 0) //�쥪��
				{
					m = rand() % 5 + 1;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[1] == 0) //��W��
				{
					m = rand() % 5 + 3;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 15) //��k��
				{
					int n[5] = { 0,1,5,6,7 };
					m = rand() % 5;
					position1[0] = position1[0] + imove[n[m]];
					position1[1] = position1[1] + jmove[n[m]];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[1] == 15) //��U��
				{
					int n[5] = { 0,1,2,3,7 };
					m = rand() % 5;
					position1[0] = position1[0] + imove[n[m]];
					position1[1] = position1[1] + jmove[n[m]];
					result1[position1[0]][position1[1]]++;
				}
				else
				{
					k = rand() % 8;
					position1[0] = position1[0] + imove[k];
					position1[1] = position1[1] + jmove[k];
					result1[position1[0]][position1[1]]++;
				}
				count1 = count1 + 1;
	*/