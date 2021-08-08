#include <stdio.h>
#include <string.h>
#define STACK_SIZE 100
#define EXPR_SIZE 100
typedef enum{
    open_b, close_b, plus, minus, times, divide, mod, eos,operand
} priority;

int stack[STACK_SIZE]; // stack
char expr[EXPR_SIZE]; // 계산 수식 담을 곳
int pos = 0; //
char sym; // 수식을 담을 변수
int sym_type; // read_item 함수에서 값 들어감
int top = -1; // top

int eval_postfix(); // 값 계산
void push(int item); // push
int pop(); // pop
char read_item(); // 처음 expr에 들어간 값 판별
void print_stack(); // stack 출력

int main() {
    // strcpy(expr, "57*9+34/-"); // 5*7+9-3/4
    strcpy(expr, "936+5-/7*64-*"); // 5*7+9-3/4
    eval_postfix();
}

int eval_postfix(){
    int op1, op2; // 계산할 피연산자
    sym = read_item(); // 연산자가 들어감
    while(sym_type != eos){ // 배열의 끝이 아닐 때까지 반복 / eos = 맨 끝
        if(sym_type == operand) // 연산자일 때
            push(sym - '0'); // 문자를 숫자로 바꾸기 (아스키코드간의 뺄셈)
        else{
            op2 = pop(); // 피연산자 들어감(뒤)
            op1 = pop(); // 피연산자 들어감(앞)
            switch(sym_type){ // sym_type에 따라 다르게 연산
                case plus : push(op1 + op2); break;
                case minus : push(op1 - op2); break;
                case times : push(op1 * op2); break;
                case divide : push(op1 / op2); break;
                case mod : push(op1 % op2); break;
            }
        }
        sym = read_item(); // 다시 값 판별
    }
    return pop(); // 최종결과 pop해 리턴
}

void push(int item){
    if(top >= STACK_SIZE - 1){ // top이 스택 크기 - 1 보다 크다면
        printf("stack full"); // 스택이 꽉 참
        return;
    }
    stack[++top] = item; // push
    print_stack(); // 현재 스택 출력
}

int pop(){
    if (top < 0){ // top이 0보다 작으면
        printf("stack empty"); // 스택이 빔
        return -999;
    }
    return stack[top--]; // pop
}

char read_item(){
    sym = expr[pos++]; // expr 값 판별

    switch(sym){
        case '(' : sym_type = open_b; break;
        case ')' : sym_type = close_b; break;
        case '+' : sym_type = plus; break;
        case '-' : sym_type = minus; break;
        case '*' : sym_type = times; break;
        case '/' : sym_type = divide; break;
        case '%' : sym_type = mod; break;
        case '\0' : sym_type = eos; break;
        default : sym_type = operand;
    }
    return sym;
}

void print_stack(){ // 스택 출력
    for(int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
