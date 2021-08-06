#include <stdio.h>
char *list[] = {'a', 'b', 'c', 'd'};

void swap(char *list[], int a, int b){
    char temp = 0;
    temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void perm(char *list[], int i, int n){
    int j;
    if (i == n){
        for(j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("  ");
    }
    else{
        for(j = i; i <= n; j++){
            swap(&list, i, j);
            perm(list, i++, n);
            swap(&list, i, j);
        }
    }
}

int main() {
    perm(&list, 0, 3);
    return 0;
}
