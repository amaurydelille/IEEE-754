#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* S(int number) {
    char* sign = (char*)malloc(sizeof(char) * 1);
    sign = (number > 0) ? "0" : "1";
    return sign;
}

char* toBinary(int number) {
    char* result = (char*)malloc(sizeof(char) * 20);
    int i = 0;

    while (number > 0) {
        result[i] = (number % 2) + '0'; //Convert our integer 'number' to a binary number, once the loop is done, the number will be backward;
        number /= 2;
        i++;
    }

    result[i] = '\0';
    int length = strlen(result);
    int j = 0;

    for (int j = 0; j < length - 2; j++) {
        char temp = result[j];
        result[j] = result[length - j - 1];  //We reverse our array so that is in order.
        result[length - j - 1] = temp;
    }

    char* binary = (char*)malloc((length + 1) * sizeof(char));
    strcpy(binary, result);
    return result;
}

char* M(int number) { //We're calculating the M field of the final representation.
    char* bin = toBinary(number);
    char* M =(char*)malloc(sizeof(char)*24);
    int length = strlen(bin), i = 1, j = length;

    while (i < length) {
        M[i-1] = bin[i];
        i++;
    }

    M[i-1] = 0 + '0';

    while (j < 23) {
        M[j] = 0 + '0';
        j++;
    }

    M[j] = '\0';
    return M;
}

char* E(int number) { //Now this is the last step : calculating E field.
    char* E = (char*)malloc(sizeof(char)*8);
    char* bin = toBinary(number);
    int length = strlen(bin), e = length - 1;
    int biais = 127;

    //We know that E = e + biais.
    int _E = e + biais;
    E = toBinary(_E);

    return E;
}

char* IEEE(int number) {
    char* s = S(number);
    char* e = E(number);
    char* m = M(number);

    char* result = (char*)malloc(sizeof(char) * 36); // 1 for sign, 8 for exponent, 23 for mantissa, 4 for spaces and 1 for null terminator

    sprintf(result, "%s %s %s", s, e, m);

    printf("IEEE-754 representation of %d:\n%s\n", number, result);

    free(s);
    free(e);
    free(m);
    free(result);
}