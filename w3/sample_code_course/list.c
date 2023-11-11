/*    The sample code presented in the C for Everyone: Structured Programming
      for the list
      Kazem Bzesefidpar
      November 11, 2023*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{int data; struct list *next;} list;

int is_empty(const list *l){return (l==NULL);}

void print_list(list *h, char *title){
  printf("%s\n",title);
  while(h != NULL){
    printf("%d :",h->data);
    h = h->next;
  }
}

int main(int argc,char *argv[]){
  list list_of_int;
  list *head = NULL;
  head = malloc(sizeof(list));
  printf("sizeof(list) = %lu\n",sizeof(list));
  head->data = 5;
  head->next = NULL;
  print_list(head,"Single element list");
  printf("\n");
  return 0;
}
