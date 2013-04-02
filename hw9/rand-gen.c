#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_TESTS 15

char* SCALENE	= "SCALENE";
char* ISO		= "ISO";
char* EQUIL		= "EQUIL";
char* INVALID	= "INVALID";

int	myrand()
{
	int r = rand();
	int sign = rand() % 2 ? 1 : -1;
	return sign * r;
}

int isValid(int i, int j, int k)
{
	if (i < 0 || j < 0 || k < 0)
		return 0;

	// use subtraction to avoid overlow
	return i > k - j && i > j - k && j > i - k;
}

char* tritype(int i, int j, int k)
{
	if (!isValid(i,j,k))
		return INVALID;
	else if (i == j && j == k)
		return EQUIL;
	else if (i == j || j == k || i == k)
		return  ISO;
	else
		return SCALENE;
}

int main(int argc, char const *argv[])
{
	// these were generated randomly, then saved here for reproducibility
	int arr[15][3] = {
		{-1122822091,  -1226680922,   -193961734},
		{-1182307965,   -154439951,  -1240139973},
		{ 1402051776,    914798430,   1612220316},
		{ -496854896,   -449175289,  -1180638653},
		{-1987922192,  -1484115204,   -266467487},
		{  883411989,    305256757,    945915839},
		{ -653520881,    -95223433,   -599427703},
		{ 1167814945,    678101484,  -1475198278},
		{ -737454116,   1299871708,   1347433141},
		{ 1443280107,   2141951683,   -562629834},
		{  688264798,   1650225101,   1408651086},
		{-1492740046,    429397449,   -722649152},
		{  775843237,    882820983,   1825593824},
		{ 1596782873,     35105140,   1602193698},
		{-1082197646,    422926318,  -1677901821}
	};

	srand(time(NULL));
	int i, j, k, t;
	for (t = 0; t < MAX_TESTS; ++t)
	{
		i = arr[t][0];
		j = arr[t][1];
		k = arr[t][2];

		// i = myrand();
		// j = myrand();
		// k = myrand();

		char cmd[1024];
		sprintf(cmd, "echo %d %d %d > t%d", i, j, k, t + 1);
		// printf("%s\n", cmd);
		system(cmd);

		printf("\"Test %2d: RANDOM\", %12d, %12d, %12d %8s\n", t+1, i, j, k, tritype(i, j, k));
	}
	return 0;
}

/**
	"Test  1: RANDOM",  -1122822091,  -1226680922,   -193961734  INVALID
	"Test  2: RANDOM",  -1182307965,   -154439951,  -1240139973  INVALID
	"Test  3: RANDOM",   1402051776,    914798430,   1612220316  SCALENE
	"Test  4: RANDOM",   -496854896,   -449175289,  -1180638653  INVALID
	"Test  5: RANDOM",  -1987922192,  -1484115204,   -266467487  INVALID
	"Test  6: RANDOM",    883411989,    305256757,    945915839  SCALENE
	"Test  7: RANDOM",   -653520881,    -95223433,   -599427703  INVALID
	"Test  8: RANDOM",   1167814945,    678101484,  -1475198278  INVALID
	"Test  9: RANDOM",   -737454116,   1299871708,   1347433141  INVALID
	"Test 10: RANDOM",   1443280107,   2141951683,   -562629834  INVALID
	"Test 11: RANDOM",    688264798,   1650225101,   1408651086  SCALENE
	"Test 12: RANDOM",  -1492740046,    429397449,   -722649152  INVALID
	"Test 13: RANDOM",    775843237,    882820983,   1825593824  INVALID
	"Test 14: RANDOM",   1596782873,     35105140,   1602193698  SCALENE
	"Test 15: RANDOM",  -1082197646,    422926318,  -1677901821  INVALID
 */