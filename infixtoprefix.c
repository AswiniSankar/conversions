/*
ip1:
(a+b^c)*d+e^5
+*+a^bcd^e5
ip2:
(a+b)*(a+b)
*+ab+ab
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char stack[100];
void infixtoprefix(char []);
int pre(char);
int main()
{
  int i,j=0;
  char s[100],input[100];
  scanf("%s",input);
  i=strlen(input)-1;
 // printf("%d\n",i);
  for(;i>=0;i--)
   {
   if(input[i]=='(')
    s[j++]=')';
   else if(input[i]==')')
    s[j++]='(';
   else
    s[j++]=input[i];
   }
  s[j]='\0';
  //printf("%s",s);
  infixtoprefix(s);
  printf("\n");
}
void infixtoprefix(char s[])
{
  int i,j=0;
  for(i=0;s[i];i++)
  {
     if((65<=s[i] && s[i]<=90) ||96<=s[i] && s[i]<=121)
        s[j++]=s[i];
     else if(s[i]=='(')
      { stack[++top]=s[i];
      }
      else if(s[i]==')')
      {  
         while(stack[top]!='(')
         {
         
         //  printf("%c",stack[top]);
           s[j++]=stack[top];
           top--;
         }
       top--;
      }
   else
   {
     
    while(pre(stack[top])>=pre(s[i]))
    {
  // printf("%c",stack[top]);
    s[j++]=stack[top];
    top--;
    }
    stack[++top]=s[i];
   }
  }
 
    while(top!=-1)
    {
   //printf("%c",stack[top--]);
    s[j++]=stack[top--];
   }
  s[j]='\0';
  for(i=strlen(s)-1;i>=0;i--)
    printf("%c",s[i]);
}
int pre(char c)
{
  if(c=='+'||c=='-')
    return 1;
  else if(c=='/' || c=='*')
    return 2;
  else if(c=='^')
    return 3;
  else if(c=='(')
    return 0;
}
