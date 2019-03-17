//
//  main.cpp
//  sparse
//
//  Created by Garry Yeung on 2018/11/15.
//  Copyright © 2018 Garry Yeung. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrixStructure
{
	int row;
	int col;
	int value;
	matrixStructure *next;
};

matrixStructure* mread(int,int,int);
void mwrite(matrixStructure *);
matrixStructure* mmult(matrixStructure *,matrixStructure *);
matrixStructure* mtranspose(matrixStructure *);

int main(int argc, const char * argv[]) {
	matrixStructure *matrixOne=new matrixStructure;
	matrixStructure *matrixTwo=new matrixStructure;
	matrixStructure *transposeMatrix=new matrixStructure;
	matrixStructure *product=new matrixStructure;
	
	printf("Enter matrix:\n");
	int numberOfRow,numberOfCol,totalNumOfValues;
	scanf("%d %d %d",&numberOfRow,&numberOfCol,&totalNumOfValues);
	matrixOne=mread(numberOfRow,numberOfCol,totalNumOfValues);
	scanf("%d %d %d",&numberOfRow,&numberOfCol,&totalNumOfValues);
	matrixTwo=mread(numberOfRow,numberOfCol,totalNumOfValues);
	transposeMatrix=mtranspose(matrixTwo);
	mwrite(transposeMatrix);
	product=mmult(matrixOne,transposeMatrix);
	mwrite(product);
	
	
}

matrixStructure* mread(int row,int col,int n)
{
	matrixStructure *current=new matrixStructure;
	matrixStructure *matrix=new matrixStructure;
	matrix->next=current;
	matrix->row=row;
	matrix->col=col;
	matrix->value=n;
	
	int r,c,v;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&r,&c,&v);
		
		current->row=r;
		current->col=c;
		current->value=v;
		
		current->next=new matrixStructure;
		current=current->next;
	}
	current->next=NULL;
	
	return matrix;
}

void mwrite(matrixStructure *matrix)
{
	matrixStructure *current=matrix->next;
	while(current->next)
	{
		printf("%d %d %d\n",current->row,current->col,current->value);
		current=current->next;
	}
}

matrixStructure* mtranspose(matrixStructure *matrix)
{
	matrixStructure *transposedMatrix=new matrixStructure;
	matrixStructure *current;
	matrixStructure *current2=new matrixStructure;
	
	transposedMatrix->next=current2;
	transposedMatrix->col=matrix->row;
	transposedMatrix->row=matrix->col;
	transposedMatrix->value=matrix->value;
	
	int currentCol;
	for(currentCol=0;currentCol<(matrix->col);currentCol++)
	{
		current=matrix->next;
		while(current->next)
		{
			if(current->col==currentCol)
			{
				current2->row=current->col;
				current2->col=current->row;
				current2->value=current->value;
				
				current2->next=new matrixStructure;
				current2=current2->next;
			}
			current=current->next;
		}
	}
	current2->next=NULL;
	
	return transposedMatrix;
}

matrixStructure* mmult(matrixStructure *matrix1,matrixStructure *matrix2)
{
	matrixStructure *productMatrix=new matrixStructure;
	matrixStructure *current1;
	matrixStructure *current2;
	matrixStructure *currentNew=new matrixStructure;
	
	current1=matrix1->next;
	current2=matrix2->next;
	productMatrix->row=matrix1->row;
	productMatrix->col=matrix2->col;
	productMatrix->next=currentNew;
	
	matrixStructure *rowHead;
	
	
	int product=0,currentRow,currentCol,temp,justAdd=0,lastRow,lastCol;
	
	int step[20],i=0,count=0,last;
	last=current1->row;
	while(current1)
	{
		if(last!=current1->row)
		{
			step[i]=count;
			i=i+1;
			count=0;
		}
		last=current1->row;
		current1=current1->next;
		count=count+1;
	}
	
	i=0;
	current1=matrix1->next;
	while(current1->next)
	{
		for(int j=0;j<step[i]-1;j++)
		{
			current1=current1->next;
		}
		currentRow=current1->row;
		rowHead=current1;
		
		current2=matrix2->next;
		currentCol=current2->col;
		
		while(current2->next)
		{
			justAdd=0;
			if((current2->col)!=currentCol || (current1->row)!=currentRow)
			{
				if(product!=0)
				{
					currentNew->row=lastRow;
					currentNew->col=lastCol;
					currentNew->value=product;
					
					currentNew->next=new matrixStructure;
					currentNew=currentNew->next;
					
					product=0;
					

					
					justAdd=1;
				}
			}
			
			if((current2->col)!=currentCol)
			{
				currentCol=current2->col;
				
			}
			if((current1->row)!=currentRow)
			{
				current1=rowHead;
			}
			
			if((current2->col)==(currentCol))
			{
				if((current1->col)==(current2->row))
				{
					product=product+(current1->value)*(current2->value);
					lastRow=current1->row;
					lastCol=current2->col;
					
					current1=current1->next;
					current2=current2->next;
					
					continue;
				}
			}
			
			if((current1->col)<(current2->row))
			{
				current1=current1->next;
			}
			else if((current1->col)>(current2->row))
			{
				current2=current2->next;
			}
		}
		i=i+1;
		
	}
	
	return productMatrix;
}


