#include <stdio.h>
// 삽입 정렬
void print_array(int num[], int n);
void insertion_sort(int num[], int n);

int main() {
    int num[] = {5,1,2,7,4,6,3,9,8};
    insertion_sort(num, 10);
}

void print_array(int num[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
}

void insertion_sort(int num[], int n){
    int i, j, pivot;
    for(i = 1; i < n; i++){ // i는 1부터 시작
        pivot = num[i]; // i의 값을 pivot에 넣음
        for(j = i - 1; j >= 0 && pivot < num[j]; j--)
            // j에는 i - 1의 값을 넣고 j가 0보다 같거나 클 때, i의 값이 j보다 크면
            // j + 1에 j 값을 넣음
            num[j + 1] = num[j];

        num[j + 1] = pivot; // 그리고 .j + 1에는 i 값을 넣음
        print_array(num, n);
    }
}
