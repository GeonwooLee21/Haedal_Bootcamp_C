#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100
#define FILENAME "todo_list.txt"

typedef struct {
    char task[MAX_LENGTH]; // 할 일 내용
    int  completed;        // 완료 여부 (0: 미완료, 1: 완료)
    char date[11];         // YYYY-MM-DD 형식의 날짜 (문자열 10자 + '\0')
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;   // ★ 0부터 시작

void loadTasks() {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) return;

    // ★ 0번 인덱스부터 채우기
    while (task_count < MAX_TASKS &&
           fscanf(file, "%d %10s %[^\n]",
                  &tasks[task_count].completed,
                  tasks[task_count].date,
                  tasks[task_count].task) == 3) {
        task_count++;
    }

    fclose(file);
}

void saveTasks() {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("파일 저장 오류!\n");
        return;
    }

    // ★ 0 ~ task_count-1 까지만 저장
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "%d %s %s\n",
                tasks[i].completed,
                tasks[i].date,
                tasks[i].task);
    }
    fclose(file);
}

void addTask() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (task_count >= MAX_TASKS) {
        printf("더 이상 할 일을 추가할 수 없습니다.\n");
        return;
    }

    getchar(); // 이전 입력의 개행 문자 제거
    printf("새로운 할 일: ");
    fgets(tasks[task_count].task, MAX_LENGTH, stdin);
    tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = '\0'; // 개행 제거

    printf("완료 날짜 (YYYY-MM-DD): ");
    scanf("%10s", tasks[task_count].date);
    tasks[task_count].completed = 0; // 기본 미완료

    task_count++;

    printf("할 일이 추가되었습니다! (%d-%d-%d %d:%d:%d에 추가됨)\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void displayTasks() {
    if (task_count == 0) {
        printf("할 일이 없습니다!\n");
        return;
    }

    printf("\nTODO list:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. [%s] %s (완료 기한: %s)\n",
               i + 1,                               // ★ 사람에게 보일 번호
               tasks[i].completed ? "X" : " ",
               tasks[i].task,
               tasks[i].date);
    }
}

void deleteTask() {
    int num;

    displayTasks();
    if (task_count == 0) return;

    printf("삭제할 할 일 번호: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {  // ★ 1 ~ task_count 까지 유효
        printf("잘못된 번호입니다.\n");
        return;
    }

    int index = num - 1; // ★ 실제 배열 인덱스
    for (int i = index; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;

    printf("할 일이 삭제되었습니다!\n");
}

void completeTask() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int num;

    displayTasks();
    if (task_count == 0) return;

    printf("완료할 할 일 번호: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    int index = num - 1; // ★ 실제 배열 인덱스
    tasks[index].completed = 1;

    printf("할 일이 완료되었습니다! (%d-%d-%d %d:%d:%d에 완료됨)\n",
           tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main() {
    int choice;

    loadTasks(); // 시작 시 파일에서 불러오기

    while (1) {
        printf("\n===== TODO list =====\n");
        printf("1. 할 일 추가\n");
        printf("2. 할 일 삭제\n");
        printf("3. 목록 보기\n");
        printf("4. 완료 체크\n");
        printf("5. 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                completeTask();
                break;
            case 5:
                saveTasks(); // 종료 시 저장
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}