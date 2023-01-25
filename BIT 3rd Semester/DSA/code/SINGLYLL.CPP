//********************************************************************
//*  Program to Implement Primitive operations of Singly Linked List *
//*  Developed By: H. Banjade	Orchid International College	     *
//*  E:drive.bsccsit@gmail.com					                     *
//********************************************************************

# include <stdio.h>
# include<ctype.h>
# include <conio.h>
# include <stdlib.h>

//define node
struct Node{
	int info;     // store info
	struct Node *next;         //store address of next node
	};

	typedef Node node;

	// global pointer head and tail are declared
	node *head= NULL,*tail=NULL;

	//function to insert node at head of the linked list
	void insertAtHead()
	{
		node *p;
		int ele;

		//ask user to enter element
		printf("\n Enter Element to insert At Head:\n");
		scanf("%d",&ele);

		//allocate memory for new node
		p=(node*)malloc(sizeof(node));

		//assign ele to info part of node pointed by p
		p->info = ele;

		//assign address of current head to next part of new node
		p->next=head;

		//if linked list is empty update both head and tail to new node
		if(NULL==head)
		{

			tail=head=p;
		}

		//else update head to newly created node
		else
			head = p;

		// Display the info added in the Linked List
		printf("\n %d is added to the Linked List\n",head->info);
	}

//function to delete a node from head
int deleteFromHead()
{
	int ele;
	//check linked list is empty or not
	if(NULL == head )
	{
		printf("\nThere are no element in the Linked List to delete\n");
		return NULL;
	}
       //if not empty delete the node from head
	else
	{
		ele = head->info;  // store element before deletion
		head = head->next;  //move head to the next node

	}
	return ele; //return deleted element
}

//function to insert a node at the tail of the linked list
void insertAtTail()
{
	node *p;
	int ele;
	//read element from user to insert into the tail
	printf("\n Enter Element to insert At Tail:\n");
	scanf("%d",&ele);

	//allocate memory for new node
	p=(node*)malloc(sizeof(node));

	//assign element to info part of newly created node
	p->info = ele;

	//assign NULL to the next part of tail
	p->next=NULL;

	//if linked list is empty; make it both head and tail
	if(NULL==tail)
		tail=head=p;
	else
	{
		//assign the address of newly created node to the next part of current tail
		tail->next = p;

		//move tail to next node
		tail=p;
	}

		printf("\n %d is added to the tail of a Linked List\n",tail->info);
}

//function to delete a node from tail
int deleteFromTail()
{
	int ele;

	//Check linked list is empty or not
	if(NULL ==  tail )
	{
		printf("\nThere are no element in the Linked List to delete\n");
		return NULL;
	}

	else
	{
		//point the previous node of tail by temp
		for(node *temp=head; temp->next!=NULL; temp=temp->next)
		;
		//store element before deletion
		ele = tail->info;

		//deallocate the memory allocated by the node pointed by tail
		free(tail);

	       // update tail to previous
		tail = temp;
	}
	return ele;
}

//function to display all element stored in linked list
void displayAll()
{
	printf("\n The Element Stored in Linked List Are:\n");
	for(node * temp = head ; temp!= NULL; temp= temp->next)
		printf("%d\t",temp->info);
}

void search()
{
	int ele,found=0;
	printf("\n Enter element to search\n");
	scanf("%d",&ele);
	for(node * temp = head ; temp!= NULL; temp= temp->next)
	{
		if(temp->info==ele)
		{
			found=1;
			break;
		}
	}
	if(found == 1)
		printf("\n Element found");
	else
		printf("\n Element not found");
}

void insertAfter()
{
	node *p;
	int found=0,ele;
	printf("\n Enter after which element you want to insert\n") ;
	scanf("%d",&ele);

	for(node * temp = head ; temp!= NULL; temp= temp->next)
	{
		if(temp->info==ele)
		{
			found=1;
			break;
		}
	}
	if(found == 1)
	{
		int ele2;
		printf("\n Position is valid\n");
		printf("\n Enter elemnet to insert\n");
		scanf("%d",&ele2);
		p=(node*)malloc(sizeof(node));
		p->info=ele2;
		if(temp==tail)
		{
			p->next=NULL;
			tail=p;
		}
		else
			p->next=temp->next;
		temp->next=p;
		printf("%d is inserted after %d ",ele2,ele);
		displayAll();
	}
	else
		printf("\n Such Element doesnot exit\n Insertion is Unsuccessfull");

}

void deleteAfter()
{
	node *p;
	int found=0,ele;
	if( head == NULL)
	{
			printf(" Linked List is Empty\n Not a valid position\n");
			return;
	}
	else
	{

		printf("\n Enter after which element you want to Delete\n") ;
		scanf("%d",&ele);
		for(node * temp = head ; temp!= NULL; temp= temp->next)
		{
			if(temp->info==ele)
			{
				found=1;
				break;
			}
		}
		if(found == 1)
		{
			if(temp == tail || head == tail)
			{
				printf("\n Either single Node or Last Node\n Insertion after position not valid\n");
				return;
			}
			p=temp->next;
		       //	printf("\n Valid position");

			int ele2 = p->info;
			if(p==tail)
			{
				printf("p==tail");
				tail=temp;
				tail->next=NULL;
			}
			else
				temp->next= p->next;

			printf("\n %d is deleted after %d",ele2,ele);

			displayAll();
		}
	}
 }


void main()
{
	char ch;
	int choice;
	clrscr();
	do{
		clrscr();
		printf("\n\tMENU\n");
		printf("1 -> Insert a Node at Head\n");
		printf("2 -> Delete a Node From Head\n");
		printf("3 -> Insert a Node at Tail\n");
		printf("4 -> Delete a Node from Tail\n");
		printf("5 -> Display All\n");
		printf("6 -> Search\n");
		printf("7 -> Insert After\n");
		printf("6 -> Delete After\n");
		printf("Enter your Choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertAtHead();
				break;
			case 2:
				if(head== NULL)
					printf("Linked List is Empty:\n");
				else
					printf("%d is deleted From Linked List\n",deleteFromHead());
				break;
			case 3:
				insertAtTail();
				break;
			case 4:
				if(tail == NULL)
					printf("Linked List is Empty:\n");
				else
					printf("%d is deleted From Linked List\n",deleteFromTail());
				break;
			case 5:
				if(head== NULL)
					printf("Linked List is Empty:\n");
				else
					displayAll();
				break;
			case 6:
				if(head== NULL)
				{
					printf("Linked List is Empty:\n"); 	printf("Insert after position does not exist :\n");
				}
				else
					search();
				break;

			case 7:
				if(head== NULL)
					printf("Insert after position does not exist :\n");
				else
					insertAfter();
				break;
			case 8:
				deleteAfter();
				break;
		}
		fflush(stdin);
		printf("Do you want to continue:(Y/N)\n");
		ch = toupper(getchar());
	}while(ch=='Y');

}
