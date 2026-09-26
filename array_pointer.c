#include <stdio.h>
#define MAX 40
int insert(int *a,int *n)
{
    int pos;
    int val;
if(*n==MAX)
{
    printf("array is full");
    return 0;
}
  printf("Enter the position (0 to %d):",*n);
  scanf("%d",&pos);
    if(pos<0|| pos>*n)
    {
      printf("invalid position");  
    }
    else
    {
        printf("enter the value:");
        scanf("%d",&val);
        for(int i=*n;i>pos;i--)
            {
                a[i]=a[i-1];
            }
        a[pos]=val;
        (*n)++;
        printf("Element inserted successfully!");
    }
}
int delete(int *a,int *n)
{
    int pos;
    int val;
if(*n==0)
{
    printf("array is empty");
    return 0;
}
  printf("Enter the position (0 to %d):",*n);
  scanf("%d",&pos);
    if(pos<0|| pos>*n)
    {
      printf("invalid position");  
    }
    else
    {
                a[pos]=val;
        for(int i=pos;i<((*n)-1);i++)
            {
                a[i]=a[i+1];
            }

        (*n)--;
        printf("deleted element is %d ",pos);
        printf("Element deleted successfully!");
    }
}
int display(int *a,int n)
{
    for(int i=0;i<n;i++)
        {
          printf("%d\t",a[i]);  
        }
}
int search(int *a,int n)
{ 
    int found=0;
    int key;
    printf("Enter the key to find:");
    scanf("%d",&key);
    for(int i=0;i<=n;i++)
        {
          if(a[i]==key)
          {
              printf("Element found at position at %d:",i);
              found=1;
              break;
          }
        }
    if(found==0)
    {
        printf("Not found");
    }
}
int main() {
int ch;
int a[MAX];
    int n=0;
    while(1)
        {
            printf("--ARRAY OPERATIONS--");
            printf("\n");
            printf("1.insert");
            printf("\n");
             printf("2.delete");
            printf("\n");
             printf("3.serach");
            printf("\n");
             printf("4.display");
            printf("\n");
             printf("5.exit");
            printf("\n");
            printf("Enter your choice:");
            scanf("%d",&ch);
            switch(ch)
                {
                    case 1:insert(a,&n);
                         break;
                    case 2:delete(a,&n);
                         break;
                    case 3:search(a,n);
                         break;
                    case 4:display(a,n);
                         break;
                    case 5:printf("program terminated");
                         break;
                    default:
                          printf("Wrong choice!");
                }
        }
    
}
