#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TESTS 15

int	myrand()
{
	int r = rand();
	int sign = rand() % 2 ? 1 : -1;
	return sign * r;
}

int isVaild(int i, int j, int k)
{
	return i + j > k && i + k > j && j + k > i;
}

char *	tritype(int i, int j, int k)
{
	if (i < 0 || j < 0 || k < 0)
	{
		return "INVALID";
	}

	if (i == j && j == k)
	{
		return "EQUIL";
	}

	if (isVaild(i, j, k))
	{
		if (i == j || j == k || i == k)
		{
			return  "ISO";
		}
		else
		{
			return "SCALENE";
		}
	}

	return "INVALID";
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i, j, k, t;
	for (t = 0; t < MAX_TESTS; ++t)
	{
		// do {
		i = myrand();
		j = myrand();
		k = myrand();
		// } while (!strcmp(tritype(i, j, k), "INVALID"));

		char cmd[1024];
		sprintf(cmd, "echo %d %d %d > t%d", i, j, k, t + 1);
		printf("%s\n", cmd);
		system(cmd);

		printf("\"Test %d: %s\", %d, %d, %d\t%s\n", t+1, tritype(i, j, k), i, j, k, tritype(i, j, k));
	}
}

/**
"Test 1: INVALID", -1122822091, -1226680922, -193961734 INVALID
"Test 2: INVALID", -1182307965, -154439951, -1240139973 INVALID
"Test 3: INVALID", 1402051776, 914798430, 1612220316    INVALID
"Test 4: INVALID", -496854896, -449175289, -1180638653  INVALID
"Test 5: INVALID", -1987922192, -1484115204, -266467487 INVALID
"Test 6: SCALENE", 883411989, 305256757, 945915839      SCALENE
"Test 7: INVALID", -653520881, -95223433, -599427703    INVALID
"Test 8: INVALID", 1167814945, 678101484, -1475198278   INVALID
"Test 9: INVALID", -737454116, 1299871708, 1347433141   INVALID
"Test 10: INVALID", 1443280107, 2141951683, -562629834  INVALID
"Test 11: INVALID", 688264798, 1650225101, 1408651086   INVALID
"Test 12: INVALID", -1492740046, 429397449, -722649152  INVALID
"Test 13: INVALID", 775843237, 882820983, 1825593824    INVALID
"Test 14: INVALID", 1596782873, 35105140, 1602193698    INVALID
"Test 15: INVALID", -1082197646, 422926318, -1677901821 INVALID

 */