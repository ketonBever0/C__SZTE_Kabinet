#include <stdio.h>

float kamat(int szam) {
	return szam * 1.10;
}

int main() {
	printf("%f\n", kamat(32));
	return 0;
}
