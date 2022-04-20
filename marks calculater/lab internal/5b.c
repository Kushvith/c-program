#include<stdio.h>
#include<conio.h>
#include<math.h>
void tower(int n,int source,int temp, int destination){
    if(n==0)
        return;
    tower(n-1,source,destination,temp);
    printf("\n moves disc %d from %c to %c",n,source,destination);
    tower(n-1,temp,source,destination);    
}
void main(){
    int n;
    printf("enter rhe number of disc:\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\n total number of moves are %d",(int)pow(2,n)-1);
}
