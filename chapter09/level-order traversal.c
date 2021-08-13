#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct tree_node * tree_node_ptr;
struct tree_node{
    char data;
    tree_node_ptr left;
    tree_node_ptr right;
};

int front = 0;
int rear = 0;
tree_node_ptr queue[MAX_SIZE];

tree_node_ptr tree;
void level_order(tree_node_ptr ptr);
tree_node_ptr make_node(char data);
void addq(tree_node_ptr node);
tree_node_ptr deleteq();

int main() {
    tree_node_ptr temp1, temp2;
    tree = make_node('-');
    temp1 = tree->left = make_node('+');
    temp2 = tree->right = make_node('/');

    temp1->left = make_node('*');
    temp1->right = make_node('C');

    temp2->left = make_node('D');
    temp2->right = make_node('E');

    temp1->left->left = make_node('A');
    temp1->left->right = make_node('B');
    level_order(tree);
}

tree_node_ptr make_node(char data){
    tree_node_ptr temp;
    temp = (tree_node_ptr)malloc(sizeof(struct tree_node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void level_order(tree_node_ptr node){
    if(!node) return;
    addq(node);
    while(1){
        node = deleteq();
        if(node){
            printf("%c ", node->data);
            if(node->left) addq(node->left);
            if(node->right) addq(node->right);
        }
        else break; // 큐가 empty 라면
    }
}


void addq(tree_node_ptr node){
    if(rear < MAX_SIZE)
        queue[rear++] = node;
}

tree_node_ptr deleteq(){
    return queue[front++];
}