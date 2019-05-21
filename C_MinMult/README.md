# 연쇄행렬 최소곱셈 알고리즘

Matrix Chain Multiplication

### 1. 문제정의

- 모든 행렬을 곱할 때에 최소한의 곱셈 횟수로 결과값에 도달하는 것

### 2. 변수

- M [x] [y] : x부터 y까지의 행렬을 곱할 때에 최소곱셈 연산 수
- P [x] [y] : x부터 y까지의 행렬을 곱할 때에 최소곱셈 연산을 위한 분기 위치
- d[n] : $\mathbf{d}_0$ ~ $\mathbf{d}_n$ 

### 3. 방법

- M[i] [j] = minimum( M[i] [k] + M[k+1] [j] + $\mathbf{d}_{i-1}$ $\mathbf{d}_{k}$$\mathbf{d}_{j}$ ( i <= k <= j-1 ))
- M[i] [j] = 0 ( if i == j )

- 모든 연쇄 행렬을 곱할 때 최소한의 곱셈 횟수로 결과값에 도달하기 위한 방법

  