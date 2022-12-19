

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

void print_tabs(int num_tabs);
void print_tree_recursive(tree_node *root, int level);
void print_tree(tree_node *root);


#endif //BINARY_TREE_SEARCH_BINARY_TREE_H
