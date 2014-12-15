// Defines
#define TRUE 1
#define FALSE 0

// Enums
enum months {
  JAN,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
};

// Headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "learnc.h"

// Main
int main() {

  // Define fxn declared in header
  say_hello();

  // Int and Char can be used interchangabily 
  printf("%d\n", 'A');
  printf("%c\n", 65);

  // Initialize an int array to 0
  int int_array[10] = {0};

  // Print its element just to be sure
  for (int i=0; i<10; i++) {
    printf("%d ", int_array[i]);
  }
  printf("\n");

  // Use sizeof to determine size of array in memory
  printf("size of int array: %zu\n", sizeof(int_array));
  
  // Read a specified no. of bytes from stdin
  char buf[10];
  fgets(buf, sizeof(buf), stdin);
  printf("%s\n", buf);

  // Multi dimensional arrays
  int matrix[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Bitwise operators
  printf("%x\n", ~0xFF);
  printf("%x\n", 0x11 & 0x10);
  printf("%x\n", 0x11 | 0x00);
  printf("%x\n", 0x11 ^ 0x10);
  printf("%x\n", 0x01 << 1);
  printf("%x\n", 0x02 >> 1);

  return 0;
}

void say_hello() {
  printf("Hello\n");
}
