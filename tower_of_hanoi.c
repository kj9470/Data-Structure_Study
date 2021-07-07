#include <stdio.h>
#include <time.h>
// program 3.5 하노이 타워

int count; // htower 함수가 실행된 횟수
void htower(int n, int a, int b); // htower 함수

void main() {
    int n; // 원판 개수
    count = 0; // 횟수 초기화
    double result;
    clock_t start, end;
    printf("Enter disc number : ");
    scanf("%d", &n); // 원판 개수
    start = clock();
    htower(n, 1, 2); // 원판 개수와 기둥 a, b
    printf("# move for %d discs : %d\n ", n, count); // 원판의 개수와 htower 함수가 실행된 횟수 출력
    end = clock();
    result = (double)(end - start);
    printf("%f", result);

}

void htower(int n, int a, int b){
    int c; // 기둥 c
    count++; // count 증가
    if(n == 1) // 원판이 하나라면
        printf("Disc %d, moved from Pole (%d) to (%d)\n", n, a, b); // 바로 출력
    else{ // 원판이 여러개라면
        c = 6 - a - b; // 빈 기둥 찾기
        htower(n - 1, a, c); // htower 함수 호출해 n - 1개의 원판을 빈 기둥으로 옮김
        printf("Disc %d, moved from Pole (%d) to (%d)\n", n, a, b); // 옮긴 상황 출력
        htower(n - 1, a, c); // htower 함수 호출해 다시 빈 기둥으로 옮김
    }
}

