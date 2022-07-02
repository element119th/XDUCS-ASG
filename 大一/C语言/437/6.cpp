#include <stdio.h>

int sum(int n) {
	int total = 0;
	if (n <= 9) {
		return n;
	}
	while (n) {
		total += n % 10;
		n /= 10;
	}
	return total;
}

int main() {
	int n, x, y;
	int a[1000];
	int b[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = sum(a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (b[j] < b[j + 1]) {
				x = b[j];
				b[j] = b[j + 1];
				b[j + 1] = x;
				y = a[j];
				a[j] = a[j + 1];
				a[j + 1] = y;
			}
			if (b[j] == b[j + 1] && a[j] > a[j + 1]) {
				y = a[j];
				a[j] = a[j + 1];
				a[j + 1] = y;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		printf("%d %d\n", a[i], b[i]);
	}
	printf("%d %d", a[n - 1], b[n - 1]);
	return 0;
}