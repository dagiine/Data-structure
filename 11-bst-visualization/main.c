#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

void debugPrint(char op, int num, Node *root) {
    printf("# %c%d", op, num);
    if (root != NULL)
        printf(" root: %d", root->value);
    printf("\n");
}

void printTree(Node *root, int space) {
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);

    printTree(root->left, space);
}

int main() {
    Node *root = NULL;
    int active = 1;
    char op;
    int num;

    while (active) {
        scanf(" %c", &op);
        switch (op) {
        case '+':
            scanf("%d", &num);
            root = insert(root, num);
            debugPrint(op, num, root);
            printf("Inorder: ");
            inorder(root);
            printf("\nTree structure:\n");
            printTree(root, 0);
            break;
        case '-':
            scanf("%d", &num);
            root = removeValue(root, num);
            debugPrint(op, num, root);
            printf("Inorder: ");
            inorder(root);
            printf("\nTree structure:\n");
            printTree(root, 0);
            break;
        case 'q':
            active = 0;
            break;
        default:
            printf("+, -, q\n");
            break;
        }
    }

    return 0;
}