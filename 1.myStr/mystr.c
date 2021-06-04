#include <stdio.h>
#include <string.h>
#define MaxLen 20

int mystrstr(char *,char *);

int main()
{
 char str1[MaxLen+1], str2[MaxLen+1];
 int index;
 puts("Str1[] Text:");
 scanf("%20s",str1);
 puts("Str2[] Target:");
 scanf("%20s",str2);

 index = mystrstr(str1,str2);

 if(index == -1)
   puts("No Match");
 else
   printf("Match at Str1[%d]\n",index);
}
int mystrstr(char *str1, char *str2)
{
 char *p1 = str1, *p2;
 int index = 0;
 while(*str1){
   p2 = str2;
   while((*p1) && *p1++==*p2){
     //printf("p1 %s and p2 %s\n", p1,p2);
     p2++;
     //p1++;
   }
   //printf("outter p1 %s and p2 %s\n",p1,p2);
   if(*p2){
     ++index;
     ++str1;
     p1=str1;
   }
   else
     break;
 }
 if(*str1)
   return index;
 else
   return -1;
}






