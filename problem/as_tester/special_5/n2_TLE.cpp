#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXN = 100005;
//const LL INF = (LL) 1e9 + 5;
//const LL MOD = (LL) 1e9 + 7;
using namespace std;

struct Tuple {
	int a, b, c;
	bool operator < (const Tuple &t) const {
		if (a != t.a) return a < t.a;
		if (b != t.b) return b < t.b;
		return c < t.c;
	}
};

int n, dp[MAXN];
Tuple T[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		T[i] = {a, b, c};
	}
	
	sort(T + 1, T + 1 + n);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (T[j] < T[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	cout << *max_element(dp + 1, dp + 1 + n) << '\n';

	return 0;
}
