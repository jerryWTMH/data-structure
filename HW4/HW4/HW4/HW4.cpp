// HW4.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "iostream"
using namespace std;

#define MAX_SIZE 50
typedef enum { head, entry }tagfield;
typedef struct matrixNode *matrixPointer;
typedef struct entryNode { int row; int col; int value; };
typedef struct matrixNode { matrixPointer down; matrixPointer right; tagfield tag; 
union {
	matrixPointer next;
	entryNode entry;
}u;
};
matrixPointer hdnode[MAX_SIZE];

void mwrite(matrixPointer node)
{
	/*print out the matrix in row mahor form*/
	int i;
	matrixPointer temp, head = node->right;
	/*matrix dimensions*/
	printf("\n numRows= %d, numCols=%d \n",node->u.entry.row, node->u.entry.col);
	printf("The matrix by row,column, and value: \n\n");
	for (int i = 0;i < node->u.entry.row; i++) {
		/*print out the entries in each row*/
		for (temp = head->right;temp != head;
									temp = temp->right) 
			printf("%5d%5d%5d \n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
			head = head->u.next;/*next row*/
		}
	}

matrixPointer mread(void) {
	int numRows, numCols, numTerms, numHeads, i;
	int row, col, value, currentRow;
	matrixPointer temp, last, node;

	printf("Enter the number of rows, columes and number of nonzero terms: ");
	scanf("%d %d %d", &numRows, &numCols, &numTerms);
	numHeads = (numCols > numRows) ? numCols : numRows;
	/*set up header node for the list of header nodes*/
	node = new matrixNode; node->tag = entry;
	node->u.entry.row = numRows;
	node->u.entry.col = numCols;
	
	if (!numHeads) node->right = node;
	else{ /*initialize the header nodes*/
	for (int i = 0;i < numHeads;i++) {
		temp = (matrixNode*)malloc(sizeof(matrixNode));
		hdnode[i] = temp; hdnode[i]->tag = head;
		hdnode[i]->right = temp; hdnode[i]->u.next = temp;
		}
	currentRow = 0;
	last = hdnode[0];/*last node in current row*/
	for (int i = 0;i < numTerms;i++) {
		printf("Enter row, colummn and value: ");
		scanf("%d%d%d", &row, &col, &value);
		if (row > currentRow) { /*close current row*/
		last->right = hdnode[currentRow];
		currentRow = row;last = hdnode[row];
		}
		temp = (matrixNode*)malloc(sizeof(matrixNode));
		temp->tag = entry; temp->u.entry.row = row;
		temp->u.entry.col = col;
		temp->u.entry.value = value;
		last->right = temp;/*link into row list*/
		last = temp;
		/* link into column list*/
		hdnode[col]->u.next->down = temp;
		hdnode[col]->u.next = temp;
	}
	/*close last row*/
	last->right = hdnode[currentRow];
	/*close all column lists*/
	for (int i = 0;i < numCols;i++)
		hdnode[i]->u.next->down = hdnode[i];
	hdnode[numHeads - 1]->u.next = node;
	node->right = hdnode[0];
  }
  return node;
}


int main()
{
	matrixPointer a, b;
	a = mread();
	b = mread();
	mwrite(a);

	system("pause");
    return 0;
}

