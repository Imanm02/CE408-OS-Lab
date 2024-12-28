#include <stdio.h>
#include <stdlib.h>

struct MyStruct {
    int a;
    int b;
    char name[20];
};


int main() {

struct MyStruct *str = (MyStruct *)malloc(sizeof(struct MyStruct));

str->a = 1;
str->b = 2;
sprintf(str->name, "negarr");
printf("a: %d, b: %d, name: %s\n", str->a, str->b, str->name);


free(str);
return 0;
}
