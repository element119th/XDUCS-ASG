#include <stdio.h>
#include <math.h>

int fun(int num1, int num2) {
	int t, n = 0;
	if (num1 > num2) {
		t = num1;
		num1 = num2;
		num2 = t;
	}
	if (num2 < 100)
		return n;
	else {
		for (int i = 100; i <= num2; i++) {
			int  l = i, x = i, m = 0, sum = 0;
			while (l) {
				l /= 10;
				m++;
			}
			while (x) {
				sum += pow(x % 10, m);
				x /= 10;
			}
			if (sum == i)
				n++;
		}
		return n;
	}
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", fun(a, b));
	return 0;
}