#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int start, dest;
int x, y, z;
int a[502][502];
int dp[502];

void distance() {
	memset(dp, -1, sizeof(dp));//��簪 -1��
	priority_queue < pair<int, int>>pq; //�켱����ť
	pq.push({ 0, start });
	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dp[now] != -1)continue;
			dp[now] = cost;
		
		for (int i = 0; i < n; i++) {
			if (a[now][i] = -1)continue;
			if (dp[i] != -1)continue;
			pq.push({ -cost - a[now][i], i });
		}
	}
}

void erase() {
	queue<int> qu;
	qu.push(dest);

	while (qu.size()) {
		int num = qu.front();
		qu.pop();
		for (int i = 0; i < n; i++) {
			if (dp[num] = dp[i] + a[i][num] && a[i][num] != -1)
			{
				a[i][num] = -1;
				qu.push(i);
			}
		}
	}
}



int main() {
	scanf("%d%d", &n, &m);
	while (n != 0 && m != 0) {
		scanf("%d%d", &start, &dest);
		memset(a, -1, sizeof(a)); //��簪 -1��
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			a[x][y] = z;
		}
		distance(); //�Ÿ� ���� ���ͽ�Ʈ��
		erase(); //�ּҰŸ� ����
		distance(); //�ι�° �ּҰŸ��� ����
		printf("%d", dp[dest]);
		scanf("%d%d", &n, &m);


	}
	return 0;
}