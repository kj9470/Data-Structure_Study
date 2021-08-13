#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node * tree_node_ptr;
struct tree_node{
    int data;
    int value;
    tree_node_ptr left;
    tree_node_ptr right;
};

tree_node_ptr tree;
void eval_tree(tree_node_ptr ptr);
tree_node_ptr make_node(char data);

int main() {
    tree_node_ptr temp1, temp2;
    tree = make_node('-');
    temp1 = tree->left = make_node('+');
    temp2 = tree->right = make_node('/');

    temp1->left = make_node('*');
    temp1->right = make_node('3');

    temp2->left = make_node('8');
    temp2->right = make_node('2');

    temp1->left->left = make_node('4');
    temp1->left->right = make_node('5');
    eval_tree(tree);
    printf("%d\n", tree->value);
}

tree_node_ptr make_node(char data){
    tree_node_ptr temp;
    temp = (tree_node_ptr)malloc(sizeof(struct tree_node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void eval_tree(tree_node_ptr node){
    if(node){
        eval_tree(node->left);
        eval_tree(node->right);
        switch(node->data){
            case '+' : node->value = node->left->value + node->right->value; break;
            case '-' : node->value = node->left->value - node->right->value; break;
            case '*' : node->value = node->left->value * node->right->value; break;
            case '/' : node->value = node->left->value / node->right->value; break;
            default : node->value = node->data - '0'; printf("%d ", node->value); // 피연산자
        }
    }
}
