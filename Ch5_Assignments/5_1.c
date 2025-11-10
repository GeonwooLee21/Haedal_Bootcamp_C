#include <stdio.h>

int main() {
    // 파일 스트림 생성
    FILE *fp = fopen("data.txt", "wt");

    // 파일 스트림 생성에 실패 했을 시
    if (fp == NULL) {
        printf("Failed to open file");
        return -1;
    }

    // 파일 스트림 생성에 성공 했을 시. 생성된 파일에 문자 하나씩 입력
    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);

    // 파일 스트림 종료
    fclose(fp);
    return 0;
}