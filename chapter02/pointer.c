#include <stdio.h>

int main() {
    int i = 3, j;
    int * p;
    p = &i;
    j = *p;
    j = j + 1;
    *p = j * 2;
    printf("%d %d %d %u", i, j, *p, &p);
}
