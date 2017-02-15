#include <stdlib.h>
#include <stdio.h>

int main() {
	int N;

	scanf("%d", &N);
	while (N != 0) {
		printf("%d\n", N*(N+1)*(2*N+1)/6);

		scanf("%d", &N);
	}

	return 0;
}
