#include <bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
const int MAXN = 1000005;
const LL INF = (LL) 1e18 + 48763;
using namespace std;

int n, minv[MAXN], maxv[MAXN];
LL wei[MAXN];

LL greedy_from(int id) {
	LL cur = 0, res = 0;
	for (int i = id; i < n; i++) {
		if (cur <= maxv[i]) {
			cur = max(cur, (LL) minv[i]);
			res += wei[i];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> minv[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> maxv[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> wei[i];
	}
	
	mt19937 rng(time(NULL));
	LL ans = 0;
	for (int i = 0; i < 50; i++) {
		ans = max(ans, greedy_from(rng() % n));
	}
	for (int i = 0; i < min(n, 50); i++) {
		ans = max(ans, greedy_from(i));
	}
	
	cout << ans << '\n';

	return 0;
}
