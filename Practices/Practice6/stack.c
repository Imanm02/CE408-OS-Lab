#include <stdio.h>

void f(int count) {
    int i;
    printf("%d: address= %p\n", count, (void*)&i);
    if (count < 100) {
        f(count + 1);
    }
}

int main() {
    f(1);
    return 0;
}
