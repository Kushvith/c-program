#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    /* data */
    int flag,px,py,pz,cf;
    struct Node *next;
};

typedef struct Node node;

node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("insufficent memory\n");
        return 0;
    }
    else
        return newnode;    
}
node *insert_rear(int cf,int x,int y,int z,node *head){
    node *temp,*cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    cur = head;
    while(cur->next!=head)
        cur = cur->next;
    cur->next = temp;
    temp->next = head;
    return head;    
}
node *read_poly(node *head){
    int px,py,pz,ch=1,cf;
    while(ch!=0){
        printf("enter the co-efficent\n");
        scanf("%d",&cf);
        printf("enter the power value of x,y,z if(0 indicates no term)\n");
        scanf("%d%d%d",&px,&py,&pz);
        printf("3");
        head = insert_rear(cf,px,py,pz,head);
        printf("2");
        printf("do you want to enter one more term (if no enter 0)\n");
        scanf("%d",&ch);
        return head;
    }
}
node *add_poly(node *h1,node *h2,node *h3){
    node *p1,*p2;
    int x1,y1,z1,cf1,x2,y2,z2,cf,cf2;
    p1 = h1->next;
    while(p1!=h1){
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->next;
        while(p2!=h2){
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if(x1==x2&&y1==y2&&z1==z2)
                break;
            p2 = p2->next;    
        }
        if(p2!=h2){
            cf = cf1+cf2;
            p2->flag = 1;
            if(cf!=0)
               h3 =  insert_rear(cf,x1,y1,z1,h3);
        }
        else{
            h3 = insert_rear(cf1,x1,y1,z1,h3);
        }
        p1 = p1->next;
    }
    p2 = p2->next;
    while (p2!=h2)
    {
        /* code */
        if(p2->flag!=1){
          h3 =   insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3);
        }
        p2 = p2->next;
    }
    return h3;
}
void evaluate(node *head){
    int x,y,z;
    float result = 0;
    node *p;
    p = head->next;
    printf("enter the value of x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    while (p!=head)
    {
        /* code */
        printf("%d",p->cf);
        result = result+((p->cf)*(pow(x,p->px))*(pow(y,p->py))*(pow(z,p->pz)));
        p = p->next;
    }
    printf("the result is %f\n",result);
}
void display(node *head){
    node *p;
    if(head->next == head)
        printf("polynomial does not exists\n");
    else{
        p = head->next;
        while(p!=head){
            printf("%dx^%dy^%dz^%d\n",p->cf,p->px,p->py,p->pz);
            if(p->next!=head)
             printf("+");
            p = p->next; 
        }
    }    
}
void main(){
    node *h1,*h2,*h3;int choice;
    h1 = getnode();
    h2 = getnode();
    h3 = getnode();
    h1->next = h1;
    h2->next = h2;
    h3->next = h3;
    while(choice!=3){
        printf("1.evaluating polynomial\n2.adding two polynomial\n 3.exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            /* code */
            h1 = read_poly(h1);
            printf("the polynimial is \n");
            display(h1);
            evaluate(h1);
            break;
        case 2:
            h1 = read_poly(h1);
            printf("the polynomial 1:\n");
            display(h1);
            h2 = read_poly(h2);
            printf("the polynomial 2:\n");
            display(h2);
            h3 = add_poly(h1,h2,h3);
            printf("the polynomial addition is :\n");
            display(h3);
            break;
        case 3: exit(0);       
        
        default:
        printf("invalid choice\n");
            break;
        }
    }
}