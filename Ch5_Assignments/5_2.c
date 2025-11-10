#include <stdio.h>

int main() {
    char ch;

    // 파일 스트림 생성
    FILE *fp = fopen("data.txt", "rt");

    // 파일 스트림 생성에 실패했을 시
    if (fp == NULL) {
        printf("Failed to open file");
        return -1;
    }

    // 파일 스트림 생성에 성공했을 시
    for (int i = 0; i < 3; i++) {
        ch = fgetc(fp); // 파일에 입력되어 있는 문자들을 하나씩 입력 받음.
        printf("%c\n", ch); // 파일로부터 입력받은 문자들을 하나씩 터미널에 출력.
    }

    // 스트림 종료
    fclose(fp);
    return 0;
}