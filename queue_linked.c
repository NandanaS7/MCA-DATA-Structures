#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
int enqueue()
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    int value;
    printf("Enter the element to be inserted:");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    
}
int dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue Underflow");
    }
    temp=front;
    front=front->next;
    free(temp);
    printf("Element deleted successfully!");
    if(front==NULL);
    {
        rear=NULL;
    }
}
int display()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue Underflow");
    }
    temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int peek()
{
    
    if(front==NULL)
    {
        printf("Queue Underflow");
    }
    printf("Element at front is %d",front->data);
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