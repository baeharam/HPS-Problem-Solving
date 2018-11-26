#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_N 100000

int T, N;
int stick[2][MAX_N], dp[MAX_N][3];

int sticker(int x, int state) {
	if (x == N) return 0;	//���� ����
	if (dp[x][state] != -1) return dp[x][state];	//���� ������ return

	int result = sticker(x + 1, 0);
	if (state != 1) result = max(result, sticker(x + 1, 1) + stick[0][x]);	//���� ���� sticker�� �ȶ��� ������ �Ѵ� �ȶ��������� ���� ���� ���� �������� �� �� ū ������ ����
	if (state != 2) result = max(result, sticker(x + 1, 2) + stick[1][x]);	//���� �Ʒ��� sticker�� �ȶ����� ������...

	dp[x][state] = result;

	return result;
}

int main(void) {
	scanf("%d", &T);

	for (int k = 0; k < T; k++) {
		scanf("%d", &N);
		for (int i = 0; i < 2; i++) 
			for (int j = 0; j < N; j++) 
				scanf("%d", &stick[i][j]);
		memset(dp, -1, sizeof(dp));

		printf("%d\n", sticker(0, 0));
	}

	return 0;
}