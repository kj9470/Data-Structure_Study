#include <stdio.h>
// program 3.3 이진 탐색

int binary_search(int mylist[], int item, int left, int right); // 값을 찾는 함수

void main() {
    int pos, maxnum = 12, item = 60; // 찾는 값 : 60
    int mylist[] = {5, 8, 9, 11, 13, 17, 23, 32, 45, 52, 60, 72};
    pos = binary_search(mylist, item, 0, maxnum - 1);
    printf("position = %d", pos);
}

int binary_search(int list[], int item, int left, int right){
    int mid; // 중간값
    while(left <= right){ // right가 left보다 같거나 클때 반복
        mid = (left + right) / 2; // 중간값
        if(list[mid] == item) // 원하는 값을 찾았을 때
            return mid; // 그 값의 인덱스값 리턴
        else{
            if(item < list[mid]) // 원하는 값이 mid보다 작을 때
                right = mid - 1; // right에 mid - 1 대입
            else // 원하는 값이 mid보다 크다면
                left = mid + 1; // left에 mid + 1 대입
        }
    }
    return -1; // 원하는 값이 없다면 -1 리턴
}
