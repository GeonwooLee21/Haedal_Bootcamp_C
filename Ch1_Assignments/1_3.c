#include <stdio.h>

int main() {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    printf("( %d + %d ) %% %d = %d\n", A, B, C, (A+B)%C);
    printf("(( %d %% %d ) + ( %d %% %d )) %% %d = %d\n", A, C, B, C, C, ((A%C)+(B%C))%C);

    printf("\n");

    printf("( %d * %d ) %% %d = %d\n", A, B, C, (A+B)%C);
    printf("(( %d %% %d ) * ( %d %% %d )) %% %d = %d\n", A, C, B, C, C, ((A%C)*(B%C))%C);

    return 0;
}