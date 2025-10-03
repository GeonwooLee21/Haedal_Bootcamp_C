#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    //getchar();

    char S[21];
    char P[161];

    for (int i = 0; i < T; i++) {
        int R;
        scanf("%d %s", &R, S); 
        // %d가 먼저 실행됨. 이때 %d는 공백·엔터 같은 건 무시하고 숫자부터 읽으므로, 앞 전에 문자열을 입력받았을 때 남은 '\n'은 그냥 건너뜀.
        getchar(); 
        // 입력 흐름이 전부 정수 → 문자열 구조라 줄바꿈 문자가 끼어도 자동으로 무시되므로. 굳이 getchar()를 이용해 따로 버퍼를 비워줄 필요가 없다.

        int m = 0;
        for (int j = 0; S[j] != '\0'; j++) {
            for (int k = 0; k < R; k++) {
                P[m++] = S[j];
            }
        }

        for (int n = 0; n < m; n++) {
            printf("%c", P[n]);
        }
        printf("\n");
    }
    
    return 0;
}