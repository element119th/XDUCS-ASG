#include <stdio.h>

float An(int num) {
	if (num == 1)
		return 2;
	if (num == 2)
		return 3;
	return An(num - 1) + An(num - 2);
}

float Bn(int num) {
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;
	return Bn(num - 1) + Bn(num - 2);
}

int main() {
	int n;
	float sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n ; i++) {
		sum += An(i) / Bn(i);
	}
	printf("%.2f", sum);
	return 0;
}