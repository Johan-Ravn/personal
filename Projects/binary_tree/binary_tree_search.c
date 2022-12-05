#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

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

bool insert_tree(tree_node **ptr_root, int value) {
    tree_node *root = *ptr_root;

    if (root == NULL) {
        (*ptr_root) = create_node(value);
        return true;
    }
    if (root->value == value) {
        return false;
    }
    if (value < root->value) {
        return insert_tree(&(root->left), value);
    } else {
        return insert_tree(&(root->right), value);
    }
}

void print_tabs(int num_tabs){
    for (int i = 0; i <num_tabs; i++){
        printf("\t");
    }
}

void print_tree_recursive(tree_node *root, int level) {
    if (root == NULL){
        print_tabs(level);
        printf("<EMPTY TREE>\n");
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
}

void print_tree(tree_node *root) {
    print_tree_recursive(root, 0);
}

void print_array(int size_arr, int *arr) {
    for (int i = 0; i < size_arr; i++){
        printf("array[%d]:\t %d\n", i, arr[i]);
    }
    printf("\n\n");
}

int *create_array(int size_arr, int *arr) {
    for (int i = 0; i < size_arr; i++){
        arr[i] = i;
    }
    return arr;
}

int main(void){
    // create array
    int size_arr = 15;
    int *arr = (int*)(malloc(size_arr) + 1);
    arr = create_array(size_arr, arr);
    
    // print array
    print_array(size_arr, arr);

    // Root of tree
    tree_node *root = create_node(size_arr / 2);
    for (int i = 0; i < size_arr; i++){
        insert_tree(&(root), arr[i]);
    }

    // print tree
    print_tree(root);
}
