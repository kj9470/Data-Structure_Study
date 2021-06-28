#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10000

typedef struct { // 스택 구조체
	int stack[STACK_SIZE];
	int top;
}stack;

void init(stack *s) { // top 초기화해주는 함수
	s->top = -1;
}

typedef enum { // 연산자
	open_b, close_b, plus, minus, times, divide, mod, eos, operand
} priority;

void infix_to_postfix(char *in, char *post);
int precedence(char op); // 우선순위 가려주는 함수
void push(stack *s, int item); // push 함수
int pop(stack *s); // pop 함수
int check(stack *s); // 스택 확인 함수
int is_empty(stack *s); // 스택 비었는지 확인하는 함수
int eval_postfix(char *post); // 식 계산 함수
priority read(char *item); // 연산자
int change(char *n, int *i);
void print(stack *s);
void print_c(stack *s);

stack s; // 스택 선언

int main() {
	char in[STACK_SIZE]; // infix 배열
	char post[STACK_SIZE] = { 0 }; // postfix 배열
	printf("input an infix notation to convert : ");
	gets(in); // 문자열 입력받음
	infix_to_postfix(in, post); // postfix로 변환
	printf("\ninfix : %s\n", in);
	printf("postfix : %s\n", post);
	printf("\n");
	eval_postfix(post);
	getch();
}

void infix_to_postfix(char *in, char *post) {
	init(&s); // 초기화

	while (*in != '\0') { // '\0'이 아닐 때까지
		if (*in == '(') { // 열린괄호일때
			push(&s, *in); // push
			print_c(&s); // 스택 변화 출력
			in++; // 다음
		}
		else if (*in == ')') { // 닫힌괄호일때
			while (check(&s) != '(') { // 열린괄호가 나올때까지
				*post++ = pop(&s); // pop
				*post++ = ' '; // 공백 담기
			}
			pop(&s); // 괄호 pop
			print_c(&s); // 스택 변화 출력
			in++; // 다음
		}
		else if (*in == '+' || *in == '-' || *in == '*' || *in == '/') { // 연산자일 때
			while (!is_empty(&s) && (precedence(*in) <= precedence(check(&s)))) { // 비어있지 않고 스택보다 우선순위가 낮다면
				*post++ = pop(&s); // pop
				*post++ = ' '; // 공백 담기
			}
			push(&s, *in); // 우선순위가 높으면 push
			print_c(&s); // 스택 변화 출력
			in++; // 다음
		}
		else if (*in >= '0' && *in <= '9') { // 피연산자일 때
			do {
				*post++ = *in++; // 숫자 넣음
			} while (*in >= '0' && *in <= '9'); // 숫자가 끝날 때까지 (여러 자리 숫자)
			*post++ = ' '; // 공백 담기
		}
		else
			in++; // 증가
	}
	while (!is_empty(&s)) { // 스택이 비어있지 않을 때
		*post++ = pop(&s); // 모두 post에 넣음
		*post++ = ' '; // 공백 담기
	}
	post--;
	*post = '\0';
}

int precedence(char op) { // 연산자 우선순위
	if (op == '(')
		return 0;
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/' || op == '%')
		return 2;
}

void push(stack *s, int item) { // push 함수
	if (s->top < STACK_SIZE) { // top이 STACK_SIZE보다 작을 때 push
		s->stack[++(s->top)] = item;
	}
	else
		printf("token stack full\n");
}

int pop(stack *s) { // pop함수
	if (s->top >= 0) // top이 0과 같거나 클 때 pop
		return s->stack[(s->top)--];
	else {
		printf("token stack empty\n");
		return;
	}
}

int check(stack *s) { // 스택 체크 함수
	if (s->top >= 0) // top이 0과 같거나 클 때
		return s->stack[s->top]; // top 위치에 있는 원소를 리턴
	else {
		printf("token stack empty\n");
		return;
	}
}

int is_empty(stack *s) { // 스택 비었는지 확인하는 함수
	return(s->top == -1);
}

int eval_postfix(char *post) { // 계산 함수
	priority temp; // 연산자
	int value, op1, op2, i;
	stack s; // 스택 선언
	init(&s); // 초기화
	for (i = 0; post[i] != '\0'; i++) { // post[i]가 '\0'이 아닐 때까지 반복
		if (post[i] == ' ') // 공백이라면
			i++; // i 증가
		temp = read(&post[i]); // post[i]값을 read 함수에 넣어 temp에 넣음
		if (temp == operand) { // temp가 피연산자라면
			value = change(&post[i], &i); // value에 문자열을 정수로 변환해 넣음
			push(&s, value); // 변화한 value값 push
			print(&s);
		}
		else {
			op2 = pop(&s); // 먼저 꺼낸 피연산자
			op1 = pop(&s); // 나중에 꺼낸 피연산자
			switch (temp) { // 연산자에 따라 계산
			case plus: push(&s, op1 + op2); print(&s); break;
			case minus: push(&s, op1 - op2); print(&s); break;
			case times: push(&s, op1 * op2); print(&s); break;
			case divide: push(&s, op1 / op2); print(&s); break;
			}
		}
	}
	printf("계산 결과 : ");
	print(&s);
	printf("\n");
}

priority read(char *point) { // 연산자
	switch (*point) {
	case '(': return open_b; break;
	case ')': return close_b; break;
	case '+': return plus; break;
	case '-': return minus; break;
	case '*': return times; break;
	case '/': return divide; break;
	case '%': return mod; break;
	case '\0': return eos; break;
	default: return operand;
	}
}

int change(char *n, int *index) { // 피연산자 정수 변환 함수
	int value;
	char temp[100];
	int k, j;
	for (k = 0; n[k] != ' '; k++) // 공백이 아닐 때까지 반복
		temp[k] = n[k]; // temp에 피연산자 값을 담음
	temp[k] = '\0'; // 끝에 '\0' 담음
	value = atoi(temp); // 정수로 변환해 value에 저장
	j = *index; // j에 index값 저장 (위에서 i값)
	*index = j + k; // 피연산자 자릿수만큼 더해서 index(i)값 변환
	return value; // 변환한 값 리턴
}

void print(stack *s) { // 스택 출력 함수
	for (int i = 0; i <= s->top; i++) {
		printf("%d ", s->stack[i]);
	}
	printf("\n");
}

void print_c(stack *s) { // 스택 출력 함수(연산자)
	for (int i = 0; i <= s->top; i++) {
		printf("%c ", s->stack[i]);
	}
	printf("\n");
}