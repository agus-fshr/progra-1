#include <stdio.h>

swap2(int, int);

int main() {
	int x = 5;
	int y = 10;

	printf("x: %d\ty: %d", x, y);
	swap2(&x, &y);
	printf("x: %d\ty: %d", x, y);
}

void swap2(int *pa, int *pb) {
	int t;
	t = *pa;
	*pa = *pb;
	*pb = t;
}
