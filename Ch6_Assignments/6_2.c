// #10845 : 큐
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int queue[MAX_SIZE];
int front = 0;   // 큐의 앞 인덱스
int back = 0;    // 큐의 뒤 인덱스 (다음 데이터가 들어갈 위치)

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char cmd[10];
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            queue[back++] = x;   // 뒤에 추가
        }
        else if (strcmp(cmd, "pop") == 0) {
            if (front == back) {
                printf("-1\n");
            } else {
                printf("%d\n", queue[front++]);
            }
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", back - front);
        }
        else if (strcmp(cmd, "empty") == 0) {
            if (front == back) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(cmd, "front") == 0) {
            if (front == back) printf("-1\n");
            else printf("%d\n", queue[front]);
        }
        else if (strcmp(cmd, "back") == 0) {
            if (front == back) printf("-1\n");
            else printf("%d\n", queue[back - 1]);
        }
    }

    return 0;
}