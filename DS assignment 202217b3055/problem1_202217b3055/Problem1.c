#include <stdio.h>
#define MAX 10

int b[MAX], n, i, pos;

void create();
void deletion();
void search();
void insert();
void display();

int main()
{
    int ch;
    char g = 'y';

    do
    {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display\n6. Exit \n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            deletion();
            break;
        case 3:
            search();
            break;
        case 4:
            insert();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0; 
        default:
            printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g); 
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create()
{
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion()
{
    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n)
    {
        printf("\nInvalid Location\n");
    }
    else
    {
        for (i = pos; i < n - 1; i++)
        {
            b[i] = b[i + 1];
        }
        n--;

        printf("\nThe elements after deletion:\n");
        display();
    }
}

void search()
{
    int e, flag = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            printf("Element %d is found at position %d\n", e, i);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Element %d is not found in the list\n", e);
    }
}

void insert()
{
    int p;
    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        printf("\nInvalid Location\n");
    }
    else
    {
        printf("Enter the element to insert: ");
        scanf("%d", &p);

        for (i = n - 1; i >= pos; i--)
        {
            b[i + 1] = b[i];
        }
        b[pos] = p;
        n++;

        printf("\nThe list after insertion:\n");
        display();
    }
}

void display()
{
    if (n == 0)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        printf("\nThe elements of the list are:\n");
        for (i = 0; i < n; i++)
        {
            printf("%d ", b[i]);
        }
        printf("\n");
    }
}
