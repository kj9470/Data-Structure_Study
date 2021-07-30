#include <stdio.h>
#define QUEUE_SIZE 100
int front, rear;
int cqueue[QUEUE_SIZE];
void addq(int item);
int deleteq();
void print_queue();

int main() {
    int temp;
    front = rear = 0;

    addq(11); // 11
    addq(13); // 11 13
    addq(17); // 11 13 17
    addq(19); // 11 13 17 19
    temp = deleteq();
    print_queue(); // 13 17 19
    temp = deleteq();
    print_queue(); // 13 17
    temp = deleteq();
    print_queue(); // 13
    temp = deleteq();
    print_queue(); // 아무것도 출력되지 않음
}

void addq(int item){
    if (front == ((rear + 1) % QUEUE_SIZE)){ // front 값과 rear이 가리키는 값이 같을 때
        printf("queue full");
        return;
    }
    rear = (rear + 1) % QUEUE_SIZE; // rear엔 1을 더하고 큐 사이즈로 나눈 값 저장
    cqueue[rear] = item; // push
    print_queue(); // 현재 원소 출력
}

int deleteq(){
    if(front == rear){ // front와 rear의 값이 같을 때
        printf("queue empty"); // 큐가 다 찼음
        return -999;
    }
    front = (front + 1) % QUEUE_SIZE; // front에 1을 더한 수를 큐 사이즈로 나눠 저장
    return cqueue[front]; // 값 리턴
}

void print_queue(){
    int i = front;
    while(i != rear){
        i = (i + 1) % QUEUE_SIZE;
        printf("%d ", cqueue[i]); // 현재 원소 배열 출력
    }
    printf("\n");
}

