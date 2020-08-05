#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const LL INF = (LL) 1e18 + 48763; 
const int MAXN = 100005;
using namespace std;

int n;
LL X[MAXN], Y[MAXN], P[MAXN], dp[MAXN];

LL get_cost(int l, int r) {
	// (l ... r]
	LL dx = P[r] - X[l + 1], dy = Y[l + 1];
	return dp[l] + dx * dx + dy * dy;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		dp[i] = get_cost(0, i);
		for (int j = max(1, i - 500); j < i; j++) {
			dp[i] = min(dp[i], get_cost(j, i));
		}
	}
	cout << dp[n] << '\n';

	return 0;
} 
