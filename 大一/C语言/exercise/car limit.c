#include <stdio.h>
 
int main() 
{
	int t, p, x, a;
	scanf("%d %d %d", &t, &p, &x);
	a = x % 10;
	if (p < 200 || t == 6 || t == 7)
		printf("%d no", a);
	else if (p >= 200 && p < 400) 
	{
		if (t == 1 && (a == 1 || a == 6))
			printf("%d yes", a);
		else if (t == 2 && (a == 2 || a == 7))
			printf("%d yes", a);
		else if (t == 3 && (a == 3 || a == 8))
			printf("%d yes", a);
		else if (t == 4 && (a == 4 || a == 9))
			printf("%d yes", a);
		else if (t == 5 && (a == 5 || a == 0))
			printf("%d yes", a);
		else
			printf("%d no", a);
 
	}
 
	else if (p >= 400) 
	{
		if ((t == 1 || t == 3 || t == 5) && (a == 1 || a == 3 || a == 5 || a == 7 || a == 9))
			printf("%d yes", a);
		else if ((t == 2 || t == 4) && (a == 0 || a == 2 || a == 4 || a == 6 || a == 8))
			printf("%d yes", a);
		else
			printf("%d no", a);
	} 
	else
		printf("%d no", a);
	return 0;
}