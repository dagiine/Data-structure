#include "linked_list.h"
#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

/* аравтын тооллын системээс хоёртын тооллын системд хөрвүүлэх
 * dec параметраар аравтын тооллын системийн тоон утга авна
 * хоёртын тооллын системд хөрвүүлсэн утгаа тэмдэгт мөр хэлбэрээр буцаана */
char *dec2bin(int dec) {
  if (dec == 0) {
      char *zero = (char *)malloc(2 * sizeof(char));
      zero[0] = '0';
      zero[1] = '\0';
      return zero;
  }

  char a[32]; 
  int i = 0;

  while (dec > 0) {
      a[i++] = (dec % 2) + '0'; // 0 (ASCII) = 48
      dec /= 2;
  }

  char *binary = (char *)malloc((i + 1) * sizeof(char)); //sanah oid urvuugaar n hadgalsnaar zuv bolno
  if (binary == NULL) {
    printf("Sanakh oi oldsongui!\n");
    exit(1);
  }
  for (int j = 0; j < i; j++) {
      binary[j] = a[i - j - 1];
  }
  binary[i] = '\0';

  return binary;
}

int main() {
  // оролт: 8 -> гаралт: 1000
  int dec;
  scanf("%d", &dec);
  char *bin = dec2bin(dec);
  printf("%s\n", bin);
  free(bin);
  return 0;
}