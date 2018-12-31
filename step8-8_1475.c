#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int roomNum, remainder, setCount, i;
	int set[10] = {0, }; //initialize
	bool sixUsed = false;
	bool nineUsed = false;

	scanf("%d", &roomNum);

	while(1) {
		remainder = roomNum % 10;
		roomNum = roomNum / 10;
		//printf("roomNum: %d, remainder: %d\n", roomNum, remainder);

		if(remainder == 6) {
			if(sixUsed) {
				set[9]++;
				sixUsed = false;
			}
			else {
				set[remainder]++;
				sixUsed = true;
			}
		}
		else if(remainder == 9) {
			if(nineUsed) {
				set[6]++;
				nineUsed = false;
			}
			else {
				set[remainder]++;
				nineUsed = true;
			}
		}
		else {
			set[remainder]++;
		}
		
		if(!roomNum)
			break;
	}

	setCount = 0;
	for(i = 0; i < 10; i++) {
		//printf("%d ", set[i]);
		if(setCount < set[i])
			setCount = set[i];
	}
	//printf("\n");

	printf("%d", setCount);

	return 0;
}