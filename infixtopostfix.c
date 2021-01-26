/*
(a+b)*c+(d-a)
ab+c*da-+
((4+8)(6-5))/((3-2)(2+2))
48+65-32-22+/
*/
#include<stdio.h>
#include<stdlib.h>
int top=-1;
char stack[100];
void infixtopostfix(char []);
int pre(char);
int main()
{
  int i,j;
  char s[100];
  scanf("%s",s);
  infixtopostfix(s);
  printf("\n");
}
void infixtopostfix(char s[])
{
  int i;
  for(i=0;s[i];i++)
  {
     if((65<=s[i] && s[i]<=90) ||96<=s[i] && s[i]<=121)
        printf("%c",s[i]);
     else if(s[i]=='(')
      { stack[++top]=s[i];
      }
      else if(s[i]==')')
      {  
         while(stack[top]!='(')
         {
         
           printf("%c",stack[top]);
           top--;
         }
       top--;
      }
   else
   {
     
    while(pre(stack[top])>=pre(s[i]))
    {
   printf("%c",stack[top]);
    top--;
    }
    stack[++top]=s[i];
   }
  }
 
    while(top!=-1)
    {
   printf("%c",stack[top--]);
   }
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
