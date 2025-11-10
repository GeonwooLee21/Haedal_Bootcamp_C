#include <stdio.h>

int main() {
    char str[20];
    
    // 파일 스트림 생성
    FILE *org = fopen("input.txt", "rt"); // 복사 대상 파일
    FILE *copy = fopen("output.txt", "wt"); // 복사 결과를 저장할 파일

    // 두 파일에 대한 파일 스트림이 모두 생성되었는지 체크
    if (org == NULL || copy == NULL) {
        printf("Failed to open file"); // 실패 시 파일 읽기 실패 오류 메세지 출력
        return -1;
    }

    // input.txt의 파일 내용을 읽고, 해당 내용을 output.txt에 출력
    while (fgets(str, sizeof(str), org) != NULL) {
        fputs(str, copy);
    }

    // 파일 복사가 완료되었는지 확인
    if (feof(org) != 0)
        printf("File opied successfully"); // input.txt를 끝까지 잘 읽었을 때
    else
        printf("Fail to copy file"); // input.txt 끝까지 잘 읽지 못했을 때

    // 파일 스트림 종료
    fclose(org);
    fclose(copy);
    return 0;
}