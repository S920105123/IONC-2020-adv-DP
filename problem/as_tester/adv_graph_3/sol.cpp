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

// SCC are indexed in topological order, (u, v) exist only for u < v.
int n, m, vis[MAXN], sid[MAXN], scc_sz[MAXN];
vector<int> stk, G[MAXN], Gr[MAXN];
void dfs(int v) {
	vis[v] = 1;
	for (int to : G[v]) {
		if (!vis[to]) {
			dfs(to);
		}
	}
	stk.push_back(v);
}
void rdfs(int v, int root) {
	sid[v] = root;
	for (int to : Gr[v]) {
		if (sid[to] == 0) {
			rdfs(to, root);
		}
	}
}
int find_SCC() {
	stk.clear();
	fill(vis, vis + n + 1, 0);
	fill(sid, sid + n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	
	int cnt = 0;
	for (int i = (int) stk.size() - 1; i >= 0; i--) {
		if (sid[stk[i]] == 0) {
			rdfs(stk[i], ++cnt);
		}
		scc_sz[sid[stk[i]]]++;
	}
	
	return cnt;
}

int dp[MAXN];
vector<int> Gc[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		Gr[v].push_back(u); 
	}
	
	int cnt = find_SCC();
	for (int i = 1; i <= n; i++) {
		for (int to : G[i]) {
			if (sid[i] != sid[to]) {
				Gc[sid[i]].push_back(sid[to]);
			}
		}
	}
	
	int ans = 0;
	for (int i = cnt; i >= 1; i--) {
		dp[i] = scc_sz[i];
		for (int to : Gc[i]) {
			dp[i] = max(dp[i], dp[to] + scc_sz[i]);
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << '\n';

	return 0;
} 
