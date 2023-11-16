/*The presented code in week 4 of the course*/

#include<stdio.h>
#include<stdlib.h> // exit()

void print_file(FILE *fptr){
  int c;
  rewind(fptr);      /*rewind() is used to move the file 
		       pointer to the beginning of the file stream*/
  while((c=getc(fptr))!=EOF)
    putc(c,stdout);
}

void double_space(FILE *ifp, FILE *ofp){
  int c;
  rewind(ifp);
  while((c=getc(ifp))!=EOF){
    putc(c,ofp);
    if(c=='\n')
      putc('\n',ofp);
  }
}

/*After compiling the code, use the following on the command line to run: executable_name data_file_name*/

int main(int argc, char *argv[]){
  FILE *ifp, *ofp;
  if(argc!=3){
    printf("Need executable inputfile outputfile\n");
    exit(1);
  }
  ifp = fopen(argv[1],"r+"); // read and write file
  ofp =	fopen(argv[2],"w+"); // read and write file
  printf("my %s file as read s \n\n",argv[1]);
  print_file(ifp);
  printf("\n\n");
  double_space(ifp,ofp);
  print_file(ofp);
  printf("\n\n");
  fclose(ifp);
  fclose(ofp);
  return 0;
}
