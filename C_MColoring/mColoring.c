#include <stdio.h>
#include <malloc.h>

int n, m, x, flag, **W, *vcolor;

void m_coloring(int i) {
	int col, j;

	if (i == n && validation()) {
		if(!flag)
			printf("@ minimum m : %d개\n", m);
		for (j = 0; j < n; j++) {
			if (j == 0)
				printf("%d번째 방법 : ", x++);
			printf("%d ", vcolor[j]);
			if (j == n - 1)
				printf("\n");
		}
		flag = 1;
	}
	else {
		for (col = 1; col <= m; col++) {
			if (promising(i, col)) {
				vcolor[i] = col;
				m_coloring(i + 1);
				vcolor[i] = 0;
			}
		}
	}
}

int promising(int i, int col) {
	int j;

	for (j = 0; j < n; j++) {
		if (W[i][j] && col == vcolor[j])
			return 0;
	}

	return 1;
}

int validation() {
	int i, j;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (W[i][j] && vcolor[i] == vcolor[j])
				return 0;
		}
	}

	return 1;
}

int main() {
	int i, j;
	while (1) {
		printf("@ input size : ");
		scanf_s("%d", &n);
		
		//vcolor 동적 할당
		vcolor = (int*)malloc(sizeof(int) * n);
		for (i = 0; i < n; i++) 
			vcolor[i] =  0;

		//W 동적 할당
		W = (int**)malloc(sizeof(int) * n);
		for (i = 0; i < n; i++)
			W[i] = (int*)malloc(sizeof(int) * n);

		for (i = 0; i < n; i++) {
			printf("@ %d번째 row : ", i + 1);
			for (j = 0; j < n; j++)
				scanf_s("%d", &W[i][j]);
		}

		x = 1;
		m = 2;
		flag = 0;
		while (!flag) {
			m_coloring(0);
			m++;
		}
		printf("@ 총 가짓수 : %d개\n", x-1);
	}
}