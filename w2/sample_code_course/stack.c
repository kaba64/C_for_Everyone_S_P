/* The ADT STACK code presened in C for Everyone: Structured Programming
   Kazem Bazesefidpar
   November 10, 2023*/

#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN-1)

typedef struct stack{char s[MAX_LEN]; int top;} stack;
void reset(stack *stk){stk->top = EMPTY;}
void push(char c, stack *stk){
  stk->top++;
  stk->s[stk->top]=c;
}
char pop(stack *stk){return (stk->s[stk->top--]);}
char top(const stack *stk){return (stk->s[stk->top]);}

int is_empty(const stack *stk){return(stk->top==EMPTY);}
int is_full(const stack *stk){return(stk->top==FULL);}


int main(int argc, char *argv[]){
  stack stack_of_chr;
  char *str = "i am otto am i";
  char str_back[20];
  int i = 0;
  reset(&stack_of_chr);
  printf("original is : %s\n",str);
  while(str[i]!='\0'){
    printf("%c\n",str[i]);
    push(str[i++],&stack_of_chr);
  }
  i = 0;
  while(!is_empty(&stack_of_chr) && i<20)
    str_back[i++] = pop(&stack_of_chr);
  printf("reverse is : %s",str_back);
  printf("\n");
  return 0;
}
