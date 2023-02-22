#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IEEEtoDecimal.c"
#include "DecimalToIEEE.c"

/* Before checking the code, you should read the documentation of IEEE-754 standard
   and the functioning of my code, in my repository ;)*/

int main() {
    int num = 25; //Example with 25.
    printf(IEEE(25));
    return 0;
}
