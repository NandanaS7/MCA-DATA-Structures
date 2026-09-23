#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


/* Function to create the initial linked list */
void createList()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter number to be inserted: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    printf("\nThe list is created\n");
}


/* 1. Display */
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}


/* 2. Insert at beginning */
void insertBeginning()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter number to be inserted: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}


/* 3. Insert at end */
void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter number to be inserted: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}


/* 4. Insert at any position */
void insertPosition()
{
    struct node *newnode, *temp;
    int pos, i;

    /* Allocate memory before using newnode */
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter number to be inserted: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


/* 5. Delete first element */
void deleteBeginning()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted element = %d\n", temp->data);

    free(temp);
}


/* 6. Delete last element */
void deleteEnd()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    /* If there is only one node */
    if (head->next == NULL)
    {
        printf("Deleted element = %d\n", head->data);

        free(head);
        head = NULL;

        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted element = %d\n", temp->data);

    free(temp);
}


/* 7. Delete element at any position */
void deletePosition()
{
    struct node *temp, *prev;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = head;
        head = head->next;

        printf("Deleted element = %d\n", temp->data);

        free(temp);

        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted element = %d\n", temp->data);

    free(temp);
}


/* 12. Search */
void search()
{
    struct node *temp;
    int item, pos = 1, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &item);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("Element %d found at position %d\n",
                   item, pos);

            found = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }

    if (found == 0)
    {
        printf("Element not found\n");
    }
}


/* Main function */
int main()
{
    int choice;

    createList();

    while (1)
    {
        printf("\n");
        printf("1. To display list\n");
        printf("2. For insertion at beginning\n");
        printf("3. For insertion at end\n");
        printf("4. For insertion at any position\n");
        printf("5. For deletion of first element\n");
        printf("6. For deletion of last element\n");
        printf("7. For deletion of element at any position\n");
        printf("12. Search an element\n");
        printf("13. To exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display();
                break;

            case 2:
                insertBeginning();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                insertPosition();
                break;

            case 5:
                deleteBeginning();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                deletePosition();
                break;

            case 12:
                search();
                break;

            case 13:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}