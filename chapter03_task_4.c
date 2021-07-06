#include <stdio.h>
#define exchange(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
int start = 0, end = 0;
void word(char *letter, int i, int n);

int main() {
    char letter[] = {'S', 'M', 'W', 'U', 'T'};
    scanf("%d %d", &start, &end);
    word(letter, start, end);
}

void word(char * letter, int i, int n){
    int temp = 0;
    if(i == n){
        for(int j = start; j <= end; j++)
            printf("%c", letter[j]);
        printf("\n");
    }
    else for(int j = i; j <= n; j++){
        exchange(letter[i], letter[j], temp);
        word(letter, i + 1, n);
        exchange(letter[i], letter[j], temp);
    }
}
