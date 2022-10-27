#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t size = 0;
    if (str != S21_NULL) {
        while ((*(char*)(str+size) != '\0')) {
            size++;
        }
    }
    return size;
}
