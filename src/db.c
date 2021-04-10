#include <time.h>
#include <stdio.h>
#include <stdlib.h>


struct element {
    char* key;
    char* value;
    struct element* next;
};

typedef struct element record;


void listAll(record *head) {
    record *tempnode = head->next;
    printf("+-----------------------------------+\n");
    printf("| %-15.3s | %-15.5s |\n", "KEY", "VALUE");
    printf("+-----------------------------------+\n");
    while(tempnode != NULL){
        printf("| %-15.16s | %-15.16s | \n", tempnode->key, tempnode->value);
        tempnode = tempnode->next;
    }
    printf("+-----------------------------------+\n");
}


record* create_new_record(char* key, char* value) {
    record *created_record = (record*) malloc(sizeof(record));
    created_record->key = key;
    created_record->value = value;
    created_record->next = NULL;
    return created_record;
}


void update(record *head, char* key, char* value) {
    record *tmp = head;
    while(tmp != NULL){
        if(tmp->key == key) {
            tmp->value = value;
        }
        tmp = tmp->next;
    }
}


int length(record* head) {
    record *temp = head->next;
    int count = 1;
    while(temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


void del(record *head, char* key) {
    record *tmp = head;
    record *tmp2 = tmp->next;
    while(tmp2 != NULL) {
        if(tmp2->key == key) {
            tmp->next = tmp2->next;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
}

void sSet(record *head, char* key, char* value) {
    record *creatednode = create_new_record(key, value);
    creatednode->next = head->next;
    head->next = creatednode;
}


record* set(record *head, char* key, char* value) {
    record *temp = head;
    record *creatednode = create_new_record(key, value);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = creatednode;
    return head;
}


char* get(record *head, char* key) {
    record *tmp = head;
    while(tmp != NULL){
        if(tmp->key == key) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return 0;
}


record* create_db() {
    record *head = create_new_record(0,0);
    return head;
}


void freedb(record *head) {
    record *tmp;
    tmp = head->next;
    while(tmp) {
        free(tmp);
        tmp = tmp->next;
    }
}


int main() {
    record *c = create_db(); // initializes the database

    char key[][5] = {"key1", "key2", "key3", "key4"};
    char value[][7] = {"value1", "value2", "value3", "value4"};

    sSet(c, key[0], value[0]); // creates a new db record as given key to the given value
    sSet(c, key[1], value[1]);
    set(c, key[2], value[2]);
    set(c, key[3], value[3]);

    update(c, key[0], value[2]); // updates give key with given value

    del(c, key[2]); // deletes the value

    listAll(c); // displays all the records in the database

    char *result = get(c, key[3]); // searches database for give key
    int numOfElements = length(c); // returns number of records in database

    printf("value: %s\n", result);
    printf("num of items: %d\n", numOfElements);

    freedb(c);

    return 0;
}
