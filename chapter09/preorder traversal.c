#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node * tree_node_ptr;
struct tree_node{
    char data;
    tree_node_ptr left;
    tree_node_ptr right;
};

tree_node_ptr tree;
void preorder(tree_node_ptr ptr);
tree_node_ptr make_node(char data);

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
    preorder(tree);
}

tree_node_ptr make_node(char data){
    tree_node_ptr temp;
    temp = (tree_node_ptr)malloc(sizeof(struct tree_node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(tree_node_ptr ptr){
    if(ptr){
        printf(" %c ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

