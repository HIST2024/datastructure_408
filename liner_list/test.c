#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int i;
  printf("Total %d arguments\n", argc);

  for (i = 0; i < argc; i++) {
    printf("\nArgument argv[%d]  = %s \n", i, argv[i]);
  }


  return 0;
}
