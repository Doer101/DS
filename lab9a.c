#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int coef, px, py, pz, x, y, z, i;
int val;

struct node {
    int coef, px, py, pz;
    struct node *next;
};

typedef struct node NODE;
NODE *first;

void insert(int coef, int px, int py, int pz) {
    NODE *temp, *cur;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->coef = coef;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    if (first == NULL) {
        temp->next = temp;
        first = temp;
        return;
    }
    if (first->next == first) {
        first->next = temp;
        temp->next = first;
    }
    cur = first;
    while (cur->next != first)
        cur = cur->next;
    cur->next = temp;
    temp->next = first;
}

void display() {
    NODE *cur;
    if (first == NULL) {
        printf("\nThe list is empty.");
        return;
    }
    cur = first;
    do {
        printf("%dx^%dy^%dz^%d ", cur->coef, cur->px, cur->py, cur->pz);
        cur = cur->next;
    } while (cur != first);
}

int evaluate(int x, int y, int z) {
    NODE *cur;
    int v, s = 0;
    if (first == NULL) {
        printf("\nThe list is empty.");return 0;
    }
    cur = first;
    do {
        v = cur->coef * pow(x, cur->px) * pow(y, cur->py) * pow(z, cur->pz);
        s += v;
        cur = cur->next;
    } while (cur != first);
    return s;
}

int main() {
    first = NULL;
    while (1) {
        printf("\n1> Insert\n2> Display\n3> Evaluate\n4> Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                printf("\nEnter the coefficient value: ");
                scanf("%d", &coef);
                printf("Enter the powers of x, y, and z: ");
                scanf("%d %d %d", &px, &py, &pz);
                insert(coef, px, py, pz);
                break;
            case 2:
                printf("\nPolynomial: ");
                display();
                break;
            case 3:
                printf("\nEnter the x, y, z values for evaluation: ");
                scanf("%d %d %d", &x, &y, &z);
                val = evaluate(x, y, z);
                printf("\nThe result of evaluation is: %d", val);
                break;
            case 4:
                return 0;
            default:
                printf("\nEnter a valid input.");
                break;
        }
    }
}
