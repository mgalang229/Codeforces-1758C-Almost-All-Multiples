#include <bits/stdc++.h>
using namespace std;

/*

the sequence that will be shifted to the left:
x | a[1] | a[2] | ... | n

example:
3 | 6 | 12 and 2 | 4 | 12

2 | 4 | 8 | 12 is not possible because 8 does not divide 12

to get this sequence, prime factorize (n / x):

	12
   /  \
  2    6
      / \
     2   3

12 = 2 * 2 * 3

[2, 2, 3]
[2, 4, 3]
[2, 4, 12] <=

*/

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
