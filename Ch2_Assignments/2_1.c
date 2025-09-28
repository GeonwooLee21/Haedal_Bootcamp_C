#include <stdio.h>

int main() {
    int leap_year = 0;
    scanf("%d",  &leap_year);

    if ((leap_year % 4 == 0 && leap_year % 100 != 0) || (leap_year % 400 == 0)) {
        printf("1\n");
    }
    else {
        printf("0\n");
    }

    return 0;
}