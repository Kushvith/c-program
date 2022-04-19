#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define Max 10
struct emp{
    int id;
    char name[25];
};
typedef struct emp Emp;
Emp emp[Max];
int a[Max];
int create(int num){
    int key;
    key = num % Max;
    return key;
}
int getemp(Emp emp[],int key){
    printf("Enter the employe id\n");
    scanf("%d",&emp[key].id);
    printf("enter the name\n");
    scanf("%s", emp[key].name);
    return key;
}
void display(){
    int ch,i;
    while(ch!=3){
        printf("1. display 2. enter your choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("hash table\n");
            printf("key\tnum\tid\tname\n");
            for(i=0;i<Max;i++)
            printf("%d\t%d\t%d\t%s\n",i,a[i],emp[i].id,emp[i].name);
            break;
        case 2:
            printf("hash table\n");
              printf("key\tnum\tid\tname\n");
            for(i=0;i<Max;i++)
            if(a[i]!=-1)
            printf("%d\t%d\t%d\t%s\n",i,a[i],emp[i].id,emp[i].name);
            break;
        case 3:
            exit(0);
            break;    
        default:
        printf("invalid choice\n");
            break;
        }
    }
}
void linear_prob(int key,int num)
{
    int count=0,flag=0;
    int i=0;
    while(i<Max)
    {
        if(a[i]!=-1)
            count++;
        i++;    
    }
    if(count == Max){
        printf("hash table is full\n");
        display();
        exit(0);
    }
    for(i=key;i<Max;i++){
        if(a[i]==-1){
            if(i!=key){
                printf("collision detected and number of probing required is %d",(i-key+1));

            }
            else
               printf("no of probing is 1\n");
                key = getemp(emp,i);
                a[i] = num;
                flag = 1;
                break;
           
        }
    }
    if(flag == 0){
        i = 0;
        while(i<key){
            if(a[i]==-1){
                printf("collision detected and number of probing %d",(Max-key+1));
                key = getemp(emp,i);
                a[i] = num;
                flag=1;
                break;
            }
            i++;
        }
    }   
}
void main(){
    int num,key,i,status=1;
    int ans =1;
    printf("collision handling linear probing\n");
    for(i=0;i<Max;i++)
        a[i] = -1;
    while(ans!=0){
        printf("enter the number\n");
        scanf("%d",&num);
        key = create(num);
        printf("1");
        linear_prob(key,num);
        printf("2");
        if(status == 1){
            printf("3");
            printf("do you want to continue (1\0)");
            scanf("%d",&ans);
        }
    }    
    display();
    getch();
}