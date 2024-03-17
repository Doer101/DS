#include<stdio.h>
#include<stdlib.h>

int choice, data, key;

struct node {
    int info;
    struct node *lchild, *rchild;
};

typedef struct node *NODE;

NODE create(NODE, int);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE search(NODE, int);

int main() {
    NODE root = NULL;
    while (1) {
        printf("\n1>Create\n2>Node Traversal\n3>Search\n4>Exit");
        printf("\nEnter the choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the data to be inserted:");
                scanf("%d", &data);
                root = create(root, data);
                break;
            case 2:
                if (root == NULL)
                    printf("\nTree is empty:");
                else {
                    printf("\nInorder Display:");
                    inorder(root);
                    printf("\nPreorder Display:");
                    preorder(root);
                    printf("\nPostorder Display:");
                    postorder(root);
                }
                break;
            case 3:
                printf("\nEnter the key to be searched:");
                scanf("%d", &key);
                search(root, key);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}

NODE create(NODE root, int data) {
    NODE newnode, x, parent;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->lchild = newnode->rchild = NULL;
    newnode->info = data;
    if (root == NULL)
        root = newnode;
    else {
        x = root;
        while (x != NULL) {
            parent = x;
            if (x->info > data)
                x = x->lchild;
            else if (x->info < data)
                x = x->rchild;
            else {
                printf("\nThe node is already present:");
                return root;
            }
        }
        if (parent->info > data)
            parent->lchild = newnode;
        else
            parent->rchild = newnode;
    }
    return root;
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("\n%d", root->info);
        inorder(root->rchild);
    }
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("\n%d", root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("\n%d", root->info);
    }
}

NODE search(NODE root, int key) {
    NODE cur, parent;
    if (root == NULL) {
        printf("\nTree is empty:");
        return root;
    }
    parent = NULL;
    cur = root;
    while (cur != NULL) {
        if (key == cur->info) {
            printf("\nData %d is found.", key);
            return cur;
        }
        parent = cur;
        cur = (key < cur->info) ? cur->lchild : cur->rchild;
    }
    printf("\nData is not found.");
    return NULL;
}
