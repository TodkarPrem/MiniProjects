/*
 * Compare number of ?'s in a string. If ? cout inbetween nums == num1+num2,
 * string is valid, otherwise invalid.
 *
 * valid string   - 1??1
 *          o/p   - 1+1 = 2, ? count = 2
 * Invalid string - 3??1
 *            o/p - 3+1 = 4, ? count = 2
 */


#include <stdio.h>

#define NO_OF_STRINGS	10
#define STRING_SIZE	50

int main()
{
	char string[NO_OF_STRINGS][STRING_SIZE];
	int input_strings, i, j, k, numeric_sum, number_of_symbol, string_length;

	printf("Enter how many input strings user wants to enter : ");
	scanf("%d", &input_strings);

	printf("Enter strings. Enter will be treated as new string :\n");

	for (i = 0; i < input_strings; i++)
		scanf("%s", string[i]);

	printf("Input strings are :\n");
	for (i = 0; i < input_strings; i++)
		printf("%s\n", string[i]);

	printf("Output for validity :\n");
	for (i = 0; i < input_strings; i++) {
		for (j = 0; string[i][j]; j++) {
			numeric_sum = 0;
			if (string[i][j] == '?') {
				/* Converting ascii into integer value */
				numeric_sum = string[i][j - 1] - 48;
				for (j++, number_of_symbol = 1;  string[i][j]; j++) {
					if (string[i][j] != '?')
						break;
					number_of_symbol++;
				}
				/* Converting ascii into integer value */
				numeric_sum += string[i][j] - 48;
				
				if (numeric_sum != number_of_symbol)
					break;
			}
		}
		if (numeric_sum == number_of_symbol)
			printf("String%d. Valid\n ", i + 1);
		else
			printf("String%d. Invalid\n", i + 1);
	}
	return 0;
}
