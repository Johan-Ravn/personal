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

void get_info(char *ptr_name[NAME_SIZE], int *ptr_age, int *ptr_mode){
    printf("Which operations would you like to make? \n");
    int operation = -1;
    while(true){
        printf("Print: 0\n");
        printf("Insert: 1\n");
        printf("Delete: 2\n");
        printf("Lookup: 3\n"); 
        printf("STOP: 4\n");
        scanf("%d", &operation);
        if (operation >= 0 && operation <= 4){
            break;
        }
    }

    char *temp_name = (char*)(malloc(NAME_SIZE) + 1);
    int temp_age = -1;
    
    switch (operation){
    case 0:
        *ptr_mode = operation;
        break;
    case 1:
        while(true){
            printf("Name and age to add: \n");
            scanf("%s", temp_name);
            scanf("%d", &temp_age);
            if (temp_age >= 0){
                break;
            }
            printf("Age not valid");
        }
        *ptr_name = temp_name;
        *ptr_age = temp_age;
        *ptr_mode = operation;
        break;
    case 2:
        while(true){
            printf("Name to delete: \n");
            scanf("%s", temp_name);
            break;
        }
        *ptr_name = temp_name;
        *ptr_age = 0;
        *ptr_mode = operation;
        break;
    case 3:
        while(true){
            printf("Name to lookup: \n");
            scanf("%s", temp_name);
            break;
        }
        *ptr_name = temp_name;
        *ptr_age = 0;
        *ptr_mode = operation;
        break;
    case 4:
        *ptr_mode = operation;
        break;
    
    default:
        exit(EXIT_FAILURE);
        break;
    }
}

void driver_hash_table(person p, int mode){
    switch (mode){
        case 0: // print
            print_hash_table();
            break;
        case 1: // Insert
            insert_person(&p);
            print_hash_table();
            break;
        case 2: // delete
            hash_table_delete(p.name);
            print_hash_table();
            break;
        case 3: // lookup
            hash_table_lookup(p.name);
            print_hash_table();
            break;
        case 4: // stop program
            exit(EXIT_SUCCESS);
            break;
        
        default:
            exit(EXIT_FAILURE);
            break;
    }
}

int main(void){
    // init hash table, sets everything to null
    initialize_hash_table();

    char *temp_name = (char*)(malloc(NAME_SIZE) + 1);
    int temp_age, temp_mode;
    
    while (true){
        get_info(&temp_name, &temp_age, &temp_mode);
        person temp = {.age = temp_age};
        strcpy(temp.name, temp_name);
        driver_hash_table(temp, temp_mode);
    }
}
