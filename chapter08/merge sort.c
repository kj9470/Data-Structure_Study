#include <stdio.h>
// 합병 정렬
void mergesort(int num[], int left, int right);
void merge(int num[], int left, int mid, int right);
void print_array(int num[], int n);

int main() {
    int num[] = {40,15,34,29,3,10,9,17,37};
    print_array(num, 9);
    mergesort(num, 0, 8);
}

void mergesort(int num[], int left, int right){
    int mid;
    if(right > left){ // 오른쪽이 더 크면
        mid = (right + left) / 2; // 둘을 더해 나눈 값 mid에 저장
        mergesort(num, left, mid); // 재귀 호출
        mergesort(num, mid + 1, right); // left를 mid + 1로 대체해 재귀호출
        merge(num, left, mid + 1, right); // merge 함수
        print_array(num, 9);
    }
}

void merge(int num[], int left, int mid, int right){
    int i, left_end, num_items, tmp_pos;
    int temp[100];

    left_end = mid - 1;
    tmp_pos = left;
    num_items = right - left + 1; // right에서 left 빼고 1 더해 item에 넣음

    while((left <= left_end) && (mid <= right)){ // mid - 1보다 left가 작을 때 && mid가 right보다 작을 때
        if(num[left] <= num[mid]){ // left가 mid보다 작다면
            temp[tmp_pos] = num[left]; // temp에 left 값 넣음
            tmp_pos = tmp_pos + 1; // pos 값 증가
            left = left + 1; // left 값 증가
        }
        else{
            temp[tmp_pos] = num[mid]; // temp에 mid 값 넣음
            tmp_pos = tmp_pos + 1; // pos 값 증가
            mid = mid + 1; // mid 값 증가
        }
    }

    while(left <= left_end){ // left가 left_end 보다 작을 때
        temp[tmp_pos] = num[left]; // 첫번째 세그먼트에 남아있는 항목 추가
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }

    while(mid <= right){ // mid가 right 보다 작을 때
        temp[tmp_pos] = num[mid]; // 두번째 세그먼트에 남아있는 항목 추가
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }

    for(i = 0; i < num_items; i++){
        num[right] = temp[right]; // temp 배열을 num 배열에 복사
        right = right - 1;
    }
}

void print_array(int num[], int n){ // 배열 출력
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
}
