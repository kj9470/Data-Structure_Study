#include <stdio.h>
#include <stdlib.h>

typedef struct node_type * node_ptr;
struct node_type{
    node_ptr llink;
    int data;
    node_ptr rlink;
};

void insert_dll(node_ptr prev, node_ptr node);
void delete_dll(node_ptr head, node_ptr node);
void print_dll(node_ptr head, node_ptr list1);

int main() {
    node_ptr head, list, node1, node2, node3, node4;
    head = (node_ptr) malloc(sizeof(struct node_type));
    node1 = (node_ptr)malloc(sizeof(struct node_type));
    node1->data = 7;
    list = node1;
    head->llink = NULL;
    head->rlink = node1;
    node1->llink = head;

    node2 = (node_ptr)malloc(sizeof(struct node_type));
    node2->data = 13;
    node2->llink = node1;
    node1->rlink = node2;

    node3 = (node_ptr)malloc(sizeof(struct node_type));
    node3->data = 15;
    node3->llink = node2;
    node3->rlink = head;
    node2->rlink = node3;
    head->llink = node3;

    node4 = (node_ptr)malloc(sizeof(struct node_type));
    node4->data = 11;
    node4->llink = NULL;
    node4->rlink = NULL;
    head->llink = node2;

    print_dll(head, list);
    delete_dll(head, node3);
    print_dll(head, list);
    insert_dll(node1, node4);
    print_dll(head, list);

    return 0;
}

void insert_dll(node_ptr prev, node_ptr node){
    node->llink = prev;
    node->rlink = prev->rlink;
    prev->rlink->llink = node;
    prev->rlink = node;
}

void delete_dll(node_ptr head, node_ptr node){
    if (head == node)
        printf("헤드 노드는 삭제할 수 없습니다\n");
    else{
        node->llink->rlink = node->rlink;
        node->rlink->llink = node->llink;
        free(node);
    }
}

void print_dll(node_ptr head, node_ptr list){
    while(list != head){
        printf("%d ", list->data);
        list = list->rlink;
    }
    printf("\n");
}
