#include <stdint.h>
#include <inttypes.h>

void fib()
{
    /*
     0 1 1 2 3 5 8 13 21 34
    */
    // Varje g�ng vi anropar fib() s� ska den skriva ut n�sta tal i fibonacci-serien.
    static uint32_t a = 0;
    static uint32_t b = 1;

    uint32_t next = a + b;
    printf("%" PRIu32 " ", next);

    a = b;
    b = next;
}
