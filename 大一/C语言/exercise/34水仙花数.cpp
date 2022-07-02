#include <stdio.h>
#include <math.h>

int main() {
	int num1, num2;
	scanf("%d%d", &num1, &num2);
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
		printf("%d",n);
		return 0;
	}
}
