#include<stdio.h>
#include<conio.h>
#include <process.h>
# define SIZE 20
//Declearing Structure
struct arraylist {
	int array[SIZE]; //array to store data items
	int index;

	};		  // variable which always track the position of data item stored in the last position of array
	void insertion(struct arraylist *pal);
	void deletion(struct arraylist *pal);
	void traversing(struct arraylist *pal);
	void searching(struct arraylist *pal);
	void modifying(struct arraylist *pal);

void main()
{
	int choice,repeate;
	struct arraylist al;
	al.index=-1; // indicates there is no element inside array while creating structure
	/* Program to implement array as An ADT*/

	do{
		/* Ask user to choose array operation listed below*/
		printf("\n Enter Your Choice\n\n 1: Insert \t 2: Delete \t 3: Traverse \t 4: Search \t 5: Modify \t 6: Exit:\n");
		scanf("%d",&choice);
		clrscr();
		/*Write a menu to implement above choice*/
		switch(choice)
		{
			case 1:
			insertion(&al);
			printf("\n\nPress Enter to continue\n");
			getch();
			break; //takes control out of switch

			case 2:
			deletion(&al);
			printf("\n\nPress Enter to continue\n");
			getch();
			break;

			case 3:
			traversing(&al);
			printf("\n\nPress Enter to continue\n");
			getch();
			break;

			case 4:
			searching(&al);
			printf("\n\nPress Enter to continue\n");
			getch();
			break;

			case 5:
			modifying(&al);
			printf("\n\nPress Enter to continue\n");
			getch();
			break;

			case 6:

			exit(0);
			break;

			default:
			printf("\n You choose wrong option");
			break;
		}
		printf("\n Do you want continue.\n Press 1 to continue \n Press any Key excet 1 to exit\n");
		scanf("%d",&repeate);
	}while(repeate == 1) ;

}

void insertion(struct arraylist *pal){
	int i,pos,element;
	//Check whether there is vacant space or not to insert element
	if(pal->index==SIZE-1)
	{
		printf("\n Array is Full!! \n You can't perform insertion on full array");
		return;
	}

	//Ask to enter array position in which user is going to insert an item
	printf("\n Enter position of array to insert an element(position is begining from 0)\n");
	scanf("%d",&pos);

     // check whether user entered position is valid or not
     if(pos>pal->index+1)
     {
		printf("\n You Entered Wrong position\n Position is out of array stored\n");
		return;
     }
     //if position is valid, make user entered position vacent to insert an element

     for( i = pal->index; i >= pos; i-- )

		pal->array[i+1]=pal->array[i];
     //position is vacent where you can insert element
	//ask user to insert element
	printf("\n Enter element to insert on %d position of array:\n ",pos);
	scanf("%d",&element);

	//Now insert element
	pal->array[pos]=element;

	// increment index by one
	pal->index++;
	traversing(pal);

}

void deletion(struct arraylist *pal)
{
		int i,pos,element;
	//Check whether array is empty or not
	if(pal->index==-1)
	{
		printf("\n Array is Empty!! \n You can't perform deletion operation on empty array");
		return;
	}

	//Ask position from user to delete an item on array
	printf("\n Enter position of array to delete an element(position is begining from 0)\n");
	scanf("%d",&pos);

     // check whether user entered position is valid or not
     if(pos<pal->index)
     {
		printf("\n You Entered Wrong position\n Position is out of array stored\n");
		return;
     }
	//if position is valid, perform left shift of element up to position to delete an element
	//the element stored in the given position will be overwrite by element of right next

	for( i =pos;i<pal->index;i++ )

		pal->array[i]=pal->array[i+1];

	//decrese index to notify the deletion of element
	pal->index--;
	traversing(pal);



}

void traversing(struct arraylist *pal)
{
	if(pal->index==-1)
	{
		printf("\n Array is Empty!! \n No element to Display\n");
		return;
	}
	printf("\n The element stored in array are:\n");
	for(int i=0; i<=pal->index;i++)
	printf("%d",pal->array[i]);
}

void searching(struct arraylist *pal)
{

	int element;
	if(pal->index==-1)
	{
		printf("\n Array is Empty!! \n No element to Find\n");
		return;
	}
	printf("Enter Element To find");
	scanf("%d",&element);

	for(int i=0;i<=pal->index;i++)
	{
		if(pal->array[i]==element )
		{
			printf("\n The element %d is found on array :\n",element);
			return;
		}
		else
		{

			printf("\n The element %d is not found on array :\n",element);
			return;
		}
	}


}

void modifying(struct arraylist *pal)
{
	int i,pos,element;

	if(pal->index==-1)
	{
		printf("\n Array is Empty!! \n There is no element to modify");
		return;
	}

	//Ask to enter array position in which user is going to modify an item
	printf("\n Enter position of array to modify an element(position is begining from 0)\n");
	scanf("%d",&pos);

     // check whether user entered position is valid or not
     if(pos>pal->index)
     {
		printf("\n You Entered Wrong position\n Position is out of array stored\n");
		return;
     }
     element=pal->array[pos];

	printf("\n Enter element to modify element %d stored on %d position of array:\n ",element,pos);
	scanf("%d",&element);

	//Now insert element
	pal->array[pos]=element;
	traversing(pal);

}