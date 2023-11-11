/* The assignment for week 2 of C for Everyone: Structured Programming
   Ka. Ba.
   November 10, 2023*/

#include <stdio.h>

typedef enum month{jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec} month; // enum for months
typedef struct date{month m; int d;} date; // struct for date

/*The followng function gets *ptr_in pointtng to today (input)
 *ptr_out pointtng to tomorrow (output)
 max is the maximum day of each month (input)
 With the above inputs, it decides on shifting the day and month*/
void shift_month_day(const date *ptr_in, date *ptr_out, int max){
  if(ptr_in->d < max){
    ptr_out->d = ptr_in->d + 1;
    ptr_out->m = ptr_in->m;
  }else{
    ptr_out->d = 1;
    ptr_out->m = (ptr_in->m +1)%12;
  }
}
/*This function finds the next day *ptr_in pointtng to today (input)
 *ptr_out pointtng to tomorrow (output)
 The if condition is chosen based on the calendar*/
void nextday(const date *ptr,date *temp){
 
  if(ptr->m == 1 || ptr->m == 3 || ptr->m == 5 || ptr->m == 7 || ptr->m == 8 || ptr->m == 10 || ptr->m == 12 )
    shift_month_day(ptr,temp,31);
  else if(ptr->m ==2)
    shift_month_day(ptr,temp,28);
  else
    shift_month_day(ptr,temp,30);
}
/*This function prints the date
 *text is input
 *ptr is the input for the date*/
void print_date(char *text,date *ptr){
  switch(ptr->m){
  case jan: printf("%s January %d\n",text,ptr->d); break;
  case feb: printf("%s February %d\n",text,ptr->d); break;
  case mar: printf("%s March %d\n",text,ptr->d); break;
  case apr: printf("%s Apirl %d\n",text,ptr->d); break;
  case may: printf("%s May %d\n",text,ptr->d); break;
  case jun: printf("%s Jun %d\n",text,ptr->d); break;
  case jul: printf("%s Jully %d\n",text,ptr->d); break;
  case aug: printf("%s August %d\n",text,ptr->d); break;
  case sep: printf("%s September %d\n",text,ptr->d); break;
  case oct: printf("%s October %d\n",text,ptr->d); break;
  case nov: printf("%s November %d\n",text,ptr->d); break;
  case dec: printf("%s December %d\n",text,ptr->d); break;
  default: printf("The date (%d/%d) is an error\n",ptr->m,ptr->d);
  }
    
}

int main(int argc, char *rgv[]){
  date today = {oct,31};
  date tomorrow;
  print_date("Today is",&today);
  nextday(&today,&tomorrow);
  print_date("Tomorrow is",&tomorrow);
  return 0;
}
