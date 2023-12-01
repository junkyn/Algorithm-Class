#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int Edge[1000][1000][2]; // 1: Parent 2:Tree, 3: Back
int Mark[1000];
int Pre[1000];
int L[1000];
int P;

int n, m;

void dfs(int x, int p) {
	int i, j;
	Mark[x] = 1; Pre[x] = P; P++;
	for (i = 1; i <= n; i++) {
		//Edge[x][i]
		if (i == p) {
			Edge[x][i][1] = 1;
		}
		else if (Edge[x][i][0] == 1) {
			if (Mark[i] == 0) {
				Edge[x][i][1] = 2;
				dfs(i, x);
			}
			else {
				Edge[x][i][1] = 3;
			}
		}
	}
}

void dfs2(int x) {
	int i,myL;
	myL = Pre[x];
	for (i = 1; i <= n; i++) {
		if (Edge[x][i][1] == 2) {
			dfs2(i);
			myL = min(myL, L[i]);
		}
		else if (Edge[x][i][1] == 3) {
			myL = min(myL, Pre[i]);
		}
	}
	L[x] = myL;
}
int isCut(int x) {
	int i, ret;
	ret = 0;
	for (i = 1; i <= n; i++) {
		if (Edge[x][i][1] == 2) {
			if (L[i] >= Pre[x])
				ret = 1;
		}
	}
	return ret;
}

int isRootCut(int x) {
	int i, cnt;
	cnt = 0;
	for (i = 1; i <= n; i++) {
		if (Edge[x][i][1] == 2) {
			if (L[i] >= Pre[x])
				cnt++;
		}
	}
	if (cnt > 1)return 1;
	else return 0;
}
int main() {
	int i,j,x,y;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		Edge[x][y][0] = 1;
		Edge[y][x][0] = 1;
	}
	P = 1; 
	dfs(1, 0);
	dfs2(1);
	if (isRootCut(1) == 1)
		printf("%d ", 1);
	for (i = 2; i <= n; i++) {
		if (isCut(i) == 1) {
			printf("%d ",i);
		}
	}

	printf("\n");
	return 0;
}

/*
5 4
3 2
2 1
1 4
4 5

5 5
3 2
2 1
1 4
4 5
1 3

16 20
1 2
1 3
2 4
3 4
4 5
5 6
4 6
5 7
7 8
4 12
12 13
4 11
11 13
11 10
10 9
9 11
13 14
14 15
15 16
14 16
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", Edge[i][j][0]);
		}
		printf("\n");
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", Edge[i][j][1]);
		}
		printf("\n");
	}
*/