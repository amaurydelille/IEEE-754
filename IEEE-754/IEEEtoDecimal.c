#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DecimalToIEEE.c"

//We will return our final number in the form of k*2^e, where k belongs to the relatives number.

typedef enum { false, true } bool; //Boolean type does not exist in C, so we're using an enumeration to define it.

bool isNan = false, isInfinity = false, isZero = false;

char S2(char* number) { //Here we write 'number' as a parameter but don't forget that this 'number' is written in IEEE-754.
    char sign = number[0] == 1 ? '-' : '\0';
    return sign;
}

