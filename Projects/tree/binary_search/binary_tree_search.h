
#ifndef BINARY_TREE_SEARCH_H
#define BINARY_TREE_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct tree_node {
    int value;
    struct tree_node *right;
    struct tree_node *left;
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

bool insert_tree(tree_node **ptr_root, int value);
void print_tabs(int num_tabs);
void print_tree_recursive(tree_node *root, int level);
void print_tree(tree_node *root);
void print_array(int size_arr, int *arr);
int *create_array(int size_arr, int *arr);


#endif //PERSONAL_BINARY_TREE_SEARCH_H
