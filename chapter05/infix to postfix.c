#include <stdio.h>
#include <ctype.h>
#define STACK_SIZE 100

char token_stack[STACK_SIZE];
int token_top = -1;
void infix_to_postfix();
int precedence(char op);
void push_token(char sym);
char pop_token();

int main() {
    infix_to_postfix();
}

void infix_to_postfix(){
    char expr[50], sym, token;
    int pos = 0;

    printf("Enter the expression :: ");
    scanf("%s", expr);

    while((token = expr[pos++]) != '\0'){
        if(isalnum(token)) // 알파벳 또는 숫자
            printf("%c ", token);
        else if(token == '(')
            push_token(token);
        else if(token == ')'){ // '('이 나올 때까지 모든 연산자 출력
            while((sym = pop_token()) != '('){
                printf("%c ", sym);
            }
        }
        else{
            // 스택이 입력보다 높으면
            while(precedence(token_stack[token_top]) >= precedence(token) && token_top != -1){ // 우선순위
                printf("%c ", pop_token());
            }
            push_token(token);
        }
    }

    while(token_top != -1){ // 남아 있는 모든 원소 출력
        printf("%c ", pop_token());
    }
}

int precedence(char op){
    if(op == '(')
        return 0;
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/' || op == '%')
        return 2;
}

void push_token(char sym){
    if(token_top < STACK_SIZE)
        token_stack[++token_top] = sym;
    else
        printf("token stack full\n");
}

char pop_token(){
    if(token_top >= 0)
        return token_stack[token_top--];

    printf("token stack empty \n");
    return ' ';
}
