//*******************************************************************
//*  Program to Implement Primitive operation of Singly Linked List *
//*  Developed By: H. Banjade	Orchid International College	    *
//*  E:drive.bsccsit@gmail.com					    *
//*******************************************************************

# include<stdio.h>
# include<alloc.h>
# include<conio.h>
# include <ctype.h>

struct Node{
	int info;
	struct Node *next;
};

Node *pstack=NULL;

void push()
{
	int ele;
	Node *p;
	//read ele to push
	printf("\n Enter element to push into the stack\n");
	scanf("%d",&ele);
	//allocate memory
	p=(Node*)malloc (sizeof(Node));
	//assign ele into info part
	p->info=ele;
	//if stack is empty assign the address of current node to next part
	if(pstack==NULL)
	{
		pstack=p;
		pstack->next=p;
	}
	else
	{
		p->next = pstack->next;
		pstack->next = p;
	}
	printf("\n%d is added into the stack\n",p->info);
}

void pop()
{
	Node *p;
	if(pstack==NULL)
	{
		printf("\n Underflow condition arises\n");
		return;
	}
	else
	{
		int ele;
		if(pstack->next==pstack)
		{
			ele=pstack->info;
			pstack=NULL;
		}
		else
		{

			p = pstack->next;
			ele=p->info;
			pstack->next=p->next;
		}
		printf("\n%d is deleted from the stack",ele);
		free(p);
	}
}

void isempty()
{
	if(pstack==NULL)
	{
		printf("\nStack is  Empty\n");
		return;
	}
	else
	{

		printf("\n Stack is Not Empty\n");
	}
}
void tos()
{
	Node *p;
	if(pstack==NULL)
	{
		printf("\n Empty Stack\nThere are no element to display\n");
		return;
	}
	else
	{
		p = pstack->next;
		printf("\n %d is on the top of the stack\n",p->info);
	}
}

int main()
{

	int choice;
	char ch;
	do{
		clrscr();
		printf("\n Stack as a Circular List\n\n");
		printf("\n MENU");
		printf("\n\t1-> Check Empty\n\t2 -> PUSH\n\t3 -> POP\n\t4 -> TOS");
		printf("\n enter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				isempty();
				break ;
			case 2:
				push();
				break;
			case 3:
				pop();
				break;
			case 4:
				tos();
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