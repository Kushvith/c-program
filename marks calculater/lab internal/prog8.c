#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define Max 4
struct Node
{
    /* data */
    int ssn;
    char name[20];
    char dept[10];
    char designation[20];
    int salary;
    char phno[10];
    struct Node *prev;
    struct Node *next;
};
typedef struct Node node;

node *getnode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("enter the ssn,name,dept,designation,salary,phno in sequence\n");
    scanf("%d", &newnode->ssn);
    _flushall();
    gets(newnode->name);
    _flushall();
    gets(newnode->dept);
    _flushall();
    gets(newnode->designation);
    scanf("%d", &newnode->salary);
    _flushall();
    gets(newnode->phno);
    newnode->next = newnode->prev = NULL;
    return newnode;
}
node *create(node *head)
{
    node *newnode, *p;
    newnode = getnode();
    if (head == NULL)
        head = newnode;
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
        p->prev = p;
    }
    return head;
}
int countnodes(node *head)
{
    int count = 0;
    node *p;
    p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
node *insert_rear(node *head)
{
    node *x;
    if (countnodes(head) == Max)
        printf("linked list is full");
    else
    {
        x = create(head);
    }
    return x;
}
node *insert_front(node *head)
{
    node *x;
    if (countnodes(head) == Max)
        printf("linked list is full");
    else
    {
        x = getnode();
        head->prev = x;
        x->next = head;
        head = x;
    }
    return head;
}
node *delete_front(node *head)
{
    node *p;
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        p = head;
        head = p->next;
        head->prev = NULL;
        free(p);
    }
    return head;
}
node *delete_rear(node *head)
{
    node *p, *q;
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }
    return head;
}
void display(node *head)
{
    node *p;
    printf("student database\n");
    if (head == NULL)
        printf("student database is empty\n");
    else
    {
        printf("ssn\tname\tdept\tdesignation\tsalary\tphno\n");
        p = head;
        while (p != NULL)
        {
            printf("%d\t%s\t%s\t%s\t%d\t%s\n", p->ssn, p->name, p->dept, p->designation, p->salary, p->phno);
            p = p->next;
        }
    }
}
node *doublequeue(node *head)
{
    int ch, ch1, ch2;
    printf("double ended queue\n");
    while (ch != 3)
    {
        printf("1.insert_rear&&delete_front\t2.insert_front&&delete_rear\t3.exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            while (ch1 != 3)
            {
                printf("1.insert_rear\t2.delete_front\t3.exit\n");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    head = insert_rear(head);
                    break;
                case 2:
                    head = delete_front(head);
                    break;
                case 3:
                    break;
                }
            }
            break;
        case 2:
            while (ch2 != 3)
            {
                printf("1.insert_front\t2.delete_rear\t3.exit\n");
                scanf("%d", &ch2);
                switch (ch2)
                {
                case 1:
                    head = insert_front(head);
                    break;
                case 2:
                    head = delete_rear(head);
                    break;
                case 3:
                    break;
                }
            }
            break;

        default:
            break;
        }
    }
    return head;
}
void main()
{
    int ch, i, n;
    node *head;
    head = NULL;
    while (ch != 8)
    {
        printf("--employee database---\n");
        printf("1.create\t2.display\t3.insert_rear\t4.insert_front\t5.delete_front\t6.delete_rear\t7.double ended queue\t8.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("no employees to be entered\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                head = create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insert_rear(head);
            break;
        case 4:
            head = insert_front(head);
            break;
        case 5:
            head = delete_front(head);
            break;
        case 6:
            head = delete_rear(head);
            break;
        case 7:
            head = doublequeue(head);
            break;
        case 8:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
}