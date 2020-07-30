#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXQ = 505;
const int MAXN = 505;
const int MAXV = 505;
using namespace std;

// O(QN * 2^Q)

struct Query {
	int l, r, v;
};

int n, qn, sum, a[MAXN], occ[MAXQ * MAXV];
Query qs[MAXQ];

void simulate(int outcome) {
	memset(a, 0, sizeof(a));
	for (int i = 0; i < qn; i++) {
		if (outcome >> i & 1) {
			for (int j = qs[i].l; j <= qs[i].r; j++) {
				a[j] += qs[i].v;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		occ[a[i]]++;
	}
}

int main() {
	cin >> n >> qn;
	for (int i = 0; i < qn; i++) {
		int l, r, v;
		cin >> l >> r >> v;
		sum += v;
		qs[i] = {l, r, v};
	}
	
	for (int i = 0; i < (1 << qn); i++) {
		simulate(i);
	}
	
	for (int i = 0; i <= sum; i++) {
		cout << occ[i] << " \n"[i == sum];
	}

	return 0;
} 
