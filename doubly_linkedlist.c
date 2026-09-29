#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Create List */
void createList()
{
    int n, i, value;
    struct node *newnode;
    struct node *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid number of nodes.\n");
        return;
    }

    /* If a list already exists, remove it */
    head = NULL;

    for(i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    printf("List created successfully.\n");
}

/* Insert at beginning */
void insertBeginning()
{
    int value;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;

    printf("Node inserted successfully.\n");
}

/* Insert at end */
void insertEnd()
{
    int value;
    struct node *newnode;
    struct node *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

/* Insert at position */
void insertPosition()
{
    int value, position, i;
    struct node *newnode;
    struct node *temp;

    printf("Enter position: ");
    scanf("%d", &position);

    printf("Enter value: ");
    scanf("%d", &value);

    if(position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if(position == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        if(newnode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = head;

        if(head != NULL)
        {
            head->prev = newnode;
        }

        head = newnode;

        printf("Node inserted successfully.\n");
        return;
    }

    temp = head;

    for(i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = value;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

    printf("Node inserted successfully.\n");
}

/* Delete from beginning */
void deleteBeginning()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

/* Delete from end */
void deleteEnd()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

/* Delete from position */
void deletePosition()
{
    int position, i;
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if(position < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for(i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

/* Display forward */
void displayForward()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Display backward */
void displayBackward()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

/* Search */
void search()
{
    int key, position = 1;
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d.\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element not found.\n");
}

/* Count nodes */
void countNodes()
{
    int count = 0;
    struct node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes: %d\n", count);
}

/* Main function */
int main()
{
    int choice;

    while(1)
    {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Search\n");
        printf("11. Count Nodes\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createList();
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

            case 8:
                displayForward();
                break;

            case 9:
                displayBackward();
                break;

            case 10:
                search();
                break;

            case 11:
                countNodes();
                break;

            case 12:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
