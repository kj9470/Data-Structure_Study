#include <stdio.h>
// program 3-1 factorial

long factorial(int n){ // 재귀함수
    if(n == 0) // n이 0이 되면 종료
        return 1;
    else // 0이 아니라면 factorial 함수를 다시 호출해 n과 곱함
        return n * factorial(n - 1);
}

int main() {
    printf("factorial of %d is %d\n", 8, factorial(8)); // 8!의 값
    return 0;
}
