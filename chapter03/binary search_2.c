#include <stdio.h>
// program 3.4 재귀 호출에 의한 이진 탐색

int rbinsearch(int mylist[], int item, int left, int right); // 재귀호출을 이용한 이진탐색 함수

int main() {
    int pos, maxnum = 12, item = 60; // 찾을 값 : 60
    int mylist[] = {5, 8, 9, 11, 13, 17, 23, 32, 45, 52, 60, 72};
    pos = rbinsearch(mylist, item, 0, maxnum - 1);
    printf("%d", pos);
}

int rbinsearch(int list[], int item, int left, int right){
    int mid; // 중간값
    if (left <= right){ // right가 left 보다 크거나 같을 때
        mid = (left + right) / 2; // 중간값
        if (list[mid] < item) // mid 값이 찾는 값보다 작을 때
            return rbinsearch(list, item, mid + 1, right); // rbinsearch 함수 다시 호출, mid + 1값 넣음
        else if (list[mid] > item)  // mid 값이 찾는 값보다 클 때
            return rbinsearch(list, item, left, mid - 1); // rbinsearch 함수 다시 호출, mid - 1값 넣음
        else return mid; // 깉으면 mid 값 리턴
    }
    return -1; // 찾는 값이 없으면 -1 리턴
}
