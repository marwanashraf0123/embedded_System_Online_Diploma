/*
 * main.c
 *
 *  Created on: 29 Aug 2023
 *      Author: marwan
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DPRINTF(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

struct Sdata
{
	char name[40];
	float hieght;
	int ID;
};

struct SSdata
{
	struct Sdata student;
	struct SSdata* next;
};

struct SSdata* head = NULL;

void Addstudent()
{
	struct SSdata *pNewStudent;
	struct SSdata *pLastStudent;

	pNewStudent = (struct SSdata*)malloc(sizeof(struct SSdata));
	pNewStudent->next = NULL;

	if(head == NULL)
	{
		head=pNewStudent;
	}
	else
	{
		pLastStudent = head;
		while(pLastStudent->next != NULL)
		{
			pLastStudent = pLastStudent->next;
		}
		pLastStudent->next = pNewStudent;

	}
	DPRINTF("Enter Name\n");
	gets(pNewStudent->student.name);


	DPRINTF("Enter ID\n");
	scanf("%d",&pNewStudent->student.ID);

	DPRINTF("Enter Height\n");
	scanf("%f",&pNewStudent->student.hieght);



	pNewStudent->next = NULL;

}

void viewStudent()
{
	int count = 0 ;
	struct SSdata* pCurrent = head;
	if(pCurrent!=NULL)
	{
		while(pCurrent)
		{
			DPRINTF("student number : %d\n",count+1);
			DPRINTF("Name : %s\n",pCurrent->student.name);
			DPRINTF("ID : %d\n",pCurrent->student.ID);
			DPRINTF("Height : %f\n",pCurrent->student.hieght);
			pCurrent = pCurrent->next;
			count++;
		}
	}
	else
	{
		printf("Empty\n");
	}
}
int deletStudent()
{
	struct SSdata *pCurrent ;
	struct SSdata *pPrev=NULL;
	int ID;
	DPRINTF("Please Enter ID for student to be deleted");
	scanf("%d",&ID);

	pCurrent = head;

	if(pCurrent->student.ID == ID)
	{
		head = pCurrent->next;
		free(pCurrent);
		return 1;
	}

	else
	{
		while(pCurrent)
		{

			if(pCurrent->student.ID == ID)
			{

				pPrev->next = pCurrent->next;
				free(pCurrent);
				return 1;



			}
			pPrev = pCurrent;
			pCurrent=pCurrent->next;



		}
		DPRINTF("No ID matches");

	}
	return 0;
}
void delet_all()
{
	struct SSdata*pCurrent ;
	pCurrent =head;

	if(head==NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		while(pCurrent)
		{
			struct SSdata*pTemp = pCurrent;
			pCurrent = pCurrent->next;
			free(pTemp);
		}
	}
	head = NULL;
}


int GetNth()
{
	int index;
	int counter = 0;
	DPRINTF("\n Enter Index");
	scanf("%d",&index);

	struct SSdata *pCurrent;
	pCurrent = head;
	if(counter==index)
	{
		DPRINTF("Index : %d  ID :%d \n",index,pCurrent->student.ID );
		return 1;
	}
	while(pCurrent)
	{
		if(counter == index)
		{
			DPRINTF("Index : %d  ID :%d \n",index,pCurrent->student.ID);
			return 1;
		}
		pCurrent=pCurrent->next;
		counter++;
	}
	DPRINTF("The index Doesn't exist\n");
	return 0;

}

int listLegnth()
{
	struct SSdata*pCurrent ;
	/*
	 pCurrent = head;
	 if(head==NULL)
	 {
	 DPRINTF("list is Empty\n");
	  return 0;

	 }
	 else
	 {
	   1+listLegnth(pCurrent->next)
	 }

	 */
	pCurrent= head;
	int counter = 0;
	if(head == NULL)
	{
		DPRINTF("List is Empty\n");
		return 0;
	}
	else
	{
		while(pCurrent)
		{
			pCurrent=pCurrent->next;
			counter++;

		}
		DPRINTF("List length = %d\n",counter);
	}
	return 0;
}

int GetNth_reversed()
{
	struct SSdata* pMain = head;
	struct SSdata* pRev = head;

	int index;
	int counter = 0;
	DPRINTF("Enter the index required to be found\n");
	scanf("%d",&index);

	if(head == NULL)
	{
		DPRINTF("Empty List \n");
		return 0;
	}


	while(counter != index)
	{
		pRev = pRev->next;
		counter++;
	}
	while(pRev)
	{
		pMain = pMain->next;
		pRev = pRev ->next;

	}
	DPRINTF("Index : %d   ID : %d",index,pMain->student.ID);

	return 1;


}

int find_middle_node()
{
	struct SSdata *pSlow = head;
	struct SSdata *pFast = head;
	if(head == NULL)
	{
		DPRINTF("Empty List \n");
		return 0;
	}
	while(pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	DPRINTF("Middle Node ID is : %d ",pSlow->student.ID);
	return 1;

}

int Detect_loop()
{
	if(head == NULL)
	{
		DPRINTF("List is Empty\n");
		return 0;
	}
	struct SSdata*pFast =head;
	struct SSdata*pSlow =head;

	while(pFast && pSlow->next && pSlow && pFast->next)

	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if (pSlow == pFast)
		{
			DPRINTF("There is a Loop\n");
			return 1;
		}

	}
	DPRINTF("No LOOP \n");
	return 0;

}

int Reverse_list()
{
	if(head == NULL)
	{
		DPRINTF("List is Empty\n");
		return 0;
	}
	if(head->next == NULL)
	{
		DPRINTF("List has only one elemnt no need to reverse");
		return 0;
	}

	struct SSdata *pCurrent = head->next;
	struct SSdata *pPrev = head;
	struct SSdata *pNext = head->next->next;


	if(pCurrent->next == NULL)
	{
		pCurrent->next = pPrev;
		head = pCurrent;
		pPrev->next = NULL;
		return 1;
	}
	while(pCurrent)
	{

		pCurrent->next = pPrev;
		pPrev=pCurrent;
		pCurrent = pNext;
		if(pNext != NULL)
			pNext=pNext->next;
	}
	head->next = NULL;
	head = pPrev;
	return 1;



}


int main()
{
	while(1)
	{
		int number;
		DPRINTF("\n==================================");
		DPRINTF("Please enter a number from 1 to 4\n");
		DPRINTF("1-Add Student\n");
		DPRINTF("2-Delet Student\n");
		DPRINTF("3-View Students\n");
		DPRINTF("4-DeletAll\n");
		DPRINTF("5-Search using Index\n");
		DPRINTF("6-List Length\n");
		DPRINTF("7-Search using index reversed\n");
		DPRINTF("8-Find the Middle ID\n");
		DPRINTF("9-Detect Loop in the list\n");
		DPRINTF("10-Reverse List\n");
		scanf("%d",&number);

		switch (number)
		{
		case 1:
			Addstudent();
			break;
		case 2:
			deletStudent();
			break;
		case 3:
			viewStudent();
			break;
		case 4:
			delet_all();
			break;
		case 5:
			GetNth();
			break;
		case 6:
			listLegnth();
			break;
		case 7:
			GetNth_reversed();
			break;
		case 8:
			find_middle_node();
			break;
		case 9:
			Detect_loop();
			break;
		case 10:
			Reverse_list();
			break;
		default:
			printf("ERRRO!");
			break;


		}


	}


}

