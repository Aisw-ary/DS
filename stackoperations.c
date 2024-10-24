#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int stack[MAX],top=-1;
void push()
{
	int elem;
	if(top==MAX-1)
	{
	printf("\n\nStack Overflow!\nCannot push more elements");
	return;
	}
	printf("Enter the elements to be pushed:");
	scanf("%d",&elem);
	top++;
	stack[top]=elem;
	printf("\n\n%d pushed to the stack.\n",elem);
}
void pop()
{
	if(top==-1)
	{
		printf("\n\nStack Underflow!\nNo elements to pop\n");
		return;
	}
	printf("\n\nPopped element: %d\n",stack[top]);
	top--;
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\n\nStack is empty\n");
		return;
	}
	printf("\n\nStack elements are:\n");
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}
	
int main()
{
int ch;
while(1)
{
printf("\n---Stack Menu---\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("4.exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
	push();
	break;
case 2:
	pop();
	break;
case 3:
	display();
	break;
case 4:
	exit(0);
default:
	printf("Invalid Choice");
}
}
return 0;
}
