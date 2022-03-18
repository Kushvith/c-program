#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct NODE
{
    int cf, px, py, pz;
    struct Node *next;
    int flag;
};
typedef struct NODE node;
node *getnode()
{
    node *x;
    x = (node *)malloc(sizeof(node));
    if (x==NULL)
    {
        /* code */
        printf("unsufficient space");
        return 0;
    }
    else
    {
        return x;
    }
}
node *insert_rear(int cf, int x, int y, int z, node *head)
{
    node *temp, *cur;
    temp = getnode(1);
    temp->cf=cf;
    temp->px=x;
    temp->py=y;
    temp->pz=z;
    cur=head->next;
    while (cur->next!= head)
    {
        cur=cur->next;
    }
    cur->next=temp;
    temp->next=head;
    return head;
}
node *read_poly(node *head)
{
    int cf, x, y, z, ch = 1;
    while (ch != 0)
    {
        /* code */
        printf("enter the co-efficient\n");
        scanf("%d", &cf);
        printf("enter the value of x\n");
        scanf("%d", &x);
        printf("enter the value of y\n");
        scanf("%d", &y);
        printf("enter the value of z\n");
        scanf("%d", &z);
        head = insert_rear(cf, x, y, z, head);
        printf("enter the zero for end or one to continue\n");
        scanf("%d", &ch);
    }
    return head;
}
node *add_poly(node *h1, node *h2, node *h3)
{
    node *p1, *p2;
    int x1, y1, z1, x2, y2, z2, cf1, cf2, cf;
    p1=h1->next;
    while (p1!=h1)
    {
        /* code */
        x1=p1->px;
        y1=p1->py;
        z1=p1->pz;
        cf1=p1->cf;
        p2=h2->next;
        while (p2!=h2)
        {
            x2=p2->px;
            y2=p2->py;
            z2=p2->pz;
            cf2=p2->cf;
            if (x1==x2&&y1==y2&&z1==z2)
                break;
            p2=p2->next;
        }
        if (p2!=h2)
        {
            cf=cf1+cf2;
            p2->flag=1;
            if (cf!=0)
                h3=insert_rear(cf, x1, y1, z1, h3);
        }
        else
        {
            h3=insert_rear(cf, x1, y1, z1, h3);
        }
        p1=p1->next;
    }
    p2=h2->next;
    while (p2!=h2)
    {
        /* code */
        if (p2->flag==0)
        {
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        }
        p2=p2->next;
    }
    return h3;
}
void evaluate(node *head)
{
    int x, y, z;
    float result = 0;
    node *p;
    printf("Enter the values x,y and z");
    scanf("%d%d%d", &x, &y, &z);
    p = head->next;
    while (p!=head)
    {
        /* code */
        result = result + (p->cf) * (pow(x, p->px)) * (pow(y, p->py)) * (pow(z, p->pz));
    }
    printf("the result of the evaluation is : %f\n", result);
}
void display(node *head)
{
    node *temp;
    if (head->next==head)
    {
        /* code */
        printf("polynomial does not exists\n");
        return;
    }
    else
    {
        temp=head->next;
        printf("\n");
        while (temp!=head)
        {
            /* code */
            printf("%dx^%dy^%dz^%d\n", temp->cf, temp->px, temp->py, temp->pz);
            if (temp->next!=head)
                printf(" + ");
            temp=temp->next;
        }
        printf("\n");
    }
}
void main(){
    node *h1,*h2,*h3;
    int ch;
    h1 = getnode();
    h2 = getnode();
    h3 = getnode();
    h1->next=h1;
    h2->next=h2;
    h3->next=h3;
    while(ch!=3){
        printf("1: evaluation\n2: sum of two polynomial\n3: exit\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the evaluation for polynomial\n");
            h1 = read_poly(h1);
            display(h1);
            evaluate(h1);
            break;
        case 2:
            printf("enter the polynomial 1 and two in order\n");
            h1=read_poly(h1);
            h2=read_poly(h2);
            h3=add_poly(h1,h2,h3);
            printf("polynomial 1\n");
            display(h1);
            printf("polynomial 2\n");
            display(h2);
            printf("polynomial 3\n");
            display(h3);
            break;
        case 3:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
    getch();
}