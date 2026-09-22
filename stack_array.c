#include<stdio.h>
#define MAX 50
int stack[MAX];
int top=-1;
int push(){
    int value;
    if(top>=MAX-1)
    {
        printf("Stack Overflow");
    }
    else{
      printf("Enter the element to be inserted:");
      scanf("%d",&value);
      top++;
      stack[top]=value;
      printf("Element inserted successfully!");
    }
}
int pop()
{
    int value;
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else{
      value=stack[top];
      top--;
      printf("Element deleted!");
    }
}
int peek()
{
    
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else{
      printf("Element at the top is  %d:",stack[top]);
    }
}
int display()
{
    if(top==-1)
    {
        printf("Stack Underflow");
    }
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