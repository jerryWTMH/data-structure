// F94041026_徐慶航.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <iomanip> 
#include <time.h>
using namespace std;

int result1[15][15]; //第一小題的result矩陣
int result2[39][19]; //第二小題的result矩陣
int k;int m;		 //k和m為提供數字的變數
int imove[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int jmove[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int position1[2] = { 10,10 }; //第一小題的當前(x,y)
int position2[2] = { 1,1 };   //第二小題的當前(x,y)
int check1(int result1[15][15])   //判斷第一小題是否結束
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
int check2(int result2[39][19])  //判斷第二小題是否結束
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
	result1[15][15] = 1; //把初始位置的走過次數先設為1
	int count1 = 0; //第一小題全體步數初始化
	int position11[2] = {position1[0],position1[1]}; //暫存值

			while (check1(result1) && count1<=50000)
			{
				

				position11[0] = position1[0]; position11[1] = position1[1]; //把當下的(x,y)存到暫存值
				k = rand() % 8;
				position1[0] = position1[0] + imove[k];
				position1[1] = position1[1] + jmove[k];
				if (position1[0] < 0 || position1[0]>15 || position1[1] < 0 || position1[1]>15) //如果超出了界線
				{
					position1[0] = position11[0]; position1[1] = position11[1]; //暫存值的值轉為當下的(x,y)，什麼事情都沒有發生
				}
				else
				{
					result1[position1[0]][position1[1]]++; //沒超出界線的話就把那點(x,y)的步數+1
					count1++; //全體步數+1
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



///////////////////////////////////////////////////////////////////////////////////////第二小題
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
	if (position1[0] == 0 && position1[1] == 0) //到左上方了
				{
					m = rand() % 3 + 3;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 0 && position1[1] == 15) //到右上方了
				{
					m = rand() % 3 + 5;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 15 && position1[1] == 15) //到右下方了
				{
					int n[3] = { 0,1,7 };
					m = rand() % 3;
					position1[0] = position1[0] + imove[n[m]];
					position1[1] = position1[1] + jmove[n[m]];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 15 && position1[1] == 0) //到左下方了
				{
					m = rand() % 3 + 1;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 0) //到左邊
				{
					m = rand() % 5 + 1;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[1] == 0) //到上面
				{
					m = rand() % 5 + 3;
					position1[0] = position1[0] + imove[m];
					position1[1] = position1[1] + jmove[m];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[0] == 15) //到右邊
				{
					int n[5] = { 0,1,5,6,7 };
					m = rand() % 5;
					position1[0] = position1[0] + imove[n[m]];
					position1[1] = position1[1] + jmove[n[m]];
					result1[position1[0]][position1[1]]++;
				}
				else if (position1[1] == 15) //到下面
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