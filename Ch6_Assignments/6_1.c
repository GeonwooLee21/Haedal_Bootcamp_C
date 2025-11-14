// #10828 : 스택
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int stack[MAX_SIZE];
int top = -1;  // 스택은 비어있을 때 top == -1

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char cmd[10];
        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0) {
            int x;
            scanf("%d", &x);
            stack[++top] = x;
        }
        else if (strcmp(cmd, "pop") == 0) {
            if (top == -1)
                printf("-1\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", top + 1);
        }
        else if (strcmp(cmd, "empty") == 0) {
            if (top == -1) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(cmd, "top") == 0) {
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }
    }

    return 0;
}