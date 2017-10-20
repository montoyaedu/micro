#ifndef __MICRO_LOGIC_H__
#define __MICRO_LOGIC_H__
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char* printable(int n, uint8_t* array);
uint8_t and(uint8_t a, uint8_t b);
uint8_t or(uint8_t a, uint8_t b);
uint8_t xor(uint8_t a, uint8_t b);
uint8_t not(uint8_t a);
uint8_t nand(uint8_t a, uint8_t b);
uint8_t half_add(uint8_t a, uint8_t b, uint8_t* cout);
uint8_t full_add(uint8_t a, uint8_t b, uint8_t cin, uint8_t* cout);
void n_bit_add(uint8_t bits, uint8_t** result, uint8_t* a, uint8_t* b, uint8_t cin, uint8_t* cout);

#endif
