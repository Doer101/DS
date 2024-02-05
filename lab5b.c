#include<stdio.h>
int count=0,n;
int towers(int n, char s, char t, char d){
  if (n == 1){
    printf("\n Move disk 1 from peg %c to peg %c", s, d);count++;
    return 1;
  }
  towers(n - 1, s, d, t);
  printf("\n Move disk %d from peg %c to peg %c", n, s, d);count++;
  towers(n - 1, t, s, d);
}
void main(){
 printf("Enter the number of disks : ");
 scanf("%d", &n);
 towers(n, 'A', 'B', 'C');
 printf("\nThe sequence of moves involved in the Tower of Hanoi are :%d\n",count);
}
