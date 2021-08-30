#include <stdio.h>
#include <stdlib.h>

typedef struct treenode * node_ptr;
struct treenode{
    char data;
    node_ptr left;
    node_ptr right;
};

node_ptr tree;

int main() {
    printf("Hello, World!\n");
    return 0;
}

void insert_BST(node_ptr tree, int item){
    node_ptr node = (node_ptr)malloc(sizeof(struct treenode)); // 공간할당
    node_ptr temp, prev;

    node->data = item;
    node->left = NULL;
    node->right = NULL;

    if(tree == NULL){ // 트리가 비었을 때
        tree = node;
    }
    else{
        temp = tree;
        prev = NULL;

        while(1){
            prev = temp;
            if(item < prev->data){ // item이 작을 때
                temp = temp->left; // 왼쪽 서브 트리로 이동
                if(temp == NULL){ // 트리가 비었을 때
                    prev->left = node; // 추가하고 리턴
                    return;
                }
            }
            else if(item > prev->data){ // item이 더 클 때
                temp = temp->right; // 오른쪽 서브 트리로 이동
                if(temp == NULL){
                    prev->right = node;
                    return;
                }
            }
            else return; // 중복 노드일 때
        }
    }
}
