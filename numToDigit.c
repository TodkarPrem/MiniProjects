#include <stdio.h>

char str1[][10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char str2[][15] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char str3[][10] = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};

int main()
{
	int num;

	printf("Enter any number(-99l to 99l): ");
	scanf("%d", &num);

	if (num < 0) {
		printf("(-ve) ");
		num = -num;
	}
	if (num > 9999999) {
		printf("Number out of range\n");
		return -1;
	}

	if (num >= 100000) {
		if (num >= 2000000) {
			printf("%s ", str3[num/1000000 - 2]);
			num = num % 1000000;
		}
		if (num > 1000000) {
			printf("%s ", str2[num/100000 - 10]);
			num = num % 100000;
		}
		if (num >= 100000)
			printf("%s ", str1[num/100000]);
		num = num % 100000;
		printf("Lakhs ");
	}
	if (num > 999) {
		if (num >= 20000) {
			printf("%s ", str3[num/10000 - 2]);
			num = num % 10000;
		}
		if (num >= 10000) {
			printf("%s ", str2[num/1000 - 10]);
			num = num % 1000;
		}
		if (num >= 1000)
			printf("%s ", str1[num/1000]);
		num = num % 1000;
		printf("Thousand ");
	}
	if (num >= 100) {
		printf("%s Hundred ", str1[num/100]);
		num = num % 100;
		if (num)
			printf("And ");
	}
	if (num >= 20) {
		printf("%s ", str3[num/10 - 2]);
		num = num % 10;
	}
	if (num >= 10) {
		printf("%s", str2[num%10]);
	}
	else if (num > 0)
		printf("%s", str1[num]);

	printf("\n");
	return 0;
}
