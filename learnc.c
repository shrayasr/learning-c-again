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
  //char buf[10];
  //fgets(buf, sizeof(buf), stdin);
  //printf("%s\n", buf);

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

  // Pointers *drum roll*
  int x = 0;
  char y = 'a';
  /*
   * This will generate a warning since int is being cast down to 
   * a void pointer. The void pointer can point to a larger portion
   * of memory than can be represented by the int, i think?
   */
  printf("%p\n", (void *)x);
  //printf("%p\n", (void *)y);
  
  int *p, not_a_ptr;
  p = &x;
  /*
   * A void pointer can be used to store an address of any
   * type. A void pointer is a type. 
   */
  printf("%p\n", (void *)p);
  printf("%p\n", p);
  // ^ TODO Find out why casting to or not casting to void* gives
  // the same output above
  
  // Prints "8 4". Why does a pointer to an integer 
  // take 4 more bytes?
  //
  // ANSWER: The size of an integer depends on the underlying
  // architecture. On a 64 bit (non windows) machine, it will show 8.
  printf("%zu %zu\n", sizeof(p), sizeof(x));

  // Dereference
  printf("%d\n", *p);

  // Value at that location can be incremented
  (*p)++;
  printf("%d\n", *p);

  int int_array2[20];
  for (int i=0; i<20; i++) {
    int_array2[i] = 20 - i;
  }

  int *p_int_array;
  /*
   * Pointer to array assignment doesn't need to be 
   * prefixed by the "&" operator because arrays are
   * stored by the address of the first value. This is
   * because arrays are stored in contiguous set of memory
   * locations
   */
  p_int_array = int_array2;

  printf("%d\n", *(p_int_array));
  printf("%d\n", *(p_int_array + 1));

  void *p_to_all;
  int val1;
  char val2;
  float val3;
  p_to_all = &val1;
  printf("%lu\n", sizeof(p_to_all));
  p_to_all = &val2;
  printf("%lu\n", sizeof(p_to_all));
  p_to_all = &val3;
  printf("%lu\n", sizeof(p_to_all));

  int *p_to_int, xx;
  p_to_int = &xx;
  /*
   * If lu isn't, a warning is shown for trying to print the size
   * More info: http://stackoverflow.com/a/22752349
   */
  printf("%lu\n", sizeof(p_to_int));

  // Malloc stuff
  /*
   * Allocate a certain amount of memory and return back
   * a pointer pointing to that allocated block
   */
  int *ptr_array = malloc(sizeof(*ptr_array) * 10);
  for (int i=0; i<10; i++) {
    *(ptr_array + i) = 20 - i;
  }

  printf("%d\n", *(ptr_array+7));

  // Free dem memory!
  free(ptr_array);

  /*
   * Shouldn't this result in some garbage value? Or doesn't
   * it because that memory hasn't been claimed yet? Maybe it is
   * just 'marked' to be collected and not collected itself.
   */
  printf("%d\n", *(ptr_array+7));

  // Strings are just a sequence of characters. 
  // More specifically they are usually represented by
  // a pointer to the first element of a character array
  const char *my_str = "Hello world";
  printf("%c\n", *my_str);

  /*
   * using printf("%s\n", *my_str) gives me a seg fault. Maybe
   * it is because it isn't NULL terminated? unsure
   */

  return 0;
}

void say_hello() {
  printf("Hello\n");
}
