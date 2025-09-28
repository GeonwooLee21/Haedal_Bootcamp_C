#include <stdio.h>

void fib_5(int n, int i, int* fib) {
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-2] + fib[i-1];
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int fib[20] = {0}; fib[1] = 1;
    fib_5(n, 0, fib);
    
    printf("%d\n", fib[n]);

    return 0;
}