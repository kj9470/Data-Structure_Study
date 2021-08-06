#include <stdio.h>
// program 3.2 greatest common divisor

int gcd(int x, int y); // x와 y의 최대공약수를 구하는 함수

int main() {
    int x = 128, y = 12; // x와 y를 선언
    printf("gcd (%d, %d) = %d\n", x, y, gcd(x, y));
}

int gcd(x, y){ // x와 y를 매개변수로 받음
    if (y == 0) return x; // y가 0이 되면 return x
    else return gcd (y, x % y); // 아니라면 y랑 x % y를 gcd 함수로 다시 리턴
}
