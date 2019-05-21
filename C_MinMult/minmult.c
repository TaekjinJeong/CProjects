#include <stdio.h>
#include <malloc.h>

int minmult(int n, const int d[], int *P[]) {
	int i, j, k, diagonal, min_k = 0;
	int **M = (int**)malloc(sizeof(int) * n);
	//동적 할당
	for (i = 0; i < n; i++) {
		M[i] = (int*)malloc(sizeof(int) * n);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("M[%d][%d] = %d\n", i, j, M[i][j]);
		}
	}
	//대각선을 0으로 초기화
	for (i = 0; i < n; i++) {
		M[i][i] = 0;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("M[%d][%d] = %d\n", i, j, M[i][j]);
		}
	}
	for (diagonal = 1; diagonal < n; diagonal++) {
		for (i = 0; i < n - diagonal; i++) {
			j = i + diagonal;
			for (k = i; k < j; k++) {
				if (i == k) {
					M[i][j] = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
					min_k = k;
				}
				else if ((M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1]) < M[i][j]) {
					M[i][j] = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
					min_k = k;
				}
			}
			P[i][j] = min_k;
			printf("min_k = %d\n", min_k);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("M[%d][%d] = %d\n", i, j, M[i][j]);
		}
	}

	i = M[0][n - 1];
	free(M);
	return i;
}

void order(int i, int j, int *P[]) {
	int k;

	if (i == j)
		printf("A%d", i);
	else {
		k = P[i][j];
		printf("(");
		order(i, k, P);
		order(k + 1, j, P);
		printf(")");
	}
}

int main() {
	int *d, **P, num, min_mult, i, j;

	while (1) {
		//행렬의 개수 입력
		printf("행렬의 개수(-1입력시 종료) : ");
		scanf_s("%d", &num);
		if (num == -1)
			break;

		//d0 ~ dn 입력
		printf("d0 ~ d%d를 입력하시오.\n", num);
		d = (int*)malloc(sizeof(int)*num);
		for (i = 0; i <= num; i++) {
			printf("d%d : ", i);
			scanf_s("%d", &d[i]);
		}
		for (i = 0; i <= num; i++) {
			printf("d[%d] : %d\n", i, d[i]);
		}

		//최적 순서 출력을 위한 P행렬 초기화
		P = (int**)malloc(sizeof(int) * num);
		for (i = 0; i < num; i++)
			P[i] = (int*)malloc(sizeof(int)*num);
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				printf("P[%d][%d] = %d\n", i, j, P[i][j]);
			}
		}

		//연산 및 출력
		min_mult = minmult(num, d, P);
		for (i = 0; i < num; i++) {
			for (j = 0; j < num; j++) {
				printf("P[%d][%d] = %d\n", i, j, P[i][j]);
			}
		}
		printf("[최적 순서]\n");
		order(0, num - 1, P);
		printf("\nminimum = %d\n\n", min_mult);

		//메모리 해제
		free(P);
	}
}