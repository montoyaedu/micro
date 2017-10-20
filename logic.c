#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

char* printable(int n, uint8_t* array)
{
    char* r = calloc(n + 1, sizeof(char));
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        r[j] = array[i] + '0';
    }
    return r;
}

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

uint8_t not(uint8_t a)
{
    return ~(a & 0xff) & 0x1;
}

uint8_t nand(uint8_t a, uint8_t b)
{
    return not(and(a, b));
}

uint8_t half_add(uint8_t a, uint8_t b, uint8_t* cout)
{
    *cout = and(a, b);
    return xor(a, b);
}

uint8_t full_add(uint8_t a, uint8_t b, uint8_t cin, uint8_t* cout)
{
    uint8_t cout1, cout2;
    uint8_t sum1 = half_add(a, b, &cout1);
    uint8_t sum2 = half_add(cin, sum1, &cout2);
    *cout = or(cout1, cout2);
    return sum2;
}

void n_bit_add(uint8_t bits, uint8_t** result, uint8_t* a, uint8_t* b, uint8_t cin, uint8_t* cout)
{
    uint8_t carry_in = cin;
    for (int i = 0; i < bits; i++) {
        uint8_t r = full_add(*(a++), *(b++), carry_in, cout);
        (*result)[i] = r;
        carry_in = *cout;
    }
}
