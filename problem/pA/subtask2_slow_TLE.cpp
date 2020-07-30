#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXQ = 505;
const int MAXN = 505;
const int MAXV = 505;
const LL MOD = (LL) 1e9 + 7;
using namespace std;

// O(QQQV)
LL n, qn, sum;
vector<int> keep[MAXN];
LL dp[MAXQ * MAXV], occ[MAXQ * MAXV];

void do_knapsack(vector<int> &item) {
	dp[0] = 1;
	for (int i = 1; i <= sum; i++) {
		dp[i] = 0;
	}
	for (int i = 0; i < item.size(); i++) {
		for (int j = sum; j >= item[i]; j--) {
			dp[j] = (dp[j] + dp[j - item[i]]) % MOD;
		}
	}
}

LL qpow(LL a, LL pw) {
	LL res = 1;
	while (pw) {
		if (pw & 1) {
			res = res * a % MOD;
		}
		pw >>= 1;
		a = a * a % MOD;
	}
	return res;
}

int main() {
	cin >> n >> qn;
	for (int i = 0; i < qn; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		sum += v;
		for (int j = l; j <= r; j++) {
			keep[j].push_back(v);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		do_knapsack(keep[i]);
		for (int j = 0; j <= sum; j++) {
			occ[j] = (occ[j] + dp[j] * qpow(2, qn - keep[i].size())) % MOD;
		}
	}
	
	for (int i = 0; i <= sum; i++) {
		cout << occ[i] << " \n"[i == sum];
	}

	return 0;
} 
