#include <stdio.h>

int main(void) {
	int T;
	if (scanf("%d", &T) != 1) return 0;
	while (T--) {
		int L;
		if (scanf("%d", &L) != 1) break;
		int a[55];
		for (int i = 0; i < L; ++i) scanf("%d", &a[i]);
		int swaps = 0;
		for (int i = 0; i < L; ++i) {
			for (int j = i + 1; j < L; ++j) {
				if (a[i] > a[j]) ++swaps;
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", swaps);
	}
	return 0;
}

