#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n, x;
	cin >> n >> x;
	if (n % x) {
		cout << "-1\n";
		return;
	}
	vector<int> ans(n + 1);
	iota(ans.begin(), ans.end(), 0);
	ans[n] = 1;
	ans[1] = x;
	while (x < n) {
		for (int i = x * 2; i <= n; i += x) {
			if (n % i == 0) {
				ans[x] = i;
				x = i;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
