#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TESTS 15

/** Returns 1 or -1 picked at random */
int rand_sign()
{
  // return 1 if odd, -1 if even
  return rand() % 2 ? 1 : -1;
}

/** Returns a random number between -RAND_MAX and RAND_MAX */
int random_int()
{
  int r = rand();
  int sign = rand_sign();
  return sign * r;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int i, j, k, t;
  for (t = 0; t < MAX_TESTS; ++t)
  {
    i = random_int();
    j = random_int();
    k = random_int();
    printf("\"Test %2d:\" %13d %13d %13d\n", t+1, i, j, k);
  }
}