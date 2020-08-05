#include <bits/stdc++.h>
const int MAXN = 100005;
using namespace std;

struct Tuple {
	int a, b, c, id;
};

int n, dp[MAXN];
Tuple T[MAXN];

void solve(int l, int r) {
	if (l == r) {
//		cout << "At " << T[l].a << " " << dp[T[l].id] << '\n';
		return;
	}
	
	int mid = (l + r) / 2;
	solve(l, mid);
	
	vector<Tuple> vec1, vec2;
	for (int i = l; i <= mid; i++) {
		vec1.push_back(T[i]);
	}
	for (int i = mid + 1; i <= r; i++) {
		vec2.push_back(T[i]);
	}
	sort(vec1.begin(), vec1.end(), [&] (Tuple t1, Tuple t2) {
		return t1.b > t2.b;
	});
	sort(vec2.begin(), vec2.end(), [&] (Tuple t1, Tuple t2) {
		return t1.b < t2.b;
	});
	
	map<int, int> mque;
	for (Tuple t : vec2) {
		while (!vec1.empty() && vec1.back().b < t.b) {
			// Add vec1.back()
			Tuple add = vec1.back();
			vec1.pop_back();
			auto it = mque.upper_bound(add.c);
			if (it != mque.begin() && prev(it)->second >= dp[add.id]) {
				continue;
			}
			while (it != mque.end() && it->second <= dp[add.id]) {
				it = mque.erase(it);
			}
			mque[add.c] = dp[add.id];
		}
		auto it = mque.lower_bound(t.c);
		if (it != mque.begin()) {
			dp[t.id] = max(dp[t.id], prev(it)->second + 1);
		}
	}	
	solve(mid + 1, r);
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		T[i] = {a, b, c, i};
		dp[i] = 1;
	}
	
	sort(T + 1, T + 1 + n, [&] (Tuple t1, Tuple t2) {
		return t1.a < t2.a || (t1.a == t2.a && t1.b > t2.b);
	});
	solve(1, n);
	cout << *max_element(dp + 1, dp + 1 + n) << '\n';

	return 0;
}
