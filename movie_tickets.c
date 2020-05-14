#include <stdio.h>

int main()
{
	int movie_input, shows_input, NumOfPeople, i;
	int price_list[4] = {150, 200, 250, 150};
	char movie_list[][15] = {"Sholay", "Titli", "Manjhi", "Vodka Diaries"};
	char shows_list[][15] = {"11AM - 2PM", "3PM - 6PM", "7PM - 10PM", "11AM - 2PM"};

	printf("Ongoing movie list :\n");
	for (i = 0; i < 4;i++)
		printf("\t%d. %s\n", i + 1, movie_list[i]);

	printf("Enter which movie(number) you want to see :");
	scanf("%d", &movie_input);

	printf("Movie Selected: %s\n", movie_list[movie_input - 1]);

	printf("Shows available with fare:\n");
	for (i = 0; i < 4;i++)
                printf("\t%d. %s\t %d\n", i + 1, shows_list[i], price_list[i]);

        printf("Enter which show(number) you want to see :");
        scanf("%d", &shows_input);

        printf("Show Selected: %s\n", shows_list[shows_input - 1]);

	printf("How many tickets you want to book: ");
	scanf("%d", &NumOfPeople);

	printf("Total %s movie tickets fare showing on %s for %d peaople is %d\n",movie_list[movie_input - 1], shows_list[shows_input - 1], NumOfPeople, price_list[shows_input - 1] * NumOfPeople);
	return 0;
}
