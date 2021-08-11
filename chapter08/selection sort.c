#include <stdio.h>
// 최소값 우선 탐색 선택 정렬
void print_array(int num[], int n);
void selection_sort(int num[], int n);

int main() {
    int num[] = {5,7,9,6,3,2,1,8};
    selection_sort(num, 8);
}

void print_array(int num[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", num[i]);

    printf("\n");
}

void selection_sort(int num[], int n){
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){ // j에 i의 다음 값을 넣음
            if(num[j] < num[min]) // j가 i보다 작으면
                min = j; // min에 j를 넣음
        }
        temp = num[i]; // i와 min의 자리를 교환
        num[i] = num[min];
        num[min] = temp;

        print_array(num, n);
    }
}
