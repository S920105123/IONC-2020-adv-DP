#include <bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define fi first
#define se second
const int MAXN = 2000005;
using namespace std;

LL n, k, P[MAXN];
list<LL> L;
map<pair<LL, LL*>, list<LL>::iterator> Q;

list<LL>::iterator remove(list<LL>::iterator it) {
	auto tmp = Q.find(make_pair(max(*it, -*it), &*it));
//	cout << "Find " << *it << ' ' << &*it << '\n';
	assert(tmp != Q.end());
	Q.erase(tmp);
	return L.erase(it);
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> P[i];
	}
	
	int lptr = 0, take = 0;
	LL cur = 0;
	while (lptr < n) {
		int rptr = lptr, sign = (P[lptr] >= 0);
		LL sum = 0;
		while (rptr < n && (P[rptr] >= 0) == sign) {
			sum += P[rptr];
			rptr++;
		}
		if (sign) {
			take++;
			cur += sum;
		}
		
		if ((lptr == 0 && sum < 0) || (rptr == n && sum < 0)) {
			lptr = rptr;
			continue;
		}
		L.push_back(sum);
		Q[make_pair(max(sum, -sum), &*(--L.end()))] = --L.end();
//		cout << "Push " << sum << ' ' << &*(--L.end()) << '\n';
		lptr = rptr;
	}
	
	while (take > k) {
		LL price = Q.begin()->first.first;
		auto it = Q.begin()->second;
//		cout << "Take " << price << ' ' << *Q.begin()->second << endl;
		cur -= price;
		take--;
		
		LL sum = 0;
//		cout << "Begin " << Q.begin()->first.first << " and " << Q.begin()->first.second << '\n';
		if (it != L.begin()) {
			sum += *prev(it);
			remove(prev(it));			
		}
		if (next(it) != L.end()) {
			sum += *next(it);
			remove(next(it));
		}
		sum += *it;
		it = remove(it);
		
		if (it == L.begin() && sum < 0) {
			continue;
		}
		if (it == L.end() && sum < 0) {
			continue;
		}
		it = L.insert(it, sum);
		Q[make_pair(max(sum, -sum), &*it)] = it;
	}
	
	cout << cur << '\n';
}
