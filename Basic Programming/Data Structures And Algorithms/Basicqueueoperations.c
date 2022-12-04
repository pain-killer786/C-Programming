#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front =-1;
struct node *rear = -1;
void enqueue();
void dequeue();
void display();
void peek();
void main()
{
	int choice;
	while (choice !=5)
	{
		printf("\nEnter your Choice\n\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Peek\n 5.Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\n Wrong Choice\n");
		}		
	}
}
void enqueue()
{
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	int item;
	printf("\nEnter value:\n");
	scanf("%d", &item);
	ptr->data = item;
	ptr->next =0;
	if (rear == -1)
	{
		front = rear = ptr;
		rear->next = front;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
		rear->next=front;
	}
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if ((front==-1)&&(rear ==-1))
	{
		printf("\n Queue is empty");
	}
	else if(front == rear)
	{
		front=rear=-1;
		free(temp);
	}
	else
	{
		front=front->next;
		rear->next=front;
		free(temp);
	}
}
void display()
{
	struct node *ptr;
	ptr = front;
	if ((front == -1)&&(rear== -1))
	{
		printf("\nQueue is empty");
	}
	else 
	{
		while(ptr->next !=front)
		{
			printf(" %d ",ptr->data);
			ptr = ptr->next;
		}
		printf(" %d ",ptr->data);
	}
}
void peek()
{
	if ((front==-1) && (rear==-1))
	{
		printf("\n Queue is empty");
	}
	else
	{
		printf("\n The front element is: %d",front->data);
	}
}
