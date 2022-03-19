#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define Max 4
struct Node
{
    /* data */
    char usn[20];
    char name[30];
    char branch[10];
    int sem;
    char phno[13];
    struct Node *link;
};
typedef struct Node node;

node *getnode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("enter the usn,name,branch,sem and phno in sequence\n");
    _flushall();
    gets(newnode->usn);
    _flushall();
    printf("%d",1);
    gets(newnode->name);
    _flushall();
    printf("%d",0);
    gets(newnode->branch);
    printf("%d",1);
    scanf("%d",&newnode->sem);
    printf("%d",2);
    _flushall();
    gets(newnode->phno);
    printf("%d",3);
    newnode->link = NULL;
    return newnode;
}
node *create(node *head)
{
    node *newnode = getnode();
    if (head == NULL)
        head = newnode;
    else
    {
        newnode->link = head;
        head = newnode;
    }
    return head;
}
int countnodes(node *head)
{
    node *p;
    int count = 0;
    p = head;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}
node *insert_front(node *head)
{
    if (countnodes(head) == Max)
    {
        printf("Linked list is full\n");
    }
    else
    {
        head = create(head);
    }
    return head;
}
node *insert_rear(node *head)
{
    if (countnodes(head) == Max)
        printf("Linked list is full");
    else
    {
        node *p, *newnode = getnode();
        if (head == NULL)
            head = newnode;
        else
        {
            p = head;
            while (p->link != NULL)  
            p = p->link;
            p->link = newnode;
        }
        return head;
    }
}
node *del_front(node *head)
{
    node *p;
    if (countnodes(head) == 0)
        printf("linked list is empty\n");
    else
    {
        p = head;
        head = p->link;
        free(p);
    }
    return head;
}
node *del_rear(node *head)
{
    node *p, *temp;
    if (countnodes(head) == 0)
        printf("Linked list is empty");
    else
    {
        printf("%d",1);
        p = head;
        
        while (p->link!=NULL)
        {
            temp = p;
            p = p->link;
        }
        temp->link = NULL;
        free(p);
        printf("last node deleted\n");
    }
    return head;
}
void display(node *head)
{
    node *p;
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        p = head;
        printf("---Student databse---\n");
        printf("\nusn\tname\tbranch\tsem\tphno\n");
        while (p != NULL)
        {
            printf("%s,%s,%s,%d,%s\n", p->usn, p->name, p->branch, p->sem, p->phno);
            p = p->link;
        }
    }
}
node *stack(node *head)
{
    int ch;
    while (ch != 3)
    {
        printf("1.push(insert_rear)\t 2.pop(delete_rear)\t3. exit\nenter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            /* code */
            head = insert_rear(head);
            break;
        case 2:
            head = del_rear(head);
            break;
        case 3:
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return head;
}
node *queue(node *head)
{
    int ch;
    while (ch != 3)
    {
        printf("1.enqueue(insert_rear)\t 2.dequeue(delete_front)\t3. exit\nenter your choice\n");
        scanf("%d",&ch);
       switch (ch)
        {
        case 1:
            /* code */
            head = insert_rear(head);
            break;
        case 2:
            head = del_front(head);
            break;
        case 3:
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
    return head;
}
void main()
{
    int ch, total_nodes = 0, n, i;
    node *head;
    head = NULL;
    printf("studentdatabase\n");
    while (ch != 9)
    {
        printf("1.create\t2.display\t3.insert_front\t4.insert_rear\t5.del_front\t6.del_rear\t7.stack\t8.queue\t9.exit\nenter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            /* code */
            printf("enter the number of students\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                head = create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insert_front(head);
            break;
        case 4:
            head = insert_rear(head);
            break;
        case 5:
            head = del_front(head);
            break;
        case 6:
            head = del_rear(head);
            break;
        case 7:
            head = stack(head);
            break;
        case 8:
            head = queue(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}