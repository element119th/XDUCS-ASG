#include <stdio.h>
#include <math.h>

int function(int a, int b) {
	int t, n = 0;
    int i;
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	if (b < 100)
		return n;
	else 
    {
        i=a<100?100:a;
		for (; i <= b; i++) {
			int  l = i, x = i, m = 0;
			long sum = 0;
			while (l) {
				l /= 10;
				m++;
			}
			while (x) {
				sum += pow(x % 10, m);
				x /= 10;
			}
			if (sum == i){
				n++;
            }
		}
		return n;
	}
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", function(a, b));
	return 0;
}