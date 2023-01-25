//*******************************************************************
//*  Program to Implement Primitive operation of Singly Linked List *
//*  Developed By: H. Banjade	Orchid International College	    *
//*  E:drive.bsccsit@gmail.com					    *
//*******************************************************************

# include < stdio.h >
# include < alloc.h >
# include < conio.h >
# include < ctype.h >

struct Node{
	int info;
	struct Node *next;
};

Node *rear=NULL;

void enqueue()
{
	int ele;
	Node *p;
	//read ele to insert
	printf("\n Enter element to ENQUEUE into the QUEUE\n");
	scanf("%d",&ele);
	//allocate memory
	p=(Node*)malloc (sizeof(Node));
	//assign ele into info part
	p->info=ele;
	//if stack is empty assign the address of current node to next part
	if(rear==NULL)
	{
		rear=p;
		rear->next=p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear=rear->next;
	}
	printf("\n%d is added into the QUEUE\n",rear->info);
}

void dequeue()
{
	Node *p;
	if(rear == NULL)
	{
		printf("\n Underflow condition arises\n");
		return;
	}
	else
	{
		int ele;
		if(rear->next==rear)
		{
			ele = rear->info;
			rear = NULL;
		}
		else
		{

			p = rear -> next;
			ele = p-> info;
			rear -> next = p -> next;
		}
		printf("\n%d is deleted from the queue",ele);
		free(p);
	}
}

void isempty()
{
	if(rear==NULL)
	{
		printf("\nQueue is  Empty\n");
		return;
	}
	else
	{

		printf("\n Queue is Not Empty\n");
	}
}

void first()
{
	Node *p;
	if(rear == NULL)
	{
		printf("\n Empty Queue\nThere is no element to display\n");
		return;
	}
	else
	{
		p = rear->next;
		printf("\n %d is on the front of the queue\n",p->info);
	}
}

int main()
{

	int choice;
	char ch;
	do{
		clrscr();
		printf("\n QUEUE as a Circular List\n\n");
		printf("\n MENU");
		printf("\n\t1-> Check Empty\n\t2 ->  ENQUEUE\n\t3 -> DEQUEUE\n\t4 -> FIRST\n");
		printf("\n enter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				isempty();
				break ;
			case 2:
				enqueue();
				break;
			case 3:
				dequeue();
				break;
			case 4:
				first();
				break;
			default:
				printf("\n Invalid Choice\n Choose Valid Option\n");
		}
		printf("\n Do you want to continue (Y/N)\n");
		fflush(stdin);
		ch=getchar();
       } while(toupper(ch)== 'Y');
	return 0;
}