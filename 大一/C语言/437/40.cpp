#include <stdio.h>

int main() {
	int n, t, d;
	int sign = 1;
	int a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	d = a[1] - a[0];
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] != d) {
			printf("no");
			sign = 0;
			break;
		}
	}
	if (sign)
		printf("%d", d);
	return 0;
}