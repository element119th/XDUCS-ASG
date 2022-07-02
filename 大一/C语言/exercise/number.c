#include<stdio.h>
int main() {
	int t, a[1000]={0}, n, i, x2, x1, b[1000]={0};
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		t = a[i];
		x2 = 0;
		x1 = 0;
		for (; t != 0;) {
			x1 = t % 10;
			t = t / 10;
			x2 = x1 + x2;
		}
		b[i] = x2;
	}
	for (i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1 - i; j++) {
			if (b[j] < b[j+1]) {
				int w, m;
				w = b[j];
				b[j] = b[1 + j];
				b[1 + j] = w;
				m = a[j];
				a[j] = a[1 + j];
				a[1 + j] = m;
			}

			else {
				if (b[j] == b[1 + j] && a[j] > a[1 + j]) {
					int h，l;
					h=a[j];
					a[j] = a[1 + j];
					a[1 + j] = h;
                    l=b[j];
					b[j]=b[j+1];
					b[j+1]=t;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d %d\n", a[i], b[i]);
	return 0;
}