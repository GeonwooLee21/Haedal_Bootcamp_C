#include <stdio.h>

#define MAX 1001

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    char S[MAX];
    for (int i = 0; i < T; i++) {
        fgets(S, MAX, stdin); // fgets() 함수는 첫 번째 줄 바꾸기 문자(\n)까지, 
                              // 또는 스트림이 끝에 도달하거나 읽은 문자 수가 n-1과 같을 때 까지 문자를 읽는다.

        int num;
        for (num = 0; S[num] != '\n'; num++) {}

        printf("%c%c\n", S[0], S[num-1]);
    }

    return 0;
}