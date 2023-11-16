/*      The assignmen for the week 4 of the course : C for Everyone: Structured Programming
	Kazem Bazesefidpar
	November 16, 2023*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Function to read the first element of the file pointed by fptr
It checks if the first element is an intetger, otherwise it will print error on the screen*/
int data_size(FILE *fptr,char *filename){
  int sz;
  char c;
  
  rewind(fptr);
  if(fscanf(fptr,"%d",&sz) == 1){
    return sz;
  }
  else{
    fprintf(stderr,"The first element of the data file (%s) is not an integer\n",filename);
    exit(3);
  }
} 
/*function to read the data[1] ... data[sz-1]
it will push error if the the number of the data in the file is not equal to sz*/
void read_data(FILE *fptr,int d[],char *filename,int sz){
  int count = 0;
  while(fscanf(fptr,"%d",&d[count]) == 1)
    count++;
  if(count!=sz){
    fprintf(stderr,"The number of element in data file (%s) is not %d\n",filename,sz);
    exit(3);
  }
}
/*Function to compute the average of d[]*/
double average(int d[], int sz){
  double avd = 0.0;
  for(int i = 0;i<sz;i++)
    avd+=d[i];
  return (avd/sz);
}
int max_value(int d[],int sz){
  int max_v = d[0]; // initialize to the first element
  
  for(int i=1;i<sz;++i)
    max_v = (max_v>d[i]) ? max_v:d[i]; // ternary to find maximum value
  return max_v;
}

int main(int argc,char *argv[]){
  FILE *ifp, *ofp;
  int size, max_v;
  double av_d;
  
  if(argc==1){
    printf("Please enter the name of the data file\n");
    exit (1);
  }else if((ifp=fopen(argv[1],"r"))==NULL) {// Check if the file has been opened successfully
    fprintf(stderr,"%s: can't open %s\n",argv[0],argv[1]); /*argv[1] is the name of file to be 
							     open passed by command line argument*/
    exit(2);
  }else{
    size = data_size(ifp,argv[1]);
  }
  int data[size];
  read_data(ifp,data,argv[1],size);
  av_d = average(data,size); // compute the average of data
  max_v = max_value(data,size);
  printf("The avergae value of the data is %lf\n",av_d);
  printf("The maximum value of the data is %d\n",max_v);
  ofp = fopen("answer-hw3","w");
  fprintf(ofp,"The avergae value of the data is %lf\n",av_d);
  fprintf(ofp,"The maximum value of the data is %d\n",max_v);
  fclose(ifp);
  fclose(ofp);
  return 0;
}
