
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define TABLE_SIZE 5
#define NAME_SIZE 256

typedef struct {
    char name[NAME_SIZE];
    int age;
}person;

person *hash_table[TABLE_SIZE];

bool insert_person(person *p);
void initialize_hash_table();
void print_hash_table();
person *hash_table_lookup(char *name);
person *hash_table_delete(char *name);
void get_info(char *ptr_name[NAME_SIZE], int *ptr_age, int *ptr_mode);
void driver_hash_table(person p, int mode);

#endif
