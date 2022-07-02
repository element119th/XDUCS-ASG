#include <stdio.h>

int main() {
	int n, m = 0;
	scanf("%d", &n);
	int a[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n-1 ; ++i) {
		if ((a[i] > a[i-1] && a[i] > a[i+1] )||( a[i] < a[i-1] && a[i] < a[i + 1]))
			m++;
	}
	printf("%d", m );
	return 0;
}