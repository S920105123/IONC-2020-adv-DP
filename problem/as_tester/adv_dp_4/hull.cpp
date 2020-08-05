#include <bits/stdc++.h>
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define fi first
#define se second
const LL INF = (LL) 1e18 + 48763; 
const int MAXN = 100005;
using namespace std;

const LL is_query = -(1LL<<62);
struct Line {
	LL m, b;
	mutable function<const Line*()> succ;
	bool operator<(const Line& rhs) const {
	    if (rhs.b != is_query) return m < rhs.m;
	    const Line* s = succ();
	    if (!s) return 0;
	    LL x = rhs.m;
	    return b - s->b < (s->m - m) * x;
	}
};
// Upper envelope, erase cannot be done.
// Even if you do erase, the popped lines are gone, it won't be a correct hull.
struct HullDynamic : public multiset<Line> { 
	bool bad(iterator y) {
	    auto z = next(y);
	    if (y == begin()) {
	        if (z == end()) return 0;
	        return y->m == z->m && y->b <= z->b;
	    }
	    auto x = prev(y);
	    if (z == end()) return y->m == x->m && y->b <= x->b;
	    return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m - x->m);
	}
	void insert_line(LL m, LL b) {
	    auto y = insert({ m, b });
	    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
	    if (bad(y)) { erase(y); return; }
	    while (next(y) != end() && bad(next(y))) erase(next(y));
	    while (y != begin() && bad(prev(y))) erase(prev(y));
	}
	LL eval(LL x) {
	    auto l = *lower_bound((Line) { x, is_query });
	    return l.m * x + l.b;
	}
} hull;

int n;
LL X[MAXN], Y[MAXN], P[MAXN], dp[MAXN];

LL get_slope(int j) {
	return 2 * X[j + 1];
}

LL get_intercept(int j) {
	return -(dp[j] + X[j + 1] * X[j + 1] + Y[j + 1] * Y[j + 1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> X[i] >> Y[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> P[i];
	}
	
	hull.insert_line(get_slope(0), get_intercept(0));
	for (int i = 1; i <= n; i++) {
		dp[i] = -hull.eval(P[i]) + P[i] * P[i];
		if (i != n) {
			hull.insert_line(get_slope(i), get_intercept(i));
		}
	}
	
	cout << dp[n] << '\n';

	return 0;
} 
