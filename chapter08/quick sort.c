#include <stdio.h>
// 퀵 정렬
void print_array(int num[], int n);
void quicksort(int num[], int left, int right);

int main() {
    int num[] = {25, 30, 17, 14, 49, 66, 23, 39};
    print_array(num, 8);
    quicksort(num, 0, 7);
}

void quicksort(int num[], int left, int right){
    int pivot, i, j, temp;
    if(left < right){ // right가 더 클 때
        i = left;
        j = right + 1; // j에 right + 1
        pivot = num[left]; // pivot에는 left 값을 넣음
        do{ // i가 j보다 작을 때 반복
            do{ i++; } while(num[i] < pivot); // i가 pivot보다 작을 때 i 증가
            do{ j--; } while(num[j] > pivot); // j가 pivot보다 클 대 j 증가
            if(i < j){ // i가 j보다 작을 때
                temp = num[i]; // i와 j의 위치 바꿈
                num[i] = num[j];
                num[j] = temp;
                print_array(num, 10);
            }
        } while(i < j);
        // i가 j보다 클 때 위치 바꿈
        temp = num[left]; // left와 j의 위치 바꿈
        num[left] = num[j];
        num[j] = temp;

        if(left != j) print_array(num, 10);
        // j를 기준으로 정렬 범위를 조정하여 왼쪽고 ㅏ오른쪽 서브 리스트에 대해 각각 quicksort 함수 호출
        // 재귀적으로 진행
        quicksort(num, left, j - 1);
        quicksort(num, j + 1, right);
    }
}

void print_array(int num[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
}


