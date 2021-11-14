#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int i,n,*ptr;
    printf("enter the number\n");
    scanf("%d",&n);
    ptr = (int* )malloc(n*sizeof(int));
    if(ptr == NULL)
    {
        printf("memory not available\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        /* code */
        printf("ENter the value %d",i+1);
        scanf("%d",ptr+i);
    }
    for ( i = 0; i < n; i++)
    {
        /* code */
        printf("the value is %d",*(ptr + i));
    }
    getch();
    
}