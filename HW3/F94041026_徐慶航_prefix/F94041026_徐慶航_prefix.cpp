// prefix.cpp : ﹚竡北莱ノ祘Α秈翴
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "iostream"
using namespace std;
int length = 0;

//typedef struct ppp {
//	
//	char output[30];
//};


int calculate_ten(char ten, char one) {
	int ten2 = ten - '0';
	int one2 = one - '0';
	int result = 10 * ten2 + one2;
	return result;
}


int main()
{
	char input[30];
	char input2[30];
	char number[30];//计 
	char sign[30];//才腹
	char position[30];//计
	int testing;
	int temporary;
	int counter1 = 0; //number[]
	int counter2 = 0; //
	int counter3 = 0;
	int recorder = 0;
	fgets(input, 30, stdin);

	//cout << strlen(input)<<endl;
	for (int i = strlen(input) - 2;i >= 0;i--) {
		input2[strlen(input) - 2 - i] = input[i];
	}
	//cout << strlen(input2);

	/*int shit = strlen(input2);
	cout << shit;*/

	for (int i = 0;i < 30;i++) {
		if (input[i] == ' ') {
			for (int j = recorder;j < i;j++) {
				if ((i - recorder) > 1) {
					position[j] = 100;
				}
				
			}
			recorder = i + 1;
		}

	}
	int count4 = 0;
	for (int i = 0;i < strlen(input) - 1;i++) {
		if (input2[i] != ' ')//衡獶フよ
		{
			temporary = input2[i] - '0';
			
			if (temporary < 10 && temporary >= 0) {//ボ琌计
												   /*length = 0;
												   for (int j = strlen(input2)-i;position[j] == 100;j--) {
												   length++;
												   }*/
				
				if (position[strlen(input) - i-2] > 1) {//ボ琌计
					count4++;
					if (count4 >= 2) {
						number[counter1] = calculate_ten(input2[i], input2[i - 1]);
						counter1++;
						i++;
					}
					
				}
				else { //ボΑ虫计

					number[counter1] = input2[i] - '0';
					counter1++;
				}
			}

			else { //ボ琌才腹	
				sign[counter2] = input2[i];
				if (input2[i] == ')') {
					counter3++;
					testing = counter2;

				}
				else if (input2[i] == '(') {
					counter3--;
					for (int j = testing + 1;j < counter2;j++) {
						number[counter1] = sign[j];
						sign[j] = -100;
						counter1++;
					}
					sign[testing] = -100;
					sign[counter2] = -100;
				}
				else if (input2[i] == '+' || input2[i] == '-') {
					if (counter3 == 0) {
						for (int k = 0;k < counter2;k++) {
							if (sign[k] == '*' || sign[k] == '/') {

								number[counter1] = sign[k];
								sign[k] = -100;
								counter1++;
							}
						}
					}
				}
				else { ; }
				counter2++;
			}
		}
	}
	for (int i = 0;i <counter2;i++) {
		if (sign[i] != -100) {
			cout << sign[i];
			cout << " ";
		}

	}
	for (int j = counter1 - 1;j >= 0;j--) {
		if (number[j] == '+' || number[j] == '-' || number[j] == '*' || number[j] == '/' || number[j] == '(' || number[j] == ')') {
			cout << number[j];
			cout << ' ';
		}
		else {
			cout << int(number[j]);
			cout << ' ';
		}
	}


	system("pause");
	return 0;
}



