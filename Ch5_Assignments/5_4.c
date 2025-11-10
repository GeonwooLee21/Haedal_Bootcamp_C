#include <stdio.h>

int main() {
    char name[10];
    int age;

    // 파일 스트림 생성
    FILE *fp = fopen("student.txt", "wt");

    // 학생의 이름과 나이를 user로부터 입력받아, student.txt 파일에 출력
    for (int i = 0; i < 3; i++) {
        printf("다음 순서로 입력(name age) : ");
        scanf("%s %d", name, &age); // user의 키보드 입력
        getchar(); // 버퍼에 남은 개행문자 처리
        fprintf(fp, "%s %d\n", name, age); // student.txt에 name, age 출력
    }

    // 파일 스트림 종료
    fclose(fp);
    return 0;
}