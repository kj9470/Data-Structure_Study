#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct node_type *node_ptr;
typedef struct link_stack *link;

struct node_type {
	int num;
	int shape;
	int show;
	node_ptr llink;
	node_ptr rlink;
};

struct link_stack {
	int num;
	int shape;
	int show;
	node_ptr link;
};

node_ptr t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;
link top;
int count;

void init_card(); // tree 생성 함수
void reset_board(); // shape 개수 선택과 tree와 stack 값 초기화
void insert(node_ptr node); // 카드 랜덤 값 할당 함수
void show_board(); // board 출력 함수
void push(link stack); // push 함수
void reset_stack(); // stack 전체 카드 값 초기화
link pop(); // pop 함수
void pop_handcard(); // 카드를 제거할 때 사용되는 함수
node_ptr node_switch(int n); // 원하는 노드를 반환해주는 함수
int isEmpty(); // 스택이 비었는지 확인해주는 함수
node_ptr delete(node_ptr node); // 카드를 화면상에서 제거해주는 함수

int mark[4][13]; 
static char* cshape[5] = { "♥", "♠", "♣", "◆" };
int NUM_SHAPE = 0;
int HAND_CARD = 0;

int main() {
	srand(time(NULL));
	init_card();
	reset_board();
	while (1) {
		show_board();
		if (t0->num != -1) {
			pop_handcard();
			if (count == 0) {
				printf("\n You Lose.. \n");
				return;
			}
		}
		if (t0->num == -1) {
			printf("\n You Win !! \n");
			return;
		}
	}
	getch();
}

void init_card() {
	t0 = (node_ptr)malloc(sizeof(struct node_type));
	t1 = (node_ptr)malloc(sizeof(struct node_type));
	t2 = (node_ptr)malloc(sizeof(struct node_type));
	t3 = (node_ptr)malloc(sizeof(struct node_type));
	t4 = (node_ptr)malloc(sizeof(struct node_type));
	t5 = (node_ptr)malloc(sizeof(struct node_type));
	t6 = (node_ptr)malloc(sizeof(struct node_type));
	t7 = (node_ptr)malloc(sizeof(struct node_type));
	t8 = (node_ptr)malloc(sizeof(struct node_type));
	t9 = (node_ptr)malloc(sizeof(struct node_type));
	top = (link)malloc(sizeof(struct link_stack));

	t0->llink = t1;
	t0->rlink = t2;
	t1->llink = t3;
	t1->rlink = t4;
	t2->llink = t4;
	t2->rlink = t5;
	t3->llink = t6;
	t3->rlink = t7;
	t4->llink = t7;
	t4->rlink = t8;
	t5->llink = t8;
	t5->rlink = t9;
	t6->llink = NULL;
	t6->rlink = NULL;
	t7->llink = NULL;
	t7->rlink = NULL;
	t8->llink = NULL;
	t8->rlink = NULL;
	t9->llink = NULL;
	t9->rlink = NULL;
}

void reset_board() {
	printf("2 set or 4 set? (2 or 4) : ");
	scanf("%d", &NUM_SHAPE);
	if (NUM_SHAPE == 2) HAND_CARD = 16;
	else HAND_CARD = 42;

	insert(t0);
	insert(t1);
	insert(t2);
	insert(t3);
	insert(t4);
	insert(t5);
	insert(t6);
	insert(t7);
	insert(t8);
	insert(t9);

	reset_stack();

}

void reset_stack() {
	for (int j = 0; j < HAND_CARD; j++) {
		link new;
		new = (link)malloc(sizeof(struct link_stack));
		insert(new);
		push(new);
	}
}

void push(link stack) {
	link new;
	new = (link)malloc(sizeof(struct link_stack));
	new->num = stack->num;
	new->shape = stack->shape;
	new->show = stack->show;
	new->link = top;
	top = new;
	count++;
}

link pop() {
	if (!isEmpty()) {
		--count;
		link temp = top;
		top = temp->link;
		free(temp);
	}
	else {
		printf("\n pop error \n");
	}
	return top;
}

node_ptr delete(node_ptr node) {
	node->num = -1;
}

void insert(node_ptr node) {
	int num = rand() % 13;
	int shape = rand() % NUM_SHAPE;
	node->num = num;
	node->shape = shape;
	node->show = 0;
	if (mark[shape][num] == 0) {
		mark[shape][num] = 1;
		return;
	}
	else if (mark[shape][num] == 1) {
		insert(node);
	}
}

void pop_handcard() {
	int del;
	scanf("%d", &del);
	printf("\n");

	if (del == -1) {
		pop();
		return;
	}
	else if (del >= 0 && del <= 10) {
		node_ptr node = node_switch(del - 1);
		int card_num = node->num;
		int hand_num = top->num;
		if (hand_num - card_num == 1 || hand_num - card_num == -1 ||
			hand_num - card_num == 12 || hand_num - card_num == -12) {

			switch (node->num)
			{
			case 0: printf("%sA is removed.\n\n", cshape[node->shape]); break;
			case 10: printf("%sJ is removed.\n\n", cshape[node->shape]); break;
			case 11: printf("%sQ is removed.\n\n", cshape[node->shape]); break;
			case 12: printf("%sK is removed.\n\n", cshape[node->shape]); break;
			default: printf("%s%d is removed.\n\n", cshape[node->shape], node->num + 1); break;
			}
			push(node);
			delete(node);
			return;
		}
		else {
			printf("\n -- Wrong number -- \n");
			return;
		}
	}
	else {
		printf("\n -- Wrong number -- \n");
		return;
	}
}


void show_board()
{
	int i = 0, j = 0, sum, temp = 0;
	node_ptr node;
	t6->show = 1;
	t7->show = 1;
	t8->show = 1;
	t9->show = 1;

	for (i = 0; i < 4; i++) // i는 줄 수
	{
		printf("\n");
		if (i == 0)      printf("   1             ");
		else if (i == 1) printf("  2 3          ");
		else if (i == 2) printf(" 4 5 6       ");
		else if (i == 3) printf("7 8 9 10  ");

		sum = i + j;
		j = temp + i;
		temp = j;
		for (; j <= sum; j++) // tree 출력
		{
			node = node_switch(j);
			if (j <= 5) {
				node_ptr left = node->llink;
				node_ptr right = node->rlink;
				if (left->num == -1 && right->num == -1) node->show = 1;
			}

			if (node->show == 0) printf("■  ");
			else if (node == NULL) printf("    ");
			else
			{
				switch (node->num)
				{
				case -1: printf("    "); break;
				case 0: printf("%sA ", cshape[node->shape]); break;
				case 9: printf("%s10", cshape[node->shape]); break;
				case 10: printf("%sJ ", cshape[node->shape]); break;
				case 11: printf("%sQ ", cshape[node->shape]); break;
				case 12: printf("%sK ", cshape[node->shape]); break;
				default: printf("%s%d ", cshape[node->shape], node->num + 1); break;
				}
			}
		}
		printf("\n\n");
	}

	printf("\nYou have (%d) cards.\n", count);
	printf("===============================================================================\n");
	// stack 출력
	switch (top->num)
	{
	case 0: printf("%sA ", cshape[top->shape]); break;
	case 10: printf("%sJ ", cshape[top->shape]); break;
	case 11: printf("%sQ ", cshape[top->shape]); break;
	case 12: printf("%sK ", cshape[top->shape]); break;
	default: printf("%s%d ", cshape[top->shape], top->num + 1);
	}
	for (int i = 0; i < count - 1; i++) {
		printf("■ ");
	}
	printf("\n Enter a number [0..9] to remove -1 = new card) : ");
}

node_ptr node_switch(int n) {
	node_ptr node;
	switch (n) {
	case 0: node = t0; break;
	case 1: node = t1; break;
	case 2: node = t2; break;
	case 3: node = t3; break;
	case 4: node = t4; break;
	case 5: node = t5; break;
	case 6: node = t6; break;
	case 7: node = t7; break;
	case 8: node = t8; break;
	case 9: node = t9; break;
	}
	return node;
}

int isEmpty() {
	if (top == NULL) {
		printf("stack is Empty\n");
		return 1;
	}
	return 0;
}