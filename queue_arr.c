#include<stdio.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;
int enqueue()
{
 int value;
 if(rear>=MAX)
 {
    printf("Queue Overflow");

 }
 
 if(front==-1)
 {
    front=0;
 }
 printf("Enter the value:");
 scanf("%d",&value);
 rear++;
 queue[rear]=value;
}
int dequeue()
{   
    int val;
    if(front==-1||front>rear)
    {
        printf("Queue Underflow");
    }
    val=queue[front];
    front++;
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    printf("Deleted element is %d",val);
}
int display()
{
    if(front==-1||front>rear)
    {
        printf("Queue Underflow");
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}
int peek()
{
     if(front==-1||front>rear)
    {
        printf("Queue Underflow");
    }
    printf("Element at the front is %d",queue[front]);
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n---Queue Operation---\n");
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.Exit\n");
        printf("Select an option between 1-5\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                  enqueue();
                  break;
            case 2:
                  dequeue();
                  break;
            case 3:
                  peek();
                  break;
            case 4:
                  display();
                  break;
            case 5:
                  printf("Program terminated\n");
                  return 0 ;
            default:
                  printf("Wrong Choice!");

        }
    }
}