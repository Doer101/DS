#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
  int coef,px,py,pz,flag;
  struct node *link;
};

typedef struct node *NODE;

NODE create(NODE head){
  int i,n,coef,px,py,pz;
  printf("\nenter the number of terms:");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    printf("\nenter the vales of the polynomial:");
    scanf("%d%d%d%d%d",&coef,&px,&py,&pz);
    insert(head,coef,px,py,pz);
  }
  return head;
}

void insert(NODE head, int cof, int x, int y, int z) {
    NODE cur, temp;
    temp = (NODE)malloc(sizeof(struct node));
    cur = head;
    temp->coef = cof;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    temp->flag = 0;
    while (cur->link != head)
        cur = cur->link;
    cur->link = temp;
    temp->link = head;
}

NODE add(NODE h1,NODE h2,NODE h3){
  NODE cur1,cur2;int scf;
  cur1=h1->link;
  cur2=h2->link;
  while(cur1!=h1){
    if(cur2==h2)
      cur2=h2->link;
    while(cur2!=h2){
      if(cur1->px==cur2->px && cur1->py==cur2->py && cur1->pz==cur2->pz){
        scf=cur1->coef+cur2->coef;
        insert(h3,scf,cur1->px,cur1->py,cur1->pz);
        cur2->flag=1;
        cur2=h2->link;
        break;
      }
      cur2=h2->link;
    }  
    if(cur1==h1)
      break;
    if(cur2==h2)
      insert(h3,cur1->coef,cur1->px,cur1->py,cur1->pz);
    cur1=cur1->link;
  }   
    cur2=h2->link;
    while(cur2!=h2){
      if(cur2->flag==0)
        insert(h3,cur2->coef,cur2->px,cur2->py,cur2->pz);
      cur2=cur2->link;  
    } 
    return h3;
}

void display(NODE head){
  NODE cur;
  if(head->link==head){
    printf("\nthe list is empty:");
    return;
  }
  cur=head->link;
  while(cur!=head){
    if(cur->coef>0)
      printf("+%dx^%dy^%dz^%d",cur->coef,cur->px,cur->py,cur->pz);
    else if(cur->coef<0)
      printf("%dx^%dy^%dz^%d",cur->coef,cur->px,cur->py,cur->pz);
    cur=cur->link;    
  }
  printf("\n");
}

void main(){
  NODE head1,head2,head3;
  head1=(NODE)malloc(sizeof(struct node));
  head1->link=head1;
  head2=(NODE)malloc(sizeof(struct node));
  head2->link=head2;
  head3=(NODE)malloc(sizeof(struct node));
  head3->link=head3;
  printf("\n1.create polynomial 1:");
  head1=create(head1);
  printf("\n2.create polynomial 2:");
  head2=create(head2);
  printf("\ndisplay polynomial 1:");
  display(head1);
  printf("\ndisplay polynomial 2:");
  display(head2);
  printf("\nadding two polynomial:");
  head3=add(head1,head2,head3);
  display(head3);
}