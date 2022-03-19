#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[4], n, elem, i, pos;
void create()
{
    printf("emter the size of array\n");
    scanf("%d", &n);
    printf("enter the elements to array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}
void display()
{
    int i;
    printf("the elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
}
void insert()
{
    printf("enter the position of element\n");
    scanf("%d", &pos);
    printf("enter the element to be inserted\n");
    scanf("%d", &elem);
    for (i = n - 1; i >= pos; i--)
        a[i + 1] = a[i];
    a[pos] = elem;
    n = n + 1;
}
void del()
{
    printf("enter the position of element to be deleted\n");
    scanf("%d", &pos);
    elem = a[pos];
    for (i = pos; i < n - 1; i++)
        a[i] = a[i + 1];
    n = n - 1;
    printf("Deleted element are %d", elem);
}
void main()
{
    int ch;
    while (ch != 5)
    {
        /* code */
        printf("\n1.create\t2.insert\t3.delete\t4.display\t5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            /* code */
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            del();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice try again");
            break;
        }
    }
    getch();
}