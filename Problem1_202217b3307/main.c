#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define MAX 10
/* Define the required functions to create a list, insert into the list,
delete an element from the list, search and display the list */
void create();
void insert();
void deletion();
void search();
void display();
int a, b[20], n, p, e, f, i, pos;

void main()
{
    // clrscr();
    int ch;
    char g = 'y';
    do
    {
        printf("\n Main Menu");
        printf("\n 1.Create \n 2.Delete \n 3.Search \n 4.Insert \n 5.Display\n 6.Exit \n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);
        /* The following switch will call the appropriate choice provided
        by the user */
        switch(ch)
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
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo u want to continue:::");
        scanf("\n%c", &g);
    }
    /* The program is intended to run till we provide inputs other that ‘y’
    or ‘Y’ */
    while (g == 'y' || g == 'Y');
    getchar();
}
void create()
{
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    /* The loop should run till we get the ‘n’ inputs */
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the Element %d:", i + 1);
        scanf("%d", &b[i]);
    }
}
void deletion()
{
    printf("\nEnter the position u want to delete::");
    scanf("%d", &pos);
    if (pos >= n)
    {
        printf("\nInvalid Location::");
    }
    else
    {
        for (i = pos + 1; i < n; i++)
        {
            b[i - 1] = b[i];
        }
        n--;
    }
    printf("\nThe Elements after deletion");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", b[i]);
    }
}
void search()
{
    printf("\nEnter the Element to be searched:");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            printf("Value is in the %d Position", i);
            return;
        }
    }
    printf("Value %d is not in the list::", e);
}
void insert()
{
    printf("\n Enter the position u need to insert::");
    scanf("%d", &pos);
    if (pos >= n)
    {
        printf("\n invalid Location::");
    }
    else
    {
        for (i = MAX - 1; i >= pos - 1; i--)
        {
            b[i + 1] = b[i];
        }
        printf("\n Enter the element to insert:: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
    }
    printf("\n The list after insertion::\n");
    display();
}
void display()
{
    printf("\n The Elements of The list ADT are:");
    for (i = 0; i < n; i++)
    {
        printf("\n%d", b[i]);
    }
}
