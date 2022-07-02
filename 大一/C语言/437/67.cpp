#include <stdio.h>

int main() {
	int n, k, m;
	int sign = 1;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (k == m) {
			sign = 0;
			printf("%d ", i);
		}
	}
	if (sign)
		printf("-1");
	return 0;
}