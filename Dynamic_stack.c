#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *Top;
void init()
{
	Top=NULL;
}
stack* createnode(int x)
{
 stack *temp;
 temp=(stack*)malloc(sizeof(stack));
 temp->data=x;
 temp->next=NULL;
 return temp;
}
void push(int x)
{
	stack *temp;
	temp=createnode(x);
	if(Top==NULL)
	Top=temp;
	else
	temp->next=Top;
	Top=temp;
}
int pop() // 2 3 4 5
{
	stack *temp, *p;
	int x;
	temp=createnode(x);
	if(Top==NULL)
	printf("as there is no element to delete ,so we cant perform deletion");
	else{
	p=Top;
	Top=p->next;
	printf("\n The deleted element is %d : ",p->data);
	free(p);
}
}
int size()
{
	stack *p;
	int i;
	if (Top==NULL)
	return 0;
	else
	{
	for(p=Top,i=1;p->next!=NULL;i++,p=p->next);
	return i;
   }
}
int peek()
{
	if(Top==NULL)
	return 0;
	else
	return (Top->data);
}
void display()
{
	stack *p;
	if (Top==NULL)
	printf("nothing to display");
	else
	{
		for(p=Top;p!=NULL;p=p->next)
		printf(" %d ",p->data);
	}
}
void main()
{
	int ch,x;
	init();
	do
	{
	printf("\n1.intialise 2.push  3.pop  4.size  5.peek 6.display 7.exit\n");
	printf("\nenter choice ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:init();
		       break;
		case 2:printf("enter element for pushing :: ");
		       scanf("%d",&x);
		       push(x);
		       break;
		case 3:pop();
		       break;
		case 4: printf("the size of stack is %d ",size());
		        break;
		case 5: printf("The elememt at peek is %d :: ",peek());
		        break;
		case 6:printf("the stack is :\n");
		       display();
		case 7:break;
	}
}while(ch!=7);
}
