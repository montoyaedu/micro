#include <stdint.h>
#include <stdio.h>

uint8_t and(uint8_t a, uint8_t b)
{
    return a & b;
}

uint8_t or(uint8_t a, uint8_t b)
{
    return a | b;
}

uint8_t xor(uint8_t a, uint8_t b)
{
    return a ^ b;
}

int main(const int argc, const char** argv)
{
    fprintf(stdout, "AND GATE\n");
    fprintf(stdout, "A B RESULT\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            fprintf(stdout, "%x %x = %x\n", a, b, and(a, b));
        }
    }
    fprintf(stdout, "OR GATE\n");
    fprintf(stdout, "A B RESULT\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            fprintf(stdout, "%x %x = %x\n", a, b, or(a, b));
        }
    }
    fprintf(stdout, "XOR GATE\n");
    fprintf(stdout, "A B RESULT\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            fprintf(stdout, "%x %x = %x\n", a, b, xor(a, b));
        }
    }
    return 0;
}
