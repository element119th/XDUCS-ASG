#include <stdio.h>

int main() {
	int m, x;
	int a[20][20];
	int b[50] = {0};
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		b[2 * m] += a[i][i];
		b[2 * m + 1] += a[m - i - 1][i];
		for (int j = 0; j < m; j++) {
			b[i] += a[i][j];
			b[m + i] += a[j][i];
		}
	}
	for (int i = 0; i < 2 * m + 2; i++) {
		for (int j = 0; j < 2 * m + 1 - i; j++) {
			if (b[j] < b[j + 1]) {
				x = b[j];
				b[j] = b[j + 1];
				b[j + 1] = x;
			}
		}
	}
	for (int i = 0; i < 2 * m + 2; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}