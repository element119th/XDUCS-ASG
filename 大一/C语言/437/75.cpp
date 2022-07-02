#include <stdio.h>

int main() {
	int m, n, x;
	int index[16] = {0};
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m * n; i++) {
		scanf("%d", &x);
		index[x]++;
	}
	for (int i = 0; i < 15; i++) {
		if (index[i]) {
			printf("%d %d\n", i, index[i]);
		}
	}
	if (index[15]) {
		printf("15 %d", index[15]);
	}
	return 0;
}