#include <stdio.h>
#include "logic.h"

int main(const int argc, const char** argv)
{
    fprintf(stdout, "AND GATE\n");
    fprintf(stdout, "A B RESULT\n");
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            bit_t bit_a;
            bit_a.data = a;
            bit_t bit_b;
            bit_b.data = b;
            fprintf(stdout, "%x %x = %x\n", bit_a.bit, bit_b.bit, and(bit_a, bit_b).bit);
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
            uint8_t cout = 0;
            fprintf(stdout, "%x %x = %x       %x\n", a, b, half_add(a, b, &cout), cout);
        }
    }
    fprintf(stdout, "FULL ADDER\n");
    fprintf(stdout, "CARRY-IN A B RESULT CARRY-OUT\n");
    for (int cin = 0; cin <= 1; cin++) {
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                uint8_t cout = 0;
                fprintf(stdout, "%x        %x %x = %x       %x\n", cin, a, b, full_add(a, b, cin, &cout), cout);
            }
        }
    }
    uint8_t cout;
    uint8_t* r = (uint8_t*) calloc(4, sizeof(uint8_t));
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
