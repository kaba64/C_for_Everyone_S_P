/*    The assignement for week 3 in the C for Everyone: Structured Programming
      The list functions :
      create_list, add_to_front, array_to_list are presented code in the course
      print_list has been modified.
      Other functions are written by Ka. Ba.
      November 14, 2023*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int MAXVALUE = 100; // The maximum number of the random variable
const int N = 100;        // The number of random variables

typedef struct list{int data; struct list *next;} list;

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

void print_list(const list *h, char *title){
  list *temp = h;  /* temp has been used since the input (list *h)
		      will be used later in the main, so it will remain the same */
  int count = 0;
  
  printf("%s : \n\n",title);
  printf(" ");
  while(temp != NULL){
    printf("%d ",temp->data);
    count+=1;
    if(count==5){
      printf("\n "); // At each row 5 elements are printed
      count = 0;
    }
    temp = temp->next;
  }
}

list * array_to_list(int d[],int size){
  list *head = create_list(d[0]);
  for(unsigned int i=1;i<size;++i)
    head = add_to_front(d[i],head);
  return head;
}

void generate_random_data(int data[]){
  for(unsigned int i=0;i<N;++i)
    data[i] = rand() % (MAXVALUE + 1);
}
/*swaps two adjacent integer data in the list element*/
void swap(list* h){
    int temp = h->data;
    h->data = h->next->data;
    h->next->data = temp;
}
/*bubble_sort : it sorts a list. its complexity is O(N2) so that it is not effecient for large data!*/
void bubble_sort(const list *h){
  list *ptr = NULL; // at the begining we initialize it to null so the first while covers all the list 
  list *temp;       // we do not want to modify the input pointer
  do{
    temp = h;      // at each time we intialize temp to input list
    do{
      if((temp->data) > (temp->next->data)) // comparison of two adjacent elements
	swap(temp);
      temp = temp->next;
    }while(temp->next!=ptr); // check that we reach to the end of unsorted list
    ptr = temp;              // now we move the above check criteria one element back
  }while(temp!=h->next);     // This is to check there were two elementw in the sort loop
}

int main(int argc,char *argv[]){
  int data[N];
  generate_random_data(data); // initialize the random data
  list *head = array_to_list(data,N);
  print_list(head,"Unsorted list");
  printf("\n");
  bubble_sort(head);
  print_list(head,"sorted list");
  printf("\n");
  return 0;
}
