#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

typedef struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node *create_node(int value) {
    tree_node *result = malloc(sizeof(tree_node));
    if (result != NULL){
        result->right = NULL;
        result->left = NULL;
        result->value = value;
    }
    return result;
}

void print_tabs(int num_tabs){
    for (int i = 0; i <num_tabs; i++){
        printf("\t");
    }
}

void print_tree_recursive(tree_node *root, int level) {
    if (root == NULL){
        print_tabs(level);
        printf("<EMPTY TREE>");
        return;
    }
    // preorder traversal. Left to right
    print_tabs(level);
    printf("Root value: %d\n", root->value);
    print_tabs(level);
    
    
    printf("Left:\n");
    print_tree_recursive(root->left, level + 1);
    print_tabs(level);

    printf("Right:\n");
    print_tree_recursive(root->right, level + 1);
    print_tabs(level);
    
    printf("Done\n");
}

void print_tree(tree_node *root) {
    print_tree_recursive(root, 0);
}

int main(void){
    tree_node *n1 = create_node(10);
    tree_node *n2 = create_node(11);
    tree_node *n3 = create_node(12);
    tree_node *n4 = create_node(13);
    tree_node *n5 = create_node(14);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    print_tree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);   
}
