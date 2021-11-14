#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
int var[] = {10, 100,200};
int i,*ptr[3];
for (i = 0; i < 3; i++)
{
    /* code */
    ptr[i] = &var[i];
}
 for ( i = 0; i < 3; i++)
 {
     /* code */
     printf("the value of var[%d] = %d\n",i,*ptr[i]);
 }
 
}