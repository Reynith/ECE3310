#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _node{
    int data;
    struct _node *next;
} Node;

typedef struct _list
{
    int count;
    Node* head;
} List;

List* create_new_list() {
    List* my_new_list = (List*)malloc(sizeof(List)); 
    my_new_list->count = 0;
    my_new_list->head = NULL;
    return my_new_list;
} 

Node* create_new_node() {
    Node* n0;
    n0 = NULL;
    /** malloc will allocate memory for usin the .heap memory segment
    * malloc - is defined in the stdlib library
    * malloc has one argument that represents the number of bytes to be allocated
    * malloc will return the address where the free space was found and allocated for us OR -1 if it fails
    * malloc returns a pointer to void (void *)
    * */
    n0 = (Node*)malloc(sizeof(Node)); 
    (*n0).data = 0;
    //n0->data = 0;
    n0->next = NULL;
    return n0;
} 

Node* create_node(int val) {
    Node* result = create_new_node();
    result->data = val;
    return result;
}

int add_node_front(List* list, Node* n) {
    if (list == NULL)
        return -1;
    
    n->next = list->head;
    list->head = n;
    ++list->count;

    return 0;
}

int add_node_last(List* list, Node* n) {
    if (list == NULL)
        return -1;

    if(list->head == NULL) {
        list->head = n;
        ++list->count;
        return 0;
    }

    Node* tmp = list->head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = n;

    ++list->count;
    return 0;
}

int print_list(List* list) {
    if (list == NULL)
        return 0;
    
    Node* tmp = list->head;
    while(tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    return 0;
}

int print_list_rec(Node* item) {
    if(item == NULL)
        return 0;
    
    printf("%d ", item->data);
    print_list_rec(item->next);
    
    return 0;
}


int print_list_rec_reverse(Node* item) {
    if(item == NULL)
        return 0;
    
    print_list_rec_reverse(item->next);
    printf("%d ", item->data);
    
    return 0;
}

bool find_int(List* list, int a) {
    if (list == NULL)
        return false;

    Node* tmp = list->head;
    while(tmp != NULL) {
        if (tmp->data == a)
            return true;
        tmp = tmp->next;
    }

    return false;
}



int main() {

    Node* n0 = create_node(4);
    Node* n1 = create_node(9);
    Node* n2 = create_node(19);

    List* list = create_new_list();
    add_node_front(list, n0);
    add_node_front(list, n1);
    add_node_last(list, n2);
    add_node_last(list, create_node(22));

    print_list(list);
    printf("\n");
    print_list_rec(list->head);
    printf("\n");
    print_list_rec_reverse(list->head);
    printf("\n");

    bool a = find_int(list, 4);
    a = find_int(list, 9);
    a = find_int(list, 22);
    a = find_int(list, 0);

    free(n0); 
    n0 = NULL;

    free(n1);
    n1 = NULL;
    
    return 0;
}