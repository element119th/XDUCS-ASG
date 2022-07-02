#include <stdio.h>

int main() {
	int n, sum = 0, mid, total = 0;
	int a[10];
	int sign = 1;
	scanf("%d", &n);
	if (n < 10) {
		printf("%d", n);
		return 0;
	}
	while (n) {
		a[sum] = n % 10;
		n /= 10;
		sum++;
	}
	mid = sum / 2;
	for (int i = 0; i <= mid; i++) {
		if (a[i] != a[sum - 1 - i]) {
			sign = 0;
		}
	}
	if (sign) {
		for (int i = 0; i < sum; i++) {
			total += a[i];
		}
		printf("%d", total);
	} else
		printf("no");
	return 0;
}