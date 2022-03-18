#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
char str[100],pat[50],rep[50],ans[100];
int i,j,c,m,k,flag=0;

void stringmatch(){
    i=m=j=c=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;m++;
            if(pat[i]=='\0'){
                flag = 1;
                for(k=0;rep[k]!='\0';k++,j++)
                    ans[j] = rep[k];
                i = 0;
                c = m;    
            }
        }
        else{
            ans[j] = str[c];
            j++;c++;
            m=c;i=0;
        }
    }
}
void main(){
    printf("\nEnter the main string\n");
    gets(str);
    printf("enter pattern string \n");
    _flushall();
    gets(pat);
    printf("enter the replace string\n");
    _flushall();
    gets(rep);
    stringmatch();
    if(flag == 1){
        printf("the replacement string is %s",ans);
    }
    else{
        printf("Pattern doesnot match\n");
    }
    getch();
}