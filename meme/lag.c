#include <stdio.h>

int main() {
	unsigned long long int i = 0;
	int res = 1;
	while(i<1000000000000000) {
		++i;
		--i;
		++i;
	}
	res++;
	printf("%d \n", res);
	return res;
}
