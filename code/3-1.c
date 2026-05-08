#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char name[100];
    int score;
    struct Node *next;
};

struct SList {
    struct Node *head;
};

void add(struct SList *list, char name[], int score){
    struct Node *new_node = malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->score = score;
    new_node->next = NULL;

    if(list->head == NULL){
        list->head = new_node;
        return;
    }

    for(struct Node *p = list->head; p != NULL; p = p->next){
        if(p->next == NULL){
            p->next = new_node;
            break;
        }
    }
}

void delete(struct SList *list, char name[]){
    if (strcmp(list->head->name, name) == 0) {
        struct Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    for(struct Node *p = list->head; p != NULL; p = p->next){
        if (strcmp(p->next->name, name) == 0) {
            p->next = p->next->next;

            free(p->next);
            break;
        }
    }
}

void print(struct SList *list){
    for(struct Node *p = list->head; p != NULL; p = p->next){
        printf("%s %d\n", p->name, p->score);
    }
}

int main() {
    struct SList *list = malloc(sizeof(struct SList));
    list->head = NULL;
    
    while(1) {
        char input[100] = "";
        int mode = 0;
        char name[50];
        int score = 0;
        scanf("%s", input);
        
        if (strcmp(input, "quit") == 0) {
            break;
        }

        if (strcmp(input, "add") == 0) {
            scanf("%s %d", name, &score);
            add(list, name, score);
        }
        else if (strcmp(input, "delete") == 0) {
            scanf("%s", name);
            delete(list, name);
        }
        else if (strcmp(input, "print") == 0) {
            print(list);
        }
    }
    
}