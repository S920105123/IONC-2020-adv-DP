#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXN = 1000005;
//const LL INF = (LL) 1e9 + 5;
//const LL MOD = (LL) 1e9 + 7;
using namespace std;

int n, ans, L[MAXN], R[MAXN], W[MAXN], A[MAXN], dp[MAXN];

void dfs(int id) {
	if (id > n) {
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] <= A[i]) {
					dp[i] = max(dp[i], dp[j] + W[i]);
				}
			}
			ans = max(ans, dp[i]);
		}
		return;
	}
	
	for (A[id] = L[id]; A[id] <= R[id]; A[id]++) {
		dfs(id + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> L[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> R[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> W[i];
	}
	
	dfs(1);
	
	cout << ans << '\n';
 
	return 0;
} 
