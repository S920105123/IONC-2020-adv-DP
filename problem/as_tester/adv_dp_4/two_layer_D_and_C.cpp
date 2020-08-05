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

void solve2(int l, int r, int optl, int optr) {
	// dp[l ... r] consider the transitions from dp[optl ... optr], with D&C optimization.
	int mid = (l + r) / 2, best = -1;
	LL minv = INF;
	for (int i = optl; i <= optr; i++) {
		LL trans = get_cost(i, mid);
		if (trans < minv) {
			minv = trans;
			best = i;
		}
	}
	
	dp[mid] = min(dp[mid], minv);
	if (l < mid) solve2(l, mid - 1, optl, best);
	if (mid < r) solve2(mid + 1, r, best, optr);
}

void solve1(int l, int r) {
	if (l == r) {
		return;
	}
	
	int mid = (l + r) / 2;
	solve1(l, mid);
	solve2(mid + 1, r, l, mid);
	solve1(mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
		dp[i] = INF;
	}
	
	solve1(0, n);
	
	cout << dp[n] << '\n';

	return 0;
} 
