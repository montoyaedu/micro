#include <stdint.h>
#include <stdio.h>

uint8_t and(uint8_t a, uint8_t b)
{
    return a & b;
}

int main(const int argc, const char** argv)
{
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            fprintf(stdout, "%x & %x = %x\n", a, b, and(a, b));
        }
    }
    return 0;
}
