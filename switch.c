#include<stdio.h>
#include<conio.h>
void main(){
    int n;
     const float theta_spacing = 0.07;
     const float phi_spacing = 0.02;
     const float R1 =1;
     const float R2 = 2;
     const float k2 = 5;
     const float K1 = 625*k2*3/(8*(R1+R2));
     printf("%f",k2);
     int i = 3;
     while(i>0){
         printf("Enter the n\n");
         scanf("%d",&n);
         if(n == 1){
             break;
         }
     }
    getch();
}