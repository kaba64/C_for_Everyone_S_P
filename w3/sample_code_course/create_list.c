/*    The sample code presented in the C for Everyone: Structured Programming
      for the list
      Kazem Bzesefidpar
      November 11, 2023*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{int data; struct list *next;} list;

int is_empty(const list *l){return (l==NULL);}

list * create_list(int d){
  list *head = malloc(sizeof(list));
  head->data = d;
  head->next = NULL;
  return head;
}

list * add_to_front(int d, list *h){
  list *head = create_list(d);
  head->next = h;
  return head;
}

void print_list(list *h, char *title){
  printf("%s\n",title);
  while(h != NULL){
    printf("%d :",h->data);
    h = h->next;
  }
}

list * array_to_list(int d[],int size){
  list *head = create_list(d[0]);
  for(unsigned int i=1;i<size;++i)
    head = add_to_front(d[i],head);
  return head;
}

int main(int argc,char *argv[]){
  int data[6] = {1,2,3,4,5,6};
  list *head = array_to_list(data,6);
  print_list(head,"Convert array to list");
  printf("\n");
  return 0;
}
