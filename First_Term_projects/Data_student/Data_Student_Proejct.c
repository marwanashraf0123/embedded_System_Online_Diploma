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
	char first_name[40];
	char last_name[40];
	char courses[40];
	float GPA;
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
		pLastStudent->next=pNewStudent ;

	}
	DPRINTF("Enter First Name\n");
	gets(pNewStudent->student.first_name);

	DPRINTF("Enter Last Name\n");
	gets(pNewStudent->student.last_name);


	DPRINTF("Enter ID\n");
	scanf("%d",&pNewStudent->student.ID);

	DPRINTF("Enter GPA\n");
	scanf("%f",&pNewStudent->student.GPA);

	DPRINTF("Enter Courses Registered\n");
	gets(pNewStudent->student.courses);




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
			DPRINTF("First Name : %s\n",pCurrent->student.first_name);
			DPRINTF("Last Name : %s\n",pCurrent->student.last_name);
			DPRINTF("ID : %d\n",pCurrent->student.ID);
			DPRINTF("GPA : %f\n",pCurrent->student.GPA);
			DPRINTF("Courses : %s\n",pCurrent->student.courses);
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
void Add_student_file()
{
	int result;
	FILE *file = fopen("test.txt", "r");
	struct SSdata*pNewStudent;
	struct SSdata *pLastStudent;

	if(head == NULL)
	{

	}

	else
	{
		pLastStudent = head;
		while(pLastStudent->next)
		{
			pLastStudent = pLastStudent->next;
		}
	}

	while (1)
	{
		pNewStudent = (struct SSdata*)malloc(sizeof(struct SSdata));

		if (file == NULL)
		{
			perror("Error opening file");
			break;

		}


		result = fscanf(file, "%39[^,],%39[^,],%39[^,],%f,%d\n", pNewStudent->student.first_name, pNewStudent->student.last_name,pNewStudent->student.courses,&pNewStudent->student.GPA,&pNewStudent->student.ID);

			if(result == EOF)
			{
				free(pNewStudent);

				break;
			}
			else if(result != 5)
			{
				free(pNewStudent);
				break;
			}

			pNewStudent->next = NULL;



			if(head == NULL)
			{

				head = pNewStudent;
			}
			else
			{
				/*
				if (pLastStudent == NULL)
				{
					perror("Error: pLastStudent is NULL");
					break;
				}
				 */
				pLastStudent->next = pNewStudent;

			}
			pLastStudent = pNewStudent;







	}
	fclose(file);
}


void Search_ID()
{
	int ID_needed;
	DPRINTF("Enter ID\n");
	scanf("%d",&ID_needed);
	struct SSdata *pStudent_ID;

	if(head == NULL)
	{
		DPRINTF("list is empty");
	}
	else
	{
		pStudent_ID = head;
		while(pStudent_ID)
		{
			if(pStudent_ID->student.ID == ID_needed)
			{
				DPRINTF("Student Name : %s ID : %d\n",pStudent_ID->student.first_name,pStudent_ID->student.ID);
			}
			else
			{
				DPRINTF("ID doesn't exist\n");
			}
			pStudent_ID = pStudent_ID->next;
		}
	}
}
void Search_First()
{
	char first[40];
	DPRINTF("Enter first name to search for \n");
	gets(first);
	int  i ;
	struct SSdata *pStudent_first;


	if(head == NULL)
	{
		DPRINTF("list is empty");
	}
	else
	{
		pStudent_first = head;
		while(pStudent_first)
		{
			i = strcmp(pStudent_first->student.first_name,first);
			if(i == 0)
			{
				DPRINTF("Full Name :%s %s  ID:%d",pStudent_first->student.first_name,pStudent_first->student.last_name,pStudent_first->student.ID);
				return;
			}
			pStudent_first = pStudent_first->next;
		}

	}
	DPRINTF("Name Doesn't Exist");
}
void Search_Course()
{
	char course_search[40];
	DPRINTF("Enter Course to search for Physics,MatH or English \n");
	gets(course_search);
	int  i ;
	struct SSdata *pStudent_course;


	if(head == NULL)
	{
		DPRINTF("list is empty");
	}
	else
	{
		pStudent_course = head;
		while(pStudent_course)
		{
			i = strcmp(pStudent_course->student.courses,course_search);
			if(i == 0)
			{
				DPRINTF("Course : %s  Full Name :%s %s  ID:%d\n",pStudent_course->student.courses,pStudent_course->student.first_name,pStudent_course->student.last_name,pStudent_course->student.ID);

			}
			pStudent_course = pStudent_course->next;
		}
		return;
	}
	DPRINTF("Course Doesn't Exist");
}
void Update_Student()
{
	struct SSdata *pUpdate;
	int i;
	DPRINTF("Please Enter ID Of Student You Wish To Update Information\n");
	scanf("%d",&i);
	pUpdate = head;
	if(head == NULL)
	{
		printf("List is Empty\n");
		return;
	}

	while(pUpdate)
	{
		if (pUpdate->student.ID == i)
		{
			DPRINTF("Enter First Name\n");
			gets(pUpdate->student.first_name);

			DPRINTF("Enter Last Name\n");
			gets(pUpdate->student.last_name);


			DPRINTF("Enter GPA\n");
			scanf("%f",&pUpdate->student.GPA);

			DPRINTF("Enter Courses Registered\n");
			gets(pUpdate->student.courses);
			return;
		}
		pUpdate = pUpdate->next;
	}
	DPRINTF("No student with such ID\n");
}



int main()
{
	while(1)
	{
		int number;
		DPRINTF("\n==================================");
		DPRINTF("Please enter a number from 1 to 14\n");
		DPRINTF("1-Add Student Manually\n");
		DPRINTF("2-Delet Student\n");
		DPRINTF("3-View Students\n");
		DPRINTF("4-DeletAll\n");
		DPRINTF("5-Search using Index\n");
		DPRINTF("6-List Length\n");
		DPRINTF("7-Search using index reversed\n");
		DPRINTF("8-Find the Middle ID\n");
		DPRINTF("9-Detect Loop in the list\n");
		DPRINTF("10-Reverse List\n");
		DPRINTF("11-Add Student From A File\n");
		DPRINTF("12-Search Student By ID\n");
		DPRINTF("13-Search Student By First Name\n");
		DPRINTF("14-Search Student By Course Reigstered\n");
		DPRINTF("15-Update Student Information Based on ID\n");
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
		case 11:
			Add_student_file();
			break;
		case 12:
			Search_ID();
			break;
		case 13:
			Search_First();
			break;
		case 14:
			Search_Course();
			break;
		case 15:
			Update_Student();
			break;
		default:
			printf("ERRRO!");



		}


	}


}

