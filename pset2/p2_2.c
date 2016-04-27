#include <stdio.h>

#define MASK 0x7

int main() {
  int val = 0xCAFE;


  if ((val & MASK) == MASK) {
    puts("Least 3 bits are one");
  }

  int new_val = (val >> 2 * 4) | ((val & 0xFF) << 2 * 4);

  printf("0x%x\n", new_val);

  int rotated = ((val >> 4) & 0x0FFF) | ((val & 0x000F) << 3 * 4);

  printf("0x%x\n", rotated);

  printf("%d\n", 2 && 1);


  int x, y;

  printf("%d\n", (x = 1));
  printf("%d\n", (y = 0));
  printf("%d\n", 1 && 0);


  return 0;
}
