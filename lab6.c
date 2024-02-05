#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5
int q[QSIZE],i, r=-1, f=0, count=0,j;
void main() {
 int choice;
 for(;;){
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Display\n");
 printf("4. Quit\n");
 printf("Enter your choice:\n");
 scanf("%d",&choice);
 switch(choice){
  case 1:  if(count == QSIZE)
              printf("Queue Overflow\n");
           else{
               r = (r+1) % QSIZE; 
               printf("\nEnter the item:");
               scanf("%d",&q[r]);
               count++;
           }
          break;
 case 2:  if(count == 0)
             printf("Queue Underflow\n");
          else{
              printf("The item deleted is: %d\n", q[f]);
              count--;
              f = (f+1) % QSIZE;
          }
          break;
 case 3:   if(count == 0)
             printf("Queue is Empty\n");
           else{
            i=f;
            for(j=0;j<count;j++){
              printf("%d",q[i]);
              i=(i+1)%QSIZE;
            }
           }
         break;
 default:exit(0);
 }
 }
}

