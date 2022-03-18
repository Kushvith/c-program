#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
void read_sparse(int b[3][20]);
void display(int b[3][20]);
void add(int b1[3][20],int b2[3][20],int b3[3][20]);
void main(){
    int b1[3][20],b2[3][20],b3[3][20];
    read_sparse(b1);
    read_sparse(b2);
    add(b1,b2,b3);
    display(b3);
    exit(0);
}
void read_sparse(int b[3][20]){
    int i , t,m,n;
    printf("Enter the number of rows and columns\n");
    scanf("%d%d",&m,&n);
    printf("no of the non-zero elements\n");
    scanf("%d",&t);
    b[0][0] = m;
    b[1][0] = n;
    b[2][0] = t;
    for ( i = 1; i < t; i++)
    {
        /* code */
        printf("Enter the triples(row column and value)\n");
        scanf("%d%d%d",&b[0][i],&b[1][i],&b[2][i]);
    }
    
}
void add(int b1[3][20],int b2[3][20],int b3[3][20]){
    int t1,t2,i,j,k;
    if(b1[0][0]!=b2[0][0] || b1[1][0]!=b2[1][0]){
        printf("Invalid matrix size\n");
        exit(0);
    }
    t1 = b1[2][0];
    t2 = b2[2][0];
    i=j=k = 0;
    b3[0][0] = b1[0][0];
    b3[1][0] = b1[1][0];
    while (i<=t1&&j<=t2)
    {
        if(b1[0][i]<b2[0][i]){
            //row numbers are not equal
            b3[0][k] = b1[0][i];
            b3[1][k] = b1[1][i];
            b3[2][k] = b1[2][i];
            k++;i++;
        }
        else if(b2[0][j]<b2[0][i]){
            // row number are not equal
            b3[0][k] = b2[0][j];
            b3[1][k] = b2[1][j];
            b3[2][k] = b2[2][j];
            k++;j++;
        }
        else if(b1[1][i]<b2[1][j]){
            //  rows are equal compare columns
            b3[0][k] = b1[0][i];
            b3[1][k] = b1[1][i];
            b3[2][k] = b3[2][i];
            k++;i++;
        }
        else if(b2[1][j]<b1[1][i]){
            b3[0][k] = b2[0][j];
            b3[1][k] = b2[1][j];
            b3[2][k] = b2[2][j];
            k++;j++;
        }
        else{
            // rows and columns are equal
            b3[0][k] = b1[0][i];
            b3[2][k] = b1[2][i] + b2[2][j];
            k++;j++;i++;
        }
        while (i<=t1)
        {
            // copy remaing terms from b1
            b3[0][k] = b1[0][i];
            b3[1][k] = b1[1][i];
            b3[2][k] = b1[2][i];
            i++;k++;
        }
        while(j<=t2)
        {
            b3[0][k] = b2[0][j];
            b3[1][k] = b2[1][j];
            b3[2][k] = b2[2][j];
            j++;k++;
        }
        b3[0][2] = k-1;        
    }
}
void display(int b3[3][20]){
    int i,t;
    t = b3[0][2];
    printf("row\tcolumn\tvalue");
    for (i = 1; i < t; i++)
    {
        printf("\n%d\t%d\t%d",b3[0][i],b3[1][i],b3[2][i]);
    }
    
}