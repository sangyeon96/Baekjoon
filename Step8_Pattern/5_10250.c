#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int maxFloor;
	int maxRoom;
	int orderNum;
} information;

int calculateRoomNum(information * info) {
	int floor, roomNum, result;

	floor = info->orderNum % info->maxFloor;
	roomNum = info->orderNum / info->maxFloor + 1;
	if(!floor) { //floor == 0
		floor = info->maxFloor;
		roomNum -= 1;
	}
	
	result = floor * 100 + roomNum;
	return result;
}

int main(void) {
	int caseCount, i;
	scanf("%d", &caseCount);

	information * info = (information *)malloc(sizeof(information)*caseCount);

	for(i = 0; i < caseCount; i++)
		scanf("%d %d %d", &info[i].maxFloor, &info[i].maxRoom, &info[i].orderNum);

	for(i = 0; i < caseCount; i++)
		printf("%d\n", calculateRoomNum(&info[i]));

	return 0;
}