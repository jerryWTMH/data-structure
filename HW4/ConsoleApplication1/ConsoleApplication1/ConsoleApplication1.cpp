// hw4.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#define MAX_SIZE 50
typedef enum { head, entry } tagfield;
typedef struct matrixNode *matrixPointer;
typedef struct entryNode {
	int row;
	int col;
	int value;
};
typedef struct matrixNode {
	matrixPointer down;
	matrixPointer right;
	tagfield tag;
	union {
		matrixPointer next;
		entryNode entry;
	} u;
};
matrixPointer hdnode[MAX_SIZE];

matrixPointer mread(void)
{
	int numRows, numCols, numTerms, numHeads, i;
	int row, col, value, currentRow;
	matrixPointer temp, last, node;
	printf("Enter the number of rows, columns and number of nonzero terms: ");
	scanf("%d%d%d", &numRows, &numCols, &numTerms);
	numHeads = (numCols > numRows) ? numCols : numRows;
	node = new matrixNode; node->tag = entry;
	node->u.entry.row = numRows;
	node->u.entry.col = numCols;

	if (!numHeads) node->right = node;
	else {
		for (i = 0; i < numHeads; i++) {
			temp = (matrixNode*)malloc(sizeof(matrixNode));
			hdnode[i] = temp; hdnode[i]->tag = head;
			hdnode[i]->right = temp; hdnode[i]->u.next = temp;
		}
		currentRow = 0;
		last = hdnode[0];
		for (i = 0; i < numTerms; i++)
		{
			printf("Enter row, column and value:");
			scanf("%d%d%d", &row, &col, &value);
			if (row > currentRow) {
				last->right = hdnode[currentRow];
				currentRow = row; last = hdnode[row];
			}
			temp = (matrixNode*)malloc(sizeof(matrixNode));
			temp->tag = entry; temp->u.entry.row = row;
			temp->u.entry.col = col;
			temp->u.entry.value = value;
			last->right = temp;
			last = temp;
			hdnode[col]->u.next->down = temp;
			hdnode[col]->u.next = temp;
		}
		last->right = hdnode[currentRow];
		for (i = 0; i < numCols; i++)
			hdnode[i]->u.next->down = hdnode[i];
		for (i = 0; i < numHeads - 1; i++)
			hdnode[i]->u.next = hdnode[i + 1];
		hdnode[numHeads - 1]->u.next = node;
		node->right = hdnode[0];
	}
	return node;
}

void mwrite(matrixPointer node)
{
	int i;
	matrixPointer temp, head = node->right;
	printf(" \n numRows = %d, numCols = %d \n", node->u.entry.row, node->u.entry.col);
	printf("The matrix by row,column and value: \n\n");
	for (i = 0; i < node->u.entry.row; i++) {
		for (temp = head->right; temp != head; temp = temp->right)
			printf("%5d%5d%5d \n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
		head = head->u.next;
	}
}

int main()
{
	matrixPointer a;
	a = mread();
	mwrite(a);
	system("pause");
	return 0;
}