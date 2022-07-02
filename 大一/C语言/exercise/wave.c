#include <stdio.h>

int main() {
	float S, A;
	scanf("%f", &S);
	if (S <= 3500)
		printf("%.0f", S);
	else {
		A = S - 3500;
		if (A <= 1500)
			printf("%.0f", S - A * 0.03);
		else if (A <= 4500)
			printf("%.0f", S - (A - 1500) * 0.1 - 45);
		else if (A <= 9000)
			printf("%.0f", S - (A - 4500) * 0.2 - 345);
		else if (A <= 35000)
			printf("%.0f", S - (A - 9000) * 0.25 - 1245);
		else
			printf("%.0f", S - (A - 35000) * 0.3 - 7745);
	}
	return 0;
}