#include <stdio.h>
#include <stdlib.h>

typedef struct node_type * node_ptr;
struct node_type{
    int data;
    node_ptr link;
};

int length_list(node_ptr list);

int main() {
    node_ptr list, node1, node2, node3;
    node1 = (node_ptr)malloc(sizeof(struct node_type));
    node1->data = 100;
    node1->link = NULL;
    list = node1;
    node2 = (node_ptr)malloc(sizeof(struct node_type));
    node2->data = 150;
    node2->link = NULL;
    node1->link = node2;
    node3 = (node_ptr)malloc(sizeof(struct node_type));
    node3->data = 200;
    node3->link = NULL;
    node2->link = node3;
    printf("list length is %d\n", length_list(list));
}

int length_list(node_ptr list){
    int count = 0;
    node_ptr temp = list;
    while(temp){
        count += 1;
        temp = temp->link;
    }
    return count;
}
