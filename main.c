#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
    fprintf(stdout, "NOT GATE\n");
    fprintf(stdout, "A RESULT\n");
    for (int a = 0; a <= 1; a++) {
        fprintf(stdout, "%x = %x\n", a, not(a));
    }
    fprintf(stdout, "NAND GATE\n");
    fprintf(stdout, "A B RESULT\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            fprintf(stdout, "%x %x = %x\n", a, b, nand(a, b));
        }
    }
    fprintf(stdout, "HALF ADDER\n");
    fprintf(stdout, "A B RESULT CARRY-OUT\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            uint8_t cout;
            fprintf(stdout, "%x %x = %x       %x\n", a, b, half_add(a, b, &cout), cout);
        }
    }
    fprintf(stdout, "FULL ADDER\n");
    fprintf(stdout, "CARRY-IN A B RESULT CARRY-OUT\n");
    for (int cin = 0; cin <= 1; cin++) {
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                uint8_t cout;
                fprintf(stdout, "%x        %x %x = %x       %x\n", cin, a, b, full_add(a, b, cin, &cout), cout);
            }
        }
    }
    uint8_t cout;
    uint8_t* r = calloc(4, sizeof(uint8_t));
    /**
     * LSB first
     */
    uint8_t a[5] = { 0, 1, 1, 1 };
    uint8_t b[5] = { 1, 0, 0, 0 };
    n_bit_add(4, &r, a, b, 0, &cout);
    fprintf(stdout, "%s + %s = %s, carry = %x\n", printable(4, a), printable(4, b), printable(4, r), cout);
    a[0] = 1;
    n_bit_add(4, &r, a, b, 0, &cout);
    fprintf(stdout, "%s + %s = %s, carry = %x\n", printable(4, a), printable(4, b), printable(4, r), cout);
    return 0;
}
