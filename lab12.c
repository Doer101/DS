#include<stdio.h>
#include<stdlib.h>
#define max 5
#define mod(x)x%max
void linear_prob(int a[],int num,int key){
  if(a[key]==-1)
    a[key]=num;
  else{
    printf("\ncollision is detected:");
    int i;
    for(i=mod(key+1);i!=key;i=mod(++i))
    if(a[i]==-1)
     break;
    if(i!=key){
      printf("\ncollision avoided sucessfully:");
      a[i]=num;
    } 
    else
     printf("\nhash table is full:");
  }
}
void display(int a[]){
  short ch,i;
  printf("\n1>filtered display\n2>display all\nenter your choice:");
  scanf("%hd",&ch);
  printf("\nhash table is:\n");
  for(i=0;i<max;i++)
   if(a[i]>0||ch-1)
    printf("%d %d\n",i,a[i]);
}
int main(){
  int a[max],num,i;
  for(i=0;i<max;a[i++]=-1);
  do{
    printf("\nenter the data:");
    scanf("%4d",&num);
    linear_prob(a,num,mod(num));
    printf("\ndo u want to continue(1/0):");
    scanf("%d",&i);
  }while(i);
  display(a);
  return 0;
}