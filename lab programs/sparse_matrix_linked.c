#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i ,j,k;
struct Node
{
    /* data */
    int row,col,value;
    struct Node *next;
};
typedef struct Node node;
node *create(node *head,int ele,int row,int col){
    node *temp,*r;
    temp = head;
    if(temp==NULL){
        temp = (node*)malloc(sizeof(node));
        temp->row =i;
        temp->col=j;
        temp->value = ele;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        while (temp->next!=NULL)
        {
            /* code */
            temp = temp->next;
        }
        r = (node*)malloc(sizeof(node));
        r->row = i;
        r->col = j;
        r->value = ele;
        r->next = NULL;
        temp->next = r;
    }
    return head;
}
void display(node *head){
    node *temp,*r,*s;
    temp = r= s = head;
    printf("the row address: ");
    while(temp!=NULL){
        printf("%d\t",temp->row);
        temp = temp->next;
    }
    printf("\n");
    printf("the col address: ");
    while(r!=NULL){
        printf("%d\t",r->col);
        r = r->next;
    }
    printf("\n");
    printf("the value:\t ");
    while(s!=NULL){
        printf("%d\t",s->value);
        s = s->next;
    }
    printf("\n");

}
void main(){
    int sparse[4][5] = {
        {0,0,3,0,4},{1,8,3,0,4},{0,0,0,0,0},{1,0,0,3,8}
    };
    int size = 0;
    node *head = NULL;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 5; j++)
        {
            if(sparse[i][j]!=0){
                head = create(head,sparse[i][j],i,j);
                size++;
            }
            
        }
        
    }
    display(head);
            printf("%d",size);
}