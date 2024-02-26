#include <stdio.h>
#include<stdlib.h>

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > i) break;
			printf("%2d ", i * 10 + j);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}