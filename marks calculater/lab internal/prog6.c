#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Max 4
int front = 0, rear = -1, count = 0;
char queue[Max];
char item;
void insert()
{
    if (count == Max)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("enter the character or item to queue\n");
        scanf(" %c", &item);
        rear = (rear + 1) % Max;
        queue[rear] = item;
        count++;
    }
}
void del()
{
    if (count == 0)
        printf("queue is empty");
    else
    {
        item = queue[front];
        front = (front + 1) % Max;
        printf("deleted item is %c", item);
        count--;
    }
}
void display()
{
    int i = front;
    if (count == 0)
        printf("queue is empty\n");
    else
    {
        printf("queue contents are:\n");
        while (i != (rear + 1))
        {
            printf("%c\t", queue[i]);
            i = (i+1)%Max;
        }
         printf("\n");
    }
}
int main()
{
    int ch, i;
    while (ch != 4)
    {
        printf("1.create\t 2.delete\t3.display\t4.exit\nenter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            /* code */
            
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return 0;
}