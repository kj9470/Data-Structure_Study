#include <stdio.h>
#include <stdlib.h>

typedef struct node_type * node_ptr;
struct node_type{
    int data;
    node_ptr link;
};

node_ptr reverse_list(node_ptr);
void print_list(node_ptr);

int main() {
    node_ptr list, node1, node2, node3;
    node1 = (node_ptr) malloc(sizeof(struct node_type));
    node1->data = 7;
    list = node1;

    node2 = (node_ptr) malloc(sizeof(struct node_type));
    node2->data = 11;
    node1->link = node2;

    node3 = (node_ptr) malloc(sizeof(struct node_type));
    node3->data = 13;
    node2->link = node3;
    node3->link = NULL;
    print_list(list);
    list = reverse_list(list); // 첫번째 값
    print_list(list);
    return 0;
}

node_ptr reverse_list(node_ptr one){
    node_ptr two, three;
    two = NULL;
    while(one){ // NULL 아닐 때
        three = two;
        two = one;
        one = one->link;
        two->link = three;
    }
    return two;
}

void print_list(node_ptr list){
    while(list){
        printf("%d ", list->data);
        list = list->link;
    }
    printf("\n");
}
