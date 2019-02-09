#include <stdio.h>

int main(void) {
	int month, day, maxDay, dayCount, i, remainder;
	scanf("%d %d", &month, &day);

	i = 1;
	dayCount = 0;
	while(1) {
		if(i == month) {
			dayCount += day;
			break;
		}
		if(i == 4 || i == 6 || i == 9 || i == 11)
			maxDay = 30;
		else if(i == 2)
			maxDay = 28;
		else //1, 3, 5, 7, 8, 10
			maxDay = 31;

		dayCount += maxDay;
		i++;
	}

	remainder = dayCount % 7;
	switch(remainder) {
		case 0:
			printf("SUN");
			break;
		case 1:
			printf("MON");
			break;
		case 2:
			printf("TUE");
			break;
		case 3:
			printf("WED");
			break;
		case 4:
			printf("THU");
			break;
		case 5:
			printf("FRI");
			break;
		case 6:
			printf("SAT");
			break;
	}

	return 0;
}