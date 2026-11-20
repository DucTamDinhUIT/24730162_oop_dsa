#include <stdio.h>

int main() {
    // const 2 pointer example
    
    const int a = 5;
    int b = 10;
    const int *p = &a;
    //*p = 6;  // This line will cause a compilation error
    p = &a;  // This is allowed
    printf("Value of b: %d\n", *p);
    p = &b;  // This is allowed
    printf("Value of a: %d\n", *p);

    // const pointer to int
    int c = 15;
    int * const p2 = &c;
    printf("Value of c: %d\n", *p2);
    *p2 = 20;  // This is allowed
    printf("New value of c: %d\n", c);
    return 0;
}
