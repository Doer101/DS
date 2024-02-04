#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Day{
  char *name;
  int date;
  char *activity;
};

struct Day week[7];

void create(){
  for (int i=0;i<7;i++){
    week[i].name=(char*)malloc(20*sizeof(char));
    week[i].activity=(char*)malloc(100*sizeof(char));
    printf("\nEnter the name of the Day %d:",i+1);
    scanf("%s",week[i].name);
    printf("\nEnter the date of the Day %d:",i+1);
    scanf("%d",&week[i].date);
    printf("\nEnter the activity of the Day %d:",i+1);
    getchar();
    fgets(week[i].activity,100,stdin);
  }
}
void read(){
  create();
}
void display(){
  printf("\nDay\tDate\tActivity\n");
  for(int i=0;i<7;i++){
    printf("%s\t%d\t%s",week[i].name,week[i].date,week[i].activity);
  }
}
int main(){
  printf("\nCreating a calendar\n");
  create();
  printf("\nDisplaying a claendar\n");
  display();
  return 0;
}