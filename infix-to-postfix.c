#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10000

typedef struct { // ���� ����ü
	int stack[STACK_SIZE];
	int top;
}stack;

void init(stack *s) { // top �ʱ�ȭ���ִ� �Լ�
	s->top = -1;
}

typedef enum { // ������
	open_b, close_b, plus, minus, times, divide, mod, eos, operand
} priority;

void infix_to_postfix(char *in, char *post);
int precedence(char op); // �켱���� �����ִ� �Լ�
void push(stack *s, int item); // push �Լ�
int pop(stack *s); // pop �Լ�
int check(stack *s); // ���� Ȯ�� �Լ�
int is_empty(stack *s); // ���� ������� Ȯ���ϴ� �Լ�
int eval_postfix(char *post); // �� ��� �Լ�
priority read(char *item); // ������
int change(char *n, int *i);
void print(stack *s);
void print_c(stack *s);

stack s; // ���� ����

int main() {
	char in[STACK_SIZE]; // infix �迭
	char post[STACK_SIZE] = { 0 }; // postfix �迭
	printf("input an infix notation to convert : ");
	gets(in); // ���ڿ� �Է¹���
	infix_to_postfix(in, post); // postfix�� ��ȯ
	printf("\ninfix : %s\n", in);
	printf("postfix : %s\n", post);
	printf("\n");
	eval_postfix(post);
	getch();
}

void infix_to_postfix(char *in, char *post) {
	init(&s); // �ʱ�ȭ

	while (*in != '\0') { // '\0'�� �ƴ� ������
		if (*in == '(') { // ������ȣ�϶�
			push(&s, *in); // push
			print_c(&s); // ���� ��ȭ ���
			in++; // ����
		}
		else if (*in == ')') { // ������ȣ�϶�
			while (check(&s) != '(') { // ������ȣ�� ���ö�����
				*post++ = pop(&s); // pop
				*post++ = ' '; // ���� ���
			}
			pop(&s); // ��ȣ pop
			print_c(&s); // ���� ��ȭ ���
			in++; // ����
		}
		else if (*in == '+' || *in == '-' || *in == '*' || *in == '/') { // �������� ��
			while (!is_empty(&s) && (precedence(*in) <= precedence(check(&s)))) { // ������� �ʰ� ���ú��� �켱������ ���ٸ�
				*post++ = pop(&s); // pop
				*post++ = ' '; // ���� ���
			}
			push(&s, *in); // �켱������ ������ push
			print_c(&s); // ���� ��ȭ ���
			in++; // ����
		}
		else if (*in >= '0' && *in <= '9') { // �ǿ������� ��
			do {
				*post++ = *in++; // ���� ����
			} while (*in >= '0' && *in <= '9'); // ���ڰ� ���� ������ (���� �ڸ� ����)
			*post++ = ' '; // ���� ���
		}
		else
			in++; // ����
	}
	while (!is_empty(&s)) { // ������ ������� ���� ��
		*post++ = pop(&s); // ��� post�� ����
		*post++ = ' '; // ���� ���
	}
	post--;
	*post = '\0';
}

int precedence(char op) { // ������ �켱����
	if (op == '(')
		return 0;
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/' || op == '%')
		return 2;
}

void push(stack *s, int item) { // push �Լ�
	if (s->top < STACK_SIZE) { // top�� STACK_SIZE���� ���� �� push
		s->stack[++(s->top)] = item;
	}
	else
		printf("token stack full\n");
}

int pop(stack *s) { // pop�Լ�
	if (s->top >= 0) // top�� 0�� ���ų� Ŭ �� pop
		return s->stack[(s->top)--];
	else {
		printf("token stack empty\n");
		return;
	}
}

int check(stack *s) { // ���� üũ �Լ�
	if (s->top >= 0) // top�� 0�� ���ų� Ŭ ��
		return s->stack[s->top]; // top ��ġ�� �ִ� ���Ҹ� ����
	else {
		printf("token stack empty\n");
		return;
	}
}

int is_empty(stack *s) { // ���� ������� Ȯ���ϴ� �Լ�
	return(s->top == -1);
}

int eval_postfix(char *post) { // ��� �Լ�
	priority temp; // ������
	int value, op1, op2, i;
	stack s; // ���� ����
	init(&s); // �ʱ�ȭ
	for (i = 0; post[i] != '\0'; i++) { // post[i]�� '\0'�� �ƴ� ������ �ݺ�
		if (post[i] == ' ') // �����̶��
			i++; // i ����
		temp = read(&post[i]); // post[i]���� read �Լ��� �־� temp�� ����
		if (temp == operand) { // temp�� �ǿ����ڶ��
			value = change(&post[i], &i); // value�� ���ڿ��� ������ ��ȯ�� ����
			push(&s, value); // ��ȭ�� value�� push
			print(&s);
		}
		else {
			op2 = pop(&s); // ���� ���� �ǿ�����
			op1 = pop(&s); // ���߿� ���� �ǿ�����
			switch (temp) { // �����ڿ� ���� ���
			case plus: push(&s, op1 + op2); print(&s); break;
			case minus: push(&s, op1 - op2); print(&s); break;
			case times: push(&s, op1 * op2); print(&s); break;
			case divide: push(&s, op1 / op2); print(&s); break;
			}
		}
	}
	printf("��� ��� : ");
	print(&s);
	printf("\n");
}

priority read(char *point) { // ������
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

int change(char *n, int *index) { // �ǿ����� ���� ��ȯ �Լ�
	int value;
	char temp[100];
	int k, j;
	for (k = 0; n[k] != ' '; k++) // ������ �ƴ� ������ �ݺ�
		temp[k] = n[k]; // temp�� �ǿ����� ���� ����
	temp[k] = '\0'; // ���� '\0' ����
	value = atoi(temp); // ������ ��ȯ�� value�� ����
	j = *index; // j�� index�� ���� (������ i��)
	*index = j + k; // �ǿ����� �ڸ�����ŭ ���ؼ� index(i)�� ��ȯ
	return value; // ��ȯ�� �� ����
}

void print(stack *s) { // ���� ��� �Լ�
	for (int i = 0; i <= s->top; i++) {
		printf("%d ", s->stack[i]);
	}
	printf("\n");
}

void print_c(stack *s) { // ���� ��� �Լ�(������)
	for (int i = 0; i <= s->top; i++) {
		printf("%c ", s->stack[i]);
	}
	printf("\n");
}