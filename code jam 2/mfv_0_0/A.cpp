#include <cstdio>
#include <vector>
#include <cassert>

void solveOne(int iTest) {
	int sizeI, sizeJ;
	scanf("%d %d", &sizeI, &sizeJ);
	std::vector<std::vector<char>> a(sizeI, std::vector<char>(sizeJ));
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			scanf(" %c", &a[i][j]);
			assert(a[i][j] == '?' || ('A' <= a[i][j] && a[i][j] <= 'Z'));
		}
	}
	for (int i = 1; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			if (a[i - 1][j] != '?' && a[i][j] == '?') {
				a[i][j] = a[i - 1][j];
			}
		}
	}
	for (int i = sizeI - 2; i >= 0; i--) {
		for (int j = 0; j < sizeJ; j++) {
			if (a[i + 1][j] != '?' && a[i][j] == '?') {
				a[i][j] = a[i + 1][j];
			}
		}
	}
	for (int j = 1; j < sizeJ; j++) {
		for (int i = 0; i < sizeI; i++) {
			if (a[i][j - 1] != '?' && a[i][j] == '?') {
				a[i][j] = a[i][j - 1];
			}
		}
	}
	for (int j = sizeJ - 2; j >= 0; j--) {
		for (int i = 0; i < sizeI; i++) {
			if (a[i][j + 1] != '?' && a[i][j] == '?') {
				a[i][j] = a[i][j + 1];
			}
		}
	}
	printf("Case #%d:\n", iTest);
	for (int i = 0; i < sizeI; i++) {
		for (int j = 0; j < sizeJ; j++) {
			assert(a[i][j] != '?');
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		solveOne(i);
	}
	return 0;
}
