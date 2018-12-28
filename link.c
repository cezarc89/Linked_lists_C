#include <stdio.h>
#include <stdlib.h>
   
typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void add_after(node_t * head, int value) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (struct node *)malloc(sizeof(node_t));
    current->next->val = value;
    current->next->next = NULL; 
}

struct node * add_before(node_t * head, int value){
    node_t * new;
    new =  (struct node *) malloc (sizeof(node_t));
    new->next = head;
    new->val = value;
    head = new;
    return ((struct node *)head);
}

struct node * del_before(node_t * head){
    node_t * second;
    second = head->next;
    head->next = NULL;
    free(head);
    return ((struct node *)second); 
}

int del_last(node_t * head){
    if (head->next == NULL){
        free(head);
    }
    node_t * current = head;
    while (current->next->next != NULL){
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return 0;
}

struct node * del_item(struct node * head, int value)
{
    if (!head) 
        return NULL;

    node_t * tmp = head;
    node_t * prev = NULL;

    while (tmp->val != value && tmp->next != NULL){
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp->val == value){
        if (prev){
            prev->next = tmp->next;
        } else {
            head = tmp->next;
        }
        free(tmp);
    }

    return NULL;
}


int main(){
    node_t *HEAD = NULL;
    HEAD = (struct node *)malloc(sizeof(node_t));
    if (HEAD == NULL){
        return 1;
    }

    HEAD->val = 1;
    HEAD->next = (struct node *)malloc(sizeof(node_t));
    HEAD->next->val = 2;
    HEAD->next->next = (struct node *)malloc(sizeof(node_t));
    HEAD->next->next->val = 3;
    HEAD->next->next->next = NULL;
 
    printf("Print initial list: \n");   
    print_list(HEAD);    
    add_after(HEAD,4);
    printf("\n");
    printf ("Print list after one element was added at end of list:\n");
    print_list(HEAD);
    HEAD = add_before(HEAD,5);
    printf("\n");
    printf ("Print list after one element was added in front of list: \n");
    print_list(HEAD);
    HEAD = del_before(HEAD);
    printf("\n");
    printf ("Print list after deleted HEAD of list:\n");
    print_list(HEAD);
    del_last(HEAD);
    printf("\n");
    printf("Print list after last element from list was deleted:\n");
    print_list(HEAD);
    del_item(HEAD,2);
    printf("\n");
    printf("Print list after item with value of 2 is removed:\n");
    print_list(HEAD);
    
    free(HEAD);

    return 0;
}

