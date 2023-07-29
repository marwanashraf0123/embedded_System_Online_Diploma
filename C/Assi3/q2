/*
 ============================================================================
Lesson 4 array
Ex2_homework3
Created on : 27/7/2023
Author:Khalid walid alazouni
 ============================================================================
 */
#include <stdio.h>
int main(void) {
	setbuf(stdout,NULL); //TO SOLVE INPUT/OUTPUT BUFFER BUG
	int i,n;
	float a[100],sum=0.0,average=0.0;
	printf("enter the numbers of data : ");
	scanf ("%d",&n);
	for(i=0;i<n;i++){
		printf("%d. enter number : ",i+1);
		scanf("%f",&a[i]);
	}
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	average=sum/n;
	printf("average = %.2f",average);

  return 0;
}
