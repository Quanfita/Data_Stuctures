
/*

A menu driven program 
to insert,delete and traverse data in a priority queue in C Programming Language.


*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	int pno;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

struct node*  createNode()
{
	struct node *n;
	n=(struct node*) malloc(sizeof(struct node));
	return n;
	
}
bool isempty()
{
	if(front==NULL&&rear==NULL)
	return true;
	
	else
	return false;
}

int menu()
{
	int ch;
	printf("\n1.Enqueue Priority Queue");
	printf("\n2.Dequeue Priority Queue");
	printf("\n3.Traverse Priority Queue");
	printf("\n4.Exit");
	printf("\n\nEnter your choice:");
	scanf("%d",&ch);
	return ch;
}


void en_prqueue()
{
	struct node *temp,*t;
	temp=createNode();
	printf("\n\nEnter data:");
	scanf("%d",&temp->data);
	printf("Enter pno:");
	scanf("%d",&temp->pno);
	temp->next=NULL;
	
	if(front==NULL|| temp->pno<front->pno)
	{
		temp->next=front;
		front=temp;
		
		printf("%d inserted\n",front->data);
	}	
	else
	{	t=front;
		while(t->next!=NULL&&t->next->pno<=temp->pno)
			t=t->next;
		temp->next=t->next;
		t->next=temp;
		rear=temp;
		printf("%d inserted\n",rear->data);
	}

}

void de_prqueue()
{
	struct node *temp;
	
	if(front==NULL)
	printf("Underflow!\n");
	
	else
	{
		temp=front;
		front=front->next;
		printf("\n%d deleted",temp->data);
		free(temp);
	} 

}

void traverse()
{
	struct node *i;
	if(front==NULL)
	printf("\nQueue is empty!\n");
	
	else
	{	printf("\n\n");
		for(i=front;i!=NULL;i=i->next)
		{
			printf("%d\n",i->data);
		}
	}
}


int main()
{
	while(1)
	{
		switch(menu())
		{
			case 1:en_prqueue();break;
			case 2:de_prqueue();break;
			case 3:traverse();break;
			case 4:exit(0);
		}			
	}

return 0;
}



