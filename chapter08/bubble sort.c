#include <stdio.h>
// 버블 정렬
void print_array(int num[], int n);
void bubble_sort(int num[], int n);

int main() {
    int num[] = {8,7,3,2,5,4,1,6,9};
    bubble_sort(num, 9);
}

void print_array(int num[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
}

void bubble_sort(int num[], int n){
    int i, j, swap, temp;

    for(i = 0; i < n - 1; i++){
        swap = 0; // swap 0으로 설정
        for(j = 0; j < n - 1; j++){
            if(num[j] > num[j + 1]){ // j가 j + 1보다 크면
                temp = num[j]; // 위치 바꾸기
                num[j] = num[j + 1];
                num[j + 1] = temp;
                swap = 1; // swap 1로 설정
            }
        }
        if(swap == 0) break; // swap이 0이 되면 멈추고 출력
        print_array(num, n);
    }
}
