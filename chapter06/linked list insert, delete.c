#include <stdio.h>
#include <stdlib.h>
typedef struct node_type *node_ptr;
struct node_type{
    int data;
    node_ptr link;
};
node_ptr list;
void insert_node(node_ptr prev, int data);
void delete_node(node_ptr prev, node_ptr node);
void print_list(node_ptr list);

int main() {
    node_ptr node1, node2, node3;
    node1 = (node_ptr)malloc(sizeof(struct node_type));
    node1->data = 100;
    node1->link = NULL;
    list = node1; // 첫번째 값 들어감(왜냐면 그 뒤로 계속 연결)
    node2 = (node_ptr)malloc(sizeof(struct node_type));
    node2->data = 200;
    node2->link = NULL;
    node3 = (node_ptr)malloc(sizeof(struct node_type));
    node3->data = 300;
    node3->link = NULL;
    node1->link = node2; // node1과 node2 연결
    node2->link = node3;
    print_list(list);
    delete_node(node1, node2);
    print_list(list);
    insert_node(node1, 150);
    print_list(list);

    return 0;
}

void insert_node(node_ptr prev, int data){ // prev : 이전 노드 / data : 삽입할 노드
    node_ptr node;
    node = (node_ptr)malloc(sizeof(struct node_type));
    if(!node) exit(1); // 노드에 값이 없다면 끝냄
    node->data = data;
    node->link = NULL;
    if(!list) // 리스트 비어있으면
        list = node; // 첫 번째 값으로 노드 집어넣음
    else if(prev){ // 중간에 삽입되는 경우
        node->link = prev->link; // 새로운 노드 링크에 이전 노드의 링크 주소를 넣고
        prev->link = node; // 이전 노드엔 새로운 노드의 주소를 넣음
    }
    else{ // 맨 앞에 추가되는 경우
        node->link = list; // list의 값을 넣고
        list = node; // list에 노드값을 넣음
    }
}

void delete_node(node_ptr prev, node_ptr node){
    if (prev){ // 중간 노드 삭제
        prev->link = node->link; // 앞 노드에 중간 노드 링크값 넣어줌
    }
    else{ // 첫번째 노드 삭제
        list = node->link; // list에 노드 링크값 놓어줌
    }
    free(node);
}

void print_list(node_ptr list){
    while(list){
        printf("%d ", list->data);
        list = list->link;
    }
    printf("\n");
}
