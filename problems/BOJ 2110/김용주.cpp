//Baekjoon 2110 Odsn
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {

	int n, c;
	int x[200000];

	scanf("%d %d", &n, &c);	
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	//������ �Ÿ��� sorting
	sort(x, x + n);

	//left�� �ּҰŸ�, right�� �ִ뺸�� ū �Ұ����� �Ÿ��� ����.
	int left = 1, right = x[n - 1] + 1;
	int mid, cnt, start;
	int result;


	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 1;
		start = 0;

		for (int i = 0; i < n; i++) {
			// mid ������ ũ�ų� ���ƾ� �ִ�Ÿ��� ����.
			if (x[i] - x[start] >= mid) {
				start = i;
				cnt++;
			}				
		}

		// ������ ������ŭ ������ ������ �ִ�Ÿ��� �����ϸ� ��� Ȯ��. 
		// �׸��� �̰� �ִ��� mid�� ���� right�� ����. �ִ뺸�� ������ right���� ����.
		// right���� ũ�� ������ while���� ��������.
		if (cnt >= c) {
			result = mid;
			left = mid + 1;
		}
		// �����⸦ �� ������ = ������ �ִ�Ÿ��� �ʹ� �� = �ִ�Ÿ��� right���ٴ� �����
		else
			right = mid - 1;
	}

	printf("%d", result);

	return 0;
}