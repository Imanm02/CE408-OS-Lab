#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   void *initial_heap_end = sbrk(0);
    printf("initial heap end address: %p\n", initial_heap_end);

    int count = 0;
    void *current_heap_end;

    while (1) {
        void *ptr = malloc(1024);
        count++;
	current_heap_end = sbrk(0);

        if (current_heap_end != initial_heap_end) {
            break;
        }
    }

    printf("#iterations: %d\n", count);
    return 0;
}
