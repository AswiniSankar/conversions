/*
++a*bcd
abc*+d+
*/
#include<stdio.h>
#include<string.h>
char stack[30][30],arr[30];
int tops=-1,topa=-1;
int isoperator(char);
void pushs(char *);
char *pops();
void pusha(char );
char popa();
void prefixtopostfix(char []);
int main()
{
  char str[30];
  scanf("%s",str);
  prefixtopostfix(str);
  printf("\n");
}
void prefixtopostfix(char str[])
{
  char temp[30],ch[2],op1[30],op2[30],c,st[2];
  int i,co=0;
  for(i=strlen(str)-1;i>=0;i--)
  {
    if(isoperator(str[i]))
    {
     pusha(str[i]);
     strcpy(op1,pops());
     strcpy(op2,pops());
     strcpy(temp,op1);
     strcat(temp,op2);
     c=popa();
     st[0]=c;st[1]='\0';
     strcat(temp,st);
     pushs(temp);
    } 
    else
    {
   ch[0]=str[i];
   ch[1]='\0';
   pushs(ch);
    }
  }
 if(tops==1)
 {
 
     strcpy(op1,pops());
     strcpy(op2,pops());
     strcpy(temp,op1);
     strcat(temp,op2);
     c=popa();
     st[0]=c;st[1]='\0';
     strcat(temp,st);
     pushs(temp);
 }
 printf("%s\n",stack[tops]);
}
int isoperator(char s)
{
   if(s=='^'||s=='/'||s=='*'||s=='+'||s=='-')
     return 1;
   return 0;
}
void pushs(char *ch)
{
  tops++;
  strcpy(stack[tops],ch);
}
char *pops()
{
 return (stack[tops--]);
}
void pusha(char c)
{
  arr[++topa]=c;
}
char popa()
{


  return arr[topa--];
}
