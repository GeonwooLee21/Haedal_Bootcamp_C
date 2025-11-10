#include <stdio.h>   // 표준 입출력 함수 (printf 같은 거) 쓰려고 포함
#include <stdlib.h>  // malloc, free 같은 동적 메모리 함수 쓰려고 포함

int main() {
    // int형 하나를 저장할 공간을 heap(힙 영역)에 할당하고, 그 주소를 ptr1이 가리키게 함
    int* ptr1 = (int*)malloc(sizeof(int));

    // int형 3개를 저장할 수 있는 공간을 heap에 할당하고, 그 주소를 ptr2가 가리키게 함
    int* ptr2 = (int*)malloc(sizeof(int) * 3);

    // ptr1이 가리키는 메모리(즉, int 하나짜리 공간)에 20을 저장
    *ptr1 = 20;

    // 반복문: ptr2 배열처럼 사용해서 0, 1, 2를 순서대로 저장
    for (int i = 0; i < 3; i++)
        ptr2[i] = i;

    // ptr1이 가리키는 값(즉, 20)을 출력
    printf("%d\n", *ptr1);

    // ptr2 배열에 저장된 값(0, 1, 2)을 순서대로 출력
    for (int i = 0; i < 3; i++)
        printf("%d ", ptr2[i]);

    // 동적 할당했던 메모리를 해제해서 메모리 누수 방지
    free(ptr1);
    free(ptr2);

    return 0;
}