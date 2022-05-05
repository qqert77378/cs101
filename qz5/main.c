#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* Next;
}node_t;

node_t* allocate_node(int data) {
     node_t* ptr =(node_t*)calloc(1, sizeof(node_t));
     return ptr;
}

void show_list(node_t* list) {
    while(list->Next != NULL) {
        printf("[%d]", list->data);
        list = list->Next;
    }
    printf("NULL\n");
}

node_t* append_node (node_t* list, int new_data) {
    list->Next = allocate_node(new_data);
    node_t* tmp = list;
    while(tmp->Next != NULL) {
        tmp = tmp->Next;
    }
    //allocate_node(new_data);
    return list;
}

void free_all_node(node_t* list) {
    while(list->Next != NULL) {
        free(list);
        list = list->Next;
    }
}

int main() {
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 11);
    show_list(head);
    head = append_node(head, 222);
    show_list(head);
    head = append_node(head, 3333);
    show_list(head);
    free_all_node(head);
    return 0;
}
