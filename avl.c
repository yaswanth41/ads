#include<stdio.h>
#include<stdlib.h>

#define Max(a, b) ((a>>b)?a:b)
typedef struct Avlnode {
    int data;
    struct Avlnode *left, *right;
} avlnode;
avlnode *root;

avlnode *rotate_LL(avlnode *parent) {
    avlnode *child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}

avlnode *rotate_RR(avlnode *parent) {
    avlnode *child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

avlnode *rotate_RL(avlnode *parent) {
    avlnode *child = parent->right;
    parent->right = rotate_LL(child);
    return rotate_RR(parent);
}

avlnode *rotate_LR(avlnode *parent) {
    avlnode *child = parent->left;
    parent->left = rotate_RR(child);
    return rotate_LL(parent);
}

int get_height(avlnode *node) {
    int height = 0;
    if (node != NULL)
        height = 1 + Max(get_height(node->left), get_height(node->right));
    return height;
}

int get_balence(avlnode *node) {
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

avlnode *balence_tree(avlnode **node) {
    int bal_factor = get_balence(*node);
    if (bal_factor > 1) {
        if (get_balence((*node)->left) > 0)
            *node = rotate_LL(*node);
        else
            *node = rotate_LR(*node);
    }
    else if (bal_factor < -1) {
        if (get_balence((*node)->right) < 0)
            *node = rotate_RR(*node);
        else
            *node = rotate_RL(*node);
    }
    return *node;
}

avlnode *insert(avlnode **root, int key) {
    if (*root == NULL) {
        *root = (avlnode *) malloc(sizeof(avlnode));
        (*root)->data = key;
        (*root)->left = (*root)->right = NULL;
    }
    else if (key < (*root)->data) {
        (*root)->left = insert(&((*root)->left), key);
        (*root) = balence_tree(root);
    }
    else if (key > (*root)->data) {
        (*root)->right = insert(&((*root)->right), key);
        (*root) = balence_tree(root);
    }
    return *root;
}

avlnode *search(avlnode *node, int key) {
    if (node == NULL)
        return NULL;
    printf("%d->", node->data);
    if (key == node->data)
        return node;
    else if (key < node->data)
        search(node->left, key);
    else
        search(node->right, key);
}

void display(avlnode *root) {
    if (root == NULL)
        return;
    printf("%d", root->data);
    display(root->left);
    display(root->right);
}

main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter a key to insert:");
                scanf("%d", &x);
                insert(&root, x);
                break;
            case 2:
                printf("\nEnter search key:");
                scanf("%d", &x);
                search(root, x);
                break;
            case 3:
                display(root);
                break;
            case 4:
                exit(0);
        }
    }
}

