#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
int push()
{
    int value;
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed!");
    }
    else
    {
        printf("Enter the element to be inserted:");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=top;
        top=newnode;
        printf("Element inserted successfully!");
    }
}
void pop()
{   
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack underflow");
    }
    else
    {
     temp=top;

    }
}
int display()
{
    struct node *temp;
    temp=top;
    else{
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
          
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("\n---Stack Operation---\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.Exit\n");
        printf("Select an option between 1-5\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                  push();
                  break;
            case 2:
                  pop();
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