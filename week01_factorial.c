#include <stdio.h>
#define SIZE 200
// 팩토리얼 계산하기

int main() {
    int x[SIZE] = {1}, y[SIZE] = {0}, z[SIZE] = {0};
    int factorial = 100;
    int i, j, k;

    for(i = 1; i <= factorial; i++){
        y[0] = i;
        for(j = 0; j < 2; j++){ // y 자리올림
            y[j + 1] += y[j] / 10; // 10 이상이면 10으로 나눈 몫을 다음 자리로 자리 올림
            y[j] -= (y[j] / 10) * 10; // 10 이상이면 십의자리를 빼줌
        }

        for(j = 0; j < 3; j++){ // 배열 x와 배열 y의 곱셈
            for(k = 0; k < SIZE; k++){
                z[j + k] += x[k] * y[j];
            }
        }

        for(j = 0; j < SIZE - 1; j++){ // 배열 z의 자리올림
            z[j + 1] += z[j] / 10; // 10 이상이면 10으로 나눈 몫을 다음 자리로 자리 올림
            z[j] -= (z[j] / 10) * 10; // 10 이상이면 십의자리를 빼줌
        }

        for(j = 0; j < SIZE; j++){ // 배열 z를 x로 복사 및 배열 z의 초기화
            x[j] = z[j];
            z[j] = 0;
        }

        for(j = 0; j < 3; j++){ // 초기화
            y[j] = 0;
        }

        j = SIZE - 1; // 배열의 마지막 주소는 크기 - 1

        while(x[j--] == 0); // 처음으로 유효한 값 찾기
        printf("%3d! = ", i);
        for(j = j + 1; j >= 0; j--){ // 출력
            printf("%d", x[j]);
        }
        printf("\n");
    }
}

