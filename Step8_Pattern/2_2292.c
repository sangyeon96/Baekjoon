#include <stdio.h>

int main(void) {
	int n, start, end;
	scanf("%d", &n);
	
	int count = 0;
	while(1) {
		if(count == 0) {
			start = 1;
			end = 1;
		}
		else {
			start = end + 1;
			end = start + 6 * count - 1;
		}

		if(start <= n && n <= end)
			break;
		else
			count++;
	}

	printf("%d", count + 1);

	return 0;
}