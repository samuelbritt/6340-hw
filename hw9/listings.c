#include <stdio.h>
main()
{
    int i, j, k, triang;
    scanf("%d %d %d", &i, &j, &k);

    if (i <= 0) {
        triang = 4;
    } else if (j <= 0) {
        triang = 4;
    } else if (k < 0) {
        triang = 4;
    } else {
        triang = 0;
        if (i == j)
            triang += 1; (*\label{foo}*)
        if (i == k) 
            triang += 2;
        if (j == k) 
            triang += 3;

        if (triang == 0) {
            /* Confirm it's a legal triangle before declaring it to be scalene */
            if ( i+j <= k ) 
                triang = 4;
            else if (j+k <= i)
                triang = 4;
            else if (i+k < j)
                triang = 4;
            else 
                triang = 1;
        } else {
            /* Confirm it's a legal triangle before declaring it to be isosceles or equilateral */
            if (triang > 3) {
                triang = 3;
            } else if (triang == 1) {
                if (i+j > k) 
                    triang  = 2;
            } else if (triang == 2) {
                if (i+k > j)
                    triang = 2;
            } else if (triang == 3) {
                if (j+k > i)
                    triang = 2;
            } else {
                triang = 4;
            }
        }
    } 
    printf("triang = %d\n", triang);
}

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
    for (t = 0; t < MAX_TESTS; ++t) {
        i = random_int();
        j = random_int();
        k = random_int();
        printf("\"Test %2d:\" %13d %13d %13d\n", t+1, i, j, k);
    }
}