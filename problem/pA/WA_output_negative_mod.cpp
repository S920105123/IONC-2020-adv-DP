#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXQ = 505;
const int MAXV = 505;
const LL MOD = (LL) 1e9 + 7;
using namespace std;

// O(QQV)
LL n, qn, sum;
LL dp[MAXQ * MAXV], occ[MAXQ * MAXV];

void put_in(int wei) {
	for (int j = sum; j >= wei; j--) {
		dp[j] = (dp[j] + dp[j - wei]) % MOD;
	}
}

void take_out(int wei) {
	for (int j = wei; j <= sum; j++) {
		dp[j] = (dp[j] - dp[j - wei]) % MOD;
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
	vector<PII> event;
	cin >> n >> qn;
	for (int i = 0; i < qn; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		sum += v;
		event.push_back(PII(l, v));
		event.push_back(PII(r + 1, ~v));
	}
	event.push_back(PII(1, 0));
	event.push_back(PII(n + 1, ~0));
	
	dp[0] = 1;
	for (int i = 1; i <= sum; i++) {
		dp[i] = 0;
	}
	
	int cover = 0;
	sort(event.begin(), event.end());
	for (int i = 0; i < (int) event.size() - 1; i++) {
		PII ev = event[i];
		if (ev.se < 0) {
			ev.se = ~ev.se;
			if (ev.se != 0) {
				cover--;
				take_out(ev.se);
			}
		}
		else {
			if (ev.se != 0) {
				cover++;
				put_in(ev.se);
			}
		}
		
		if (event[i].fi != event[i + 1].fi) {
			LL len = event[i + 1].fi - event[i].fi, mul = len * qpow(2, qn - cover) % MOD;
			for (int j = 0; j <= sum; j++) {
				occ[j] = (occ[j] + dp[j] * mul) % MOD;
			}
		}
	}
	
	for (int i = 0; i <= sum; i++) {
		cout << occ[i] << " \n"[i == sum];
	}

	return 0;
} 
