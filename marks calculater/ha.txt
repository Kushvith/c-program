#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*intializing the arguments*/
int main(int argc,char*argv[argc+1]){      
    int rowcol= atoi(argv[1]);
    int asterisk= atoi(argv[2]);
    /*validating the user to enter the values between 2 to 9 and 
    how many 0 to 5 asterisk(*)*/
    if(rowcol<10 && rowcol>1 && asterisk>=0 && asterisk<=5){
        /*iterating the row value*/
      for(int i=1;i<=rowcol;i++){
          /*iterating the columns value*/
        for(int j=1;j<=rowcol;j++){
            /*validating and printing  the asterisks(*) else 0's */
          if(i==j || fabs(i-j)<=asterisk)
            printf(" * ");
            else
            printf(" 0 ");
        }
        /*end of row*/
        printf("\n");
      }
    }
    else
    printf("INVALID INPUT");
    return 0;
}