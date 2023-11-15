/*The presented code in the course for week 4*/

#include <stdio.h>

#define MAX_HW 20

void read_data(FILE *ptr, int d[], int *size){
  *size = 0;
  while(fscanf(ptr,"%d",&d[*size]) == 1)
    (*size)++;
}

void print_data(int d[], int size){
  for(unsigned int i =0;i<size;i++){
    printf("%d\t",d[i]);
    if((i+1)%10 == 0)
      printf("\n");
  }
}

double average(int d[], int size){
  double avg = 0.0;
  for(unsigned int i = 0;i<size;i++)
    avg+=d[i];
  return (avg/size);
}

int main(int argc, char *argv[]){
  int i, sz = MAX_HW;
  FILE *ifp;
  int d[MAX_HW] = {100,0};

  if((ifp = fopen("myhw","r"))==NULL){
    printf("Data cannot be opened\n");
    return 1;
  }
  read_data(ifp,d,&sz);
  printf("my %d homework scores are:\t",sz);
  print_data(d,sz);
  printf("\nAverage score was %10f\n",average(d,sz));
  fclose(ifp);
  return 0;
}
