#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int s[MAX];
int top = -1;

void push(int item);
int pop();
void display();
void palindrome();

void main() {
    int choice, item;

    while (1) {
        printf("\n\nMenu\n");
        printf("1. Push an Element to Stack and Overflow demo\n");
        printf("2. Pop an Element from Stack and Underflow demo\n");
        printf("3. Palindrome demo\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1)
                    printf("Element popped is: %d\n", item);
                break;
            case 3:
                palindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    }
}

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }

    top = top + 1;
    s[top] = item;
}

int pop() {
    int item;
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }

    item = s[top];
    top = top - 1;
    return item;
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (i = top; i >= 0; i--) {
        printf("| %d |\n", s[i]);
    }
}

void palindrome() {
    int flag = 1, i;

    printf("Stack content:\n");
    for (i = top; i >= 0; i--) {
        printf("| %d |\n", s[i]);
    }

    printf("Reverse of stack content:\n");
    for (i = 0; i <= top; i++) {
        printf("| %d |\n", s[i]);
    }

    for (i = 0; i <= top / 2; i++) {
        if (s[i] != s[top - i]) {
            flag = 0;
            break;
        }
    }

    if (flag==1) {
        printf("It is a palindrome number\n");
    } else {
        printf("It is not a palindrome number\n");
    }
}
