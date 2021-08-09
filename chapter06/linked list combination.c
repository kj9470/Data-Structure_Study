#include <stdio.h>
#include <stdlib.h>

typedef struct node_type * node_ptr;
struct node_type{
    int data;
    node_ptr link;
};

node_ptr concat_list(node_ptr list1, node_ptr list2);
void print_list(node_ptr list1);

int main() {
    node_ptr list1, list2, node1, node2;
    list1 = (node_ptr) malloc(sizeof(struct node_type));
    list1->data = 100;

    node1 = (node_ptr) malloc(sizeof(struct node_type));
    node1->data = 150;
    node1->link = NULL;

    list1->link = node1; // list1 -> node1

    list2 = (node_ptr) malloc(sizeof(struct node_type));
    list2->data = 200;

    node2 = (node_ptr) malloc(sizeof(struct node_type));
    node2->data = 250;
    node2->link = NULL;

    list2->link = node2; // list2 -> node2

    print_list(list1);
    print_list(list2);
    list1 = concat_list(list1, list2);
    print_list(list1);
    return 0;
}

node_ptr concat_list(node_ptr list1, node_ptr list2){
    node_ptr temp;
    if(!list1) // list1이 비어있다면
        return list2; // list2 반환
    else{
        if(list2){
            temp = list1; // temp에 list1을 넣고
            while (temp->link) // 앞 리스트의 마지막 노드찾기
                temp = temp->link; // temp에 계속 값 넣음
            temp->link = list2; // while 문을 빠져나왔을 때의 마지막 노드에 list2를 넣음(연결)
        }
        return list1;
    };
}

void print_list(node_ptr list){
    while(list){
        printf("%d ", list->data);
        list = list->link;
    }
    printf("\n");
}

int clist_length(node_ptr list){
    node_ptr move;
    int num = 0;
    if(list){ // 리스트에 값이 있다면
        move = list; // move에 list 넣고
        do{ // 적어도 한번은 실행
            num++; // num 증가
            move = move->link; // move에 다음 링크 값 집어넣음
        } while (move != list); // move와 list가 같지 않을 때까지
    }
    return num;
}

