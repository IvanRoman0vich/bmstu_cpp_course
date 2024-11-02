#include "int2str.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>
char* int2str(int number) {
    // number равно 0
    if (number == 0) {
        char *result = malloc(2);
        if (result) {
            strcpy(result, "0");
        }
        return result;
    }
    // INT_MIN
    if (number == INT_MIN) {
        char *result = malloc(12);
        if (result) {
            strcpy(result, "-2147483648");
        }
        return result;
    }
    int minus = number < 0;
    if (minus) {
        number = -number; 
    }

    int num_len = minus ? 1 : 0; 
    int temp = number;
    do {
        num_len++;
        temp /= 10;
    } while (temp > 0);
    // Выделяем память под строку
    char* str = malloc(num_len + 1);
    if (!str) {
        return NULL; // Ошибка при выделении памяти
    }
    str[num_len] = '\0';
    for (int i = num_len - 1; i >= (minus ? 1 : 0); i--) {
        str[i] = (number % 10) + '0';
        number /= 10;
    }
    if (minus) {
        str[0] = '-';
    }
    return str;
}