#define STACK_SIZE 100
#include <stdio.h>
int stack[STACK_SIZE];
int top = -1;

void push(int item); // push 함수
int pop(); // pop 함수
void print_stack(); // 현재 스택 출력

int main() {
    push(3); // 3
    push(4); // 3 4
    push(5); // 3 4 5
    pop();
    print_stack(); // 3 4
    pop();
    print_stack(); // 3
    pop();
    print_stack(); // 아무것도 출력 X
    pop();
    print_stack(); // stack empty
}

void print_stack(){
    int i;
    for(i = 0; i <= top; i++) // 현재 스택에 있는 모든 원소 출력
        printf("%d ", stack[i]); //

    printf("\n");
}

void push(int item){
    if (top >= STACK_SIZE - 1){ // 스택이 다 찼을 때
        printf("stack full");
        return;
    }
    stack[++top] = item; // push
    print_stack();
}

int pop(){
    if (top < 0){ // 스택에 아무것도 없을 때
        printf("stack empty");
        return -999;
    }
    return stack[top--]; // 아니라면 pop
}
