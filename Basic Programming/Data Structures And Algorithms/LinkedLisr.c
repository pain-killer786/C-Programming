#include<stdlib.h>
#include <stdio.h>
void create();
void display();
void reverseList();
void insertNodeAtBeginning(int info);
void insertNodeAtEnd(int info);
void insertNodeAtMiddle();
void deleteAllByKey();
struct node
{
int info;
struct node *next;
};
struct node *head=NULL, *newnode, *temp;
int main()     
{
int choice,info;
printf("\n1.Create\n2.Display\n3.Reverse\n4.Insert node at start\n5.Insert node at end\n6.Insert node at middle\n7.Delete elements by key\n");
while(1)
{
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
break;
case 2:
display();
break;
case 3:
reverseList();
break;
case 4:
insertNodeAtBeginning(info);
break;
case 5:
insertNodeAtEnd(info);
break;
case 6:
insertNodeAtMiddle();
break;
case 7:
deleteAllByKey();
break;
default:
printf("\nWrong Choice!\n");
exit(0);
break;
}
}
return 0;
}
void create()
{
newnode=(struct node *)malloc(sizeof(struct node));
printf("\nEnter the value for the node: ");
scanf("%d",&newnode->info);
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
temp=newnode;
}
else
{
temp->next=newnode;
temp=newnode;
}
}
void display()
{
struct node *ptr;
if(head==NULL)
{
printf("\nList is empty\n");
return;
}
else
{
ptr=head;
printf("\nThe List elements are:\n");
while(ptr!=NULL)
{
printf("%d ",ptr->info );
ptr=ptr->next ;
printf("\n");
}
}
}
void reverseList()
{
struct node *prevNode, *curNode;
if(head!=NULL)
{
prevNode=head;
curNode=head->next;
head=head->next;
prevNode->next=NULL;
while(head!=NULL)
{
head=head->next;
curNode->next=prevNode;
prevNode=curNode;
curNode= head;
}
head=prevNode;
printf("\nList is successfully reversed\n");
}
}
void insertNodeAtBeginning(int info)
{
struct node *newNode;
printf("\nEnter the value for the node:");
scanf("%d",&info);
newNode=(struct node*)malloc(sizeof(struct node));
if(newNode==NULL)
{
printf("\nUnable to allocate memory\n");
}
else
{
newNode->info=info;
newNode->next=head;
head=newNode;
printf("\nData inserted at the beginning\n");
}
}
void insertNodeAtEnd(int info)
{
struct node *newNode, *temp;
printf("\nEnter the value for the node:");
scanf("%d",&info);
newNode=(struct node*)malloc(sizeof(struct node));
if(newNode==NULL)
{
printf("Unable to allocate memory.");
}
else
{
newNode->info=info;
newNode->next=NULL; 
temp=head;
while(temp!=NULL && temp->next!=NULL)
temp=temp->next;
temp->next=newNode;
printf("\nData inserted at the end\n");
}
}
void insertNodeAtMiddle(int info,int position)
{
int i;
struct node *newNode, *temp;
printf("\nEnter the valuefor the node to be inserted anywhere in the list:");
scanf("%d", &info);
printf("\nEnter the position to insert new node:" );
scanf("%d", &position);
newNode=(struct node*)malloc(sizeof(struct node));
if(newNode==NULL)
{
printf("\nUnable to allocate memory\n");
}
else
{
newNode->info=info;
newNode->next=NULL;
temp=head;
for(i=2; i<=position-1; i++)
{
temp=temp->next;
if(temp==NULL)
break;
}
if(temp!=NULL)
{
newNode->next=temp->next; 
temp->next=newNode;
printf("\nData inserted successfully\n");
}
else
{
printf("\nUnable to insert data\n");
}
}
}
void deleteAllByKey(int key)
{
int totalDeleted=0;
struct node *prev, *cur;
printf("\nEnter element to delete with key:");
scanf("%d", &key);
while (head!=NULL && head->info==key)
{
prev=head;
head=head->next;
free(prev);
totalDeleted++;
}
prev=NULL;
cur=head;
while (cur!=NULL)
{
if(cur->info==key)
{
if(prev!=NULL) 
{
prev->next=cur->next;
}
free(cur);
cur=prev->next;
totalDeleted++;
} 
else
{
prev=cur;
cur=cur->next;
}        
}
printf("\n%d element/s deleted with key %d\n",totalDeleted,key);
}
