#include<stdio.h>
#include<stdlib.h>

int n, a[10][10], i, j, source, s[10], choice;

void bfs(int n, int a[10][10], int source, int s[]) {
    int q[10], u;
    int front = 1, rear = 1;
    s[source] = 1;
    q[rear] = source;
    while (front <= rear) {
        u = q[front];
        front = front + 1;
        for (i = 1; i <= n; i++) {
            if (a[u][i] == 1 && s[i] == 0) {
                rear = rear + 1;
                q[rear] = i;
                s[i] = 1;
            }
        }
    }
}

int main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    while (1) {
        printf("\n1> BFS\n2> Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the source: ");
                scanf("%d", &source);
                for (i = 1; i <= n; i++)
                    s[i] = 0;
                bfs(n, a, source, s);
                for (i = 1; i <= n; i++) {
                    if (s[i] == 0)
                        printf("The node %d is not reachable.\n", i);
                    else
                        printf("The node %d is reachable.\n", i);
                }
                break;
            case 2:
                exit(0);
        }
    }
    return 0;
}
