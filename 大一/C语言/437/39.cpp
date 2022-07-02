#include <stdio.h>

int main() {
	int m, n;
	int sign = 0;
	int a[100][100], b[100];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		int min = 1000000;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (min > a[i][j]) {
				min = a[i][j];
				b[i] = j;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int max = a[i][b[i]];
		int sign2 = 1;
		for (int j = 0; j < m; j++) {
			if (a[i][b[i]] < a[j][b[i]]) {
				sign2 = 0;
				break;
			}
		}
		if (sign2) {
			sign++;
			printf("%d %d %d\n", i, b[i], a[i][b[i]]);
		}		
	}
	if (sign == 0)
		printf("no\n");
	return 0;
}
