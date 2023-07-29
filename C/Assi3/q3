/*
 ============================================================================
Lesson 4 array
Ex3_homework3
Created on : 27/7/2023
Author:Khalid walid alazouni
 ============================================================================
 */
#include <stdio.h>
int main(void) {
	setbuf(stdout,NULL); //TO SOLVE INPUT/OUTPUT BUFFER BUG
	int a[10][10];
	int trans[10][10];
	int i,j,r,c;
	printf("enter the rows and columns of matrix :");
	scanf("%d %d",&r,&c);
	printf("enter the elements of matrix \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("enter element a%d%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("the entered matrix :\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			trans[i][j]=a[j][i];
		}
	}
	printf("transpose of matrix :\n");
	for(i=0;i<c;i++){
			for(j=0;j<r;j++){
				printf("%d\t",trans[i][j]);
			}
			printf("\n");
		}
}
