#include "s21_string.h"
#include <stdlib.h>

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  int n = s21_strlen(str);
  byte *p = malloc(sizeof(*p) * (n + 1));
  if (!p) {
    p = S21_NULL;
  } else {
    for (int i = 0; i < (n + 1); i++) {
      if (*str >= 'A' && *str <= 'Z') {
        *p = *str + 32;
      } else {
        *p = *str;
      }
      p++;
      str++;
    }
    p = p - n - 1;
  }
  return (void *)p;
}
