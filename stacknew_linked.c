#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

/* PUSH */
void push()
{
    int value;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
    }
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = top;
        top = newnode;

        printf("Element inserted successfully!\n");
    }
}

/* POP */
void pop()
{
    struct node *temp;
    int value;

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        temp = top;
        value = temp->data;

        top = top->next;

        free(temp);

        printf("Deleted element: %d\n", value);
    }
}

/* PEEK */
void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

/* DISPLAY */
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

/* MAIN */
int main()
{
    int ch;

    while (1)
    {
        printf("\n--- Stack Operation ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Select an option between 1-5: ");
        scanf("%d", &ch);

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
                return 0;

            default:
                printf("Wrong Choice!\n");
        }
    }
}
