#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define LL long long
#define PLL pair<LL, LL>
const int MAXN = 1000005;
const LL INF = (LL) 1e18 + 48763;
using namespace std;

int n, minv[MAXN], maxv[MAXN];
LL wei[MAXN];
map<LL, LL> dp_delta;

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
	
	map<LL, LL> dp_delta;
	for (int i = 0; i < n; i++) {
		dp_delta[minv[i]] += wei[i];
		
		LL rem = wei[i];
		auto it = dp_delta.upper_bound(maxv[i]);
		while (rem > 0 && it != dp_delta.end()) {
			if (rem >= it->second) {
				rem -= it->second;
				it = dp_delta.erase(it);
			}
			else {
				it->second -= rem;
				break;
			}
		}
	}
	
	LL ans = 0;
	for (auto d : dp_delta) {
		ans += d.second;
	}
	cout << ans << '\n';

	return 0;
}
