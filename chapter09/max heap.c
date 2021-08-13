#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define HEAP_FULL(n) (n == MAX_HEAP_SIZE - 1)
#define HEAP_EMPTY(n) (!n)
int total_node = 0;
int heap[MAX_SIZE];
void add_heap(int item);
int delete_heap();

int main() {
    int i;
    add_heap(10);
    add_heap(20);
    add_heap(5);
    add_heap(12);
    add_heap(40);
    add_heap(80);
    for(i = 1; i <= total_node; i++)
        printf("%d ", heap[i]);
    printf("\n");
    while(1)
        printf("%d ", delete_heap());
}

void add_heap(int item){
    int i;
    if (total_node >= MAX_SIZE - 1) exit(1); // full heap
    i = ++total_node;
    while((i != 1) && (item > heap[i / 2])){ // 힙이 빈 경우
        heap[i] = heap[i / 2]; // 부모 노드 저장
        i /= 2; // 상위 레벨로
    }
    heap[i] = item;
}

int delete_heap(){
    int parent, child;
    int item, temp;

    if(total_node == 0) exit(1);

    item = heap[1];
    temp = heap[total_node--]; // 마지막 노드
    parent = 1; // 루트
    child = 2; // 왼쪽 자식 노드

    while(child <= total_node){ // 마지막 노드까지 확인
        if(child < total_node && heap[child] < heap[child + 1]) // 큰 노드가 자식 노드로 변경
            child++;

        if(temp >= heap[child]) break; // 재구성 완료

        heap[parent] = heap[child]; // 부모 노드와 자식 노드 교환
        parent = child; // 레벨 1단계 내림
        child *= 2; // 새로운 자식 노드
    }

    heap[parent] = temp; // 마지막 탐색 위치에 temp 저장
    return item;
}


