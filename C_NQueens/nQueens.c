#include <stdio.h>

int n, col[255], m = 1;

void queens(int i) {
	int j;

	if(promising(i))
		if (i == n) {
			for (j = 1; j <= n; j++) {
				if (j == 1)
					printf("%d번째 방법 : ", m++);
				printf("%d ", col[j]);
				if (j == n)
					printf("\n");
			}
			return;
		}
		else {
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}
}

int promising(int i) {
	int k = 1, promising = 1;

	while (k < i && promising) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
			promising = 0;
		k++;
	}

	return promising;
}

int main() {
	while (1) {
		printf("n?(-1은 종료) = ");
		scanf_s("%d", &n);
		if (n == -1)
			break;
		printf("@ n=%d 인 경우\n", n);
		m = 1;
		queens(0);
	}
}