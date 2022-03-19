#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Max 4
int stack[Max], item;
int ch, count = 0, status = 0;
int top = -1;
void push(int item)
{
    if (top == Max - 1)
    {
        printf("stack is overflow");
    }
    else
    {
        stack[++top] = item;
        status++;
    }
}
int pop()
{
    int ret;
    if (top == -1)
    {
        printf("stack is empty");
    }
    else
    {
        ret = stack[top--];
        status--;

        return ret;
    }
}
void palindrome()
{
    int i, temp;
    int j = -1;
    printf("%d", j);
    temp = top + 1;
    for (i = 0; i < temp; i++, j++)
    {
        printf("%d", 1);
        if (stack[i] == pop())
        {
            count++;
        }
    }
    if (temp == count)
    {
        printf("\n stack elemets are palindre");
    }
    else
    {
        printf("\n stack contents are not palindrome");
    }
    count = 0;
    top = j;
    printf("%d", top);
}
void display()
{
    int i;
    printf("stack content is:%d\n", top);
    for (i = 0; i <= top; i++)
    {
        printf("%d\t", stack[i]);
    }
}
void main()
{
    int a;
    while (ch != 5)
    {
        printf("\n1.push\t2.pop\t3.palindrome\t4.display\t5.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            /* code */
            printf("enter the item to be inserted\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            a = pop();
            printf("the poped element is : %d", a);
            break;
        case 3:
            palindrome();
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
}