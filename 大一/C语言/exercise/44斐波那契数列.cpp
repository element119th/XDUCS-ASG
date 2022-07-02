#include <stdio.h>

int fun(int num) {
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	return fun(num - 2) + fun(num - 1);
}

int main() {
	int n, m, x = 1;
	scanf("%d", &n);
	m = fun(n);
	for (int i = 2; i < m; i++) {
		if (m % i == 0) {
			printf("%d", m);
			x = 0;
			break;
		}
	}
	if (x == 1)
		printf("yes");
	return 0;
}