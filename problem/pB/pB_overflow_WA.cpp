#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
const int MAXN = 1000005;
using namespace std;

int n, minv[MAXN], maxv[MAXN];
int wei[MAXN];
map<int, int> dp_delta;

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
	
	map<int, int> dp_delta;
	for (int i = 0; i < n; i++) {
		dp_delta[minv[i]] += wei[i];
		
		int rem = wei[i];
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
	
	int ans = 0;
	for (auto d : dp_delta) {
		ans += d.second;
	}
	cout << ans << '\n';

	return 0;
}
