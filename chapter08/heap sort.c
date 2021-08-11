#include <stdio.h>
// 힙 정렬 프로그램

void printheap(int heap[], int root, int n);
void makeheap(int heap[], int root, int n);
void heapsort(int heap[], int n);

int main() {
    int n = 10;
    int heap[] = {0, 24, 7, 80, 3, 64, 15, 50, 10, 42, 18};
    printheap(heap, 1, n);
    heapsort(heap, n);
}

void makeheap(int heap[], int root, int n){ // 재정렬할 root, 노드 수
    int child, temp;
    temp = heap[root];
    child = 2 * root; // 왼쪽 자식 노드

    while(child <= n){
        if((child < n) && (heap[child] < heap[child + 1])) // 무엇이 더 큰 것인지
            child++;

        if(temp > heap[child]) // 부모와 자식 노드 중 큰 것 비교
            break;
        else{ // 자식 노드를 부모 위치로 이동
            heap[child / 2] = heap[child];
            child *= 2; // 한 레벨 낮추기
        }
    }
    heap[child / 2] = temp;
}

void heapsort(int heap[], int n){ // 원소 개수
    int i, temp;
    for(i = n / 2; i > 0; i--) // 초기 최대 힙
        makeheap(heap, i, n);

    printheap(heap, 1, n);
    for(i = n - 1; i > 0; i--){ // n - 1 반복
        temp = heap[1]; // max 값을 마지막 원소와 교환
        heap[1] = heap[i + 1];
        heap[i + 1] = temp;
        makeheap(heap, 1, i); // 재정렬할 노드, 노드의 수
        printheap(heap, 1, n);
    }
}

void printheap(int heap[], int root, int n){
    int i;
    for(i = root; i <= n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

void SelectionSort(int list[], int n){
    int i, j, max, temp;
    for(i = 0; i < n - 1; i++){
        max = i;
        for(j = i + 1; j < n; j++){
            if(list[j] > list[max])
                max = j;
        }
        temp = list[i];
        list[i] = list[max];
        list[max] = temp;
    }
}
