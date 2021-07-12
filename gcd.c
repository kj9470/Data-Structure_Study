#include <stdio.h>

int gcd(int x, int y);

int main() {
    int x = 128, y = 12;
    printf("gcd ( %d, %d ) = %d \n", x, y, gcd(x, y));
    return 0;
}

int gcd(x, y){
    if (y == 0) return x;
    else return gcd(y, x % y);
}
