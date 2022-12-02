#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

unsigned int hash(char *name){
    int hash_value = 0;
    int name_length = strnlen(name, NAME_SIZE);
    for (int i = 0; i < name_length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool insert_person(person *p){
    if (p == NULL) return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL){
            hash_table[try] = p;
            return true;
        }
    }
    return true;

}

// init table
void initialize_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

void print_hash_table(){
    printf("START\n");
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("%i\t --- \n", i);
        } else {
            printf("%i\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("END\n\n");
}

person *hash_table_lookup(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strcmp(hash_table[index]->name, name) == 0){
        return hash_table[index];
    }
    return NULL;
}
person *hash_table_delete(char *name){
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strcmp(hash_table[index]->name, name) == 0){
        person *temp = hash_table[index];
        hash_table[index] = NULL;
        return temp;
    }
    return NULL;
}


int main(void){
    initialize_hash_table();
    print_hash_table();

    person jacob = {.name = "Jacob", .age = 12};
    person Seb = {.name = "Seb", .age = 15};
    person Denmark = {.name = "Denmark", .age = 20};

    insert_person(&jacob);
    insert_person(&Seb);
    insert_person(&Denmark);

    print_hash_table();

    person *temp = hash_table_lookup("Jacob");

    if (temp == NULL){
        printf("NOT FOUND\n");
    }
    else{
        printf("Found %s\n", temp->name);
    }

    hash_table_delete("Seb");

    print_hash_table();

    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Seb => %u\n", hash("Seb"));
    // printf("Denmark => %u\n", hash("Denmark"));
    // printf("England => %u\n", hash("England"));
    // printf("World-cup => %u\n", hash("World-cup"));
}
