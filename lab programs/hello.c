#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct student{
    int data;
    struct student *next;
};
typedef struct student node;
node *getnode(){
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
        printf("Insufficient space in the memory");
    else{
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
    }    
    return newnode;
}
node *create(node *head){
    node *newnode;
    newnode = getnode();
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
    return head;
}
void display(node *head){
    node *p;
    if(head == NULL){
        printf("the linked list is empty");
    }
    else
    {
        p = head;
        while(p!=NULL){
            printf("%d\n",p->data);
            p = p->next;
        }
    }
    
}
void main(){
    int n,ch;
    node *head;
    head = NULL;
    while(ch!=3){
        printf("1: insert\n 2: display\n 3: exit\n enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
           head = create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            exit(0);    
        default:
            printf("invalid choice try again\n");
            break;
        }
    }
}