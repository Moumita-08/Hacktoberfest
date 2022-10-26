#include<stdio.h>
#include<string.h>
int main()
{
    char str[50], str1[50]; int i, j=0;
    printf("enter a name: ");
    gets(str);
    strcat(str," ");
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
        {
            str1[j]=str[i];
            j++;
        }
        else{
            str1[j]='\0';
            if(str[i+1]=='\0')
            {
                printf("%s\n", str1);
            }
            else
            {
                printf("%c. ",str1[0]);
            }
            str1[0]='\0';
            j=0;
        
        }
    }
    return 0;
}